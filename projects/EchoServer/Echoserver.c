#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 8080

/* Our ring buffer struct */
struct ring_buffer {
  uint8_t *buffer;
  size_t size;
  size_t head;
  size_t tail;
  int is_full;
};

/* All the ring buffer functions we built */
void rb_init(struct ring_buffer *rb, size_t size) {
  rb->buffer = malloc(size);
  rb->size = size;
  rb->head = 0;
  rb->tail = 0;
  rb->is_full = 0;
}

void rb_free(struct ring_buffer *rb) { free(rb->buffer); }

int rb_write(struct ring_buffer *rb, uint8_t data) {
  if (rb->is_full)
    return 0;
  rb->buffer[rb->head] = data;
  rb->head = (rb->head + 1) % rb->size;
  if (rb->head == rb->tail)
    rb->is_full = 1;
  return 1;
}

int rb_read(struct ring_buffer *rb, uint8_t *data) {
  if (!rb->is_full && rb->head == rb->tail)
    return 0;
  *data = rb->buffer[rb->tail];
  rb->tail = (rb->tail + 1) % rb->size;
  rb->is_full = 0;
  return 1;
}

size_t rb_available(struct ring_buffer *rb) {
  if (rb->is_full)
    return rb->size;
  if (rb->head >= rb->tail)
    return rb->head - rb->tail;
  return rb->size - rb->tail + rb->head;
}

size_t rb_free_space(struct ring_buffer *rb) {
  if (rb->is_full)
    return 0;
  return rb->size - rb_available(rb);
}

/* Write multiple bytes to ring buffer */
size_t rb_write_bytes(struct ring_buffer *rb, uint8_t *data, size_t len) {
  size_t written = 0;
  while (written < len && rb_write(rb, data[written])) {
    written++;
  }
  return written;
}

/* Read multiple bytes from ring buffer */
size_t rb_read_bytes(struct ring_buffer *rb, uint8_t *data, size_t max_len) {
  size_t read_count = 0;
  uint8_t byte;
  while (read_count < max_len && rb_read(rb, &byte)) {
    data[read_count++] = byte;
  }
  return read_count;
}

/* Each connection gets its own ring buffer */
struct connection {
  int fd;
  struct ring_buffer rx_buffer; // Data from client
  struct ring_buffer tx_buffer; // Data to send to client
};

int main() {
  int server_fd, client_fd;
  struct sockaddr_in address;
  int opt = 1;
  socklen_t addrlen = sizeof(address);

  /* Create socket */
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, 3);

  printf("Echo server on port %d\n", PORT);

  while (1) {
    client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    printf("Client connected\n");

    /* Create connection with ring buffers */
    struct connection conn;
    conn.fd = client_fd;
    rb_init(&conn.rx_buffer, BUFFER_SIZE);
    rb_init(&conn.tx_buffer, BUFFER_SIZE);

    /* Handle this client */
    uint8_t temp[1024];
    ssize_t n;

    while (1) {
      /* Read from socket into temp, then into ring buffer */
      n = read(client_fd, temp, sizeof(temp));
      if (n <= 0)
        break; // Client closed or error

      /* Write received data to both rx_buffer (if needed) and tx_buffer (to
       * echo) */
      rb_write_bytes(&conn.tx_buffer, temp, n);

      /* Now write from tx_buffer back to socket */
      size_t to_send = rb_available(&conn.tx_buffer);
      if (to_send > 0) {
        uint8_t send_buf[1024];
        size_t read_size = rb_read_bytes(
            &conn.tx_buffer, send_buf,
            to_send > sizeof(send_buf) ? sizeof(send_buf) : to_send);
        write(client_fd, send_buf, read_size);
      }
    }

    printf("Client disconnected\n");
    rb_free(&conn.rx_buffer);
    rb_free(&conn.tx_buffer);
    close(client_fd);
  }

  close(server_fd);
  return 0;
}
