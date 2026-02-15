#include <stdio.h>
#include <string.h>

int main(void) {
  /*
  *******************************************************************
  *QUEUE job analyzer takes one thing processes and passes to next..*
  *******************************************************************
  */

  char tasks[10][50];
  int taskcount = 0;
  int choice;

  do {
    printf("\n1. Add Task\n");
    printf("2. Process Next Task\n");
    printf("3. Show All Tasks\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      if (taskcount < 10) {
        printf("Enter Task: ");
        scanf("%s", tasks[taskcount]);
        taskcount++;
        printf("Task added Successfully");
      } else {
        printf("Task storage Full!");
      }
    }

    if (choice == 2) {
      printf("Processing task: %s\n", tasks[0]);
      for (int i = 0; i < taskcount - 1; i++) {
        // Destination and Source function
        strcpy(tasks[i], tasks[i + 1]);
      }
      taskcount--;
    }

    if (choice == 3) {
      printf("====== TASK QUEUE =====\n");
      if (taskcount > 0) {
        for (int j = 0; j < taskcount; j++)
          printf("%d --> %s", j + 1, tasks[j]);
      } else {
        printf("Queue is emtpy..");
      }
    }

    printf("This are the task 1, %s", tasks[0]);

  } while (choice != 4);
}
