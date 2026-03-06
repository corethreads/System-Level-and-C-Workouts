#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void find_files(char *path, char *extension, int depth) {
  DIR *dir;
  struct dirent *entry;
  struct stat file_stat;
  char full_path[1024];

  // Try to open the directory
  dir = opendir(path);
  if (!dir) {
    printf("Cannot open %s\n", path);
    return;
  }

  // Indent based on depth (so you can see the structure)
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("📁 %s\n", path);

  // Read all entries in this directory
  while ((entry = readdir(dir)) != NULL) {
    // Skip . and ..
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Build full path
    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

    // Get file info
    if (stat(full_path, &file_stat) == -1) {
      continue;
    }

    // Check if it's a directory
    if (S_ISDIR(file_stat.st_mode)) {
      // RECURSIVE CASE: It's a directory, search inside it!
      find_files(full_path, extension, depth + 1);
    } else {
      // Base case: It's a file, check if it matches our extension
      char *dot = strrchr(entry->d_name, '.');
      if (dot && strcmp(dot, extension) == 0) {
        // Found a matching file!
        for (int i = 0; i < depth + 1; i++) {
          printf("  ");
        }
        printf("📄 %s\n", entry->d_name);
      }
    }
  }

  closedir(dir);
}

int main() {
  printf("Searching for all .txt files:\n");
  printf("============================\n");
  find_files(".", ".txt", 0); // Search current directory for .txt files

  printf("\nSearching for all .c files:\n");
  printf("============================\n");
  find_files(".", ".c", 0); // Search current directory for .c files

  return 0;
}
