#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t childPid = fork();

  if (childPid < 0) {
    perror("Fork Failed to Run");
    return -1;
  }
  if (childPid == 0) {
    printf("The PID is: %d and the PPID is: %d\n", getpid(), getppid());
  } else {

    printf("The Parent Process....\n");
    printf("The Parent PID: %d\n ", getpid());
    printf("The Child PID: %d\n", childPid);
  }
  return 0;
}
