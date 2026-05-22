#include "operations.h"

#define OPERATIONS 3

void clearTerminal(int cls_stat);
void loadingAnim();

int main(int argc, char** argv) {
  if (argc > 1) {
    if (strcmp(argv[1], "arg") == 0) {
      printf("arg\n");
    }
  }

  int clear_status = 1;
  while (1) {
    clearTerminal(clear_status);
    if (clear_status) {
      printf("[1] Read file content (fgets(data, 50, fptr))\n");
      printf("[2] Create file (fopen('file.txt', 'mode'))\n");
      printf("[3] Quit\n");
    }
    clear_status = 0;
    
    int choice;
    printf("\nSelect: ");
    int n = scanf("%d", &choice);

    if (n != 1) {
      fprintf(stderr, "Please enter a number!\n");
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
      continue;
    }

    if (choice < 1 || choice > OPERATIONS) continue;

    printf("Selected: %d\n\n", choice);

    switch (choice) {
      case 1:
        printf("File path (Go select menu [exit]): ");
        char file_path[256] = { 0 };
        scanf("%255s", file_path);
        if (strcmp(file_path, "exit") == 0) {
          printf("Returning select menu");
          loadingAnim();
          clear_status = 1;
          clearTerminal(clear_status);
        } else {
          printf("\n-------File read is begin!-------\n\n");
          if (read_file(file_path)) {
            printf("\n-------File read is successfully!-------\n");
            sleep(3);
            //clear_status = 1;
          }
          else
            printf("\n[ERR] Error occurred wihle file read procces.\n");
        }
        break;
      case 2:
        printf("File name (Go select menu [exit]): ");
        char file_name[256] = { 0 };
        scanf("%255s", file_name);
        if (strcmp(file_name, "exit") == 0) {
          printf("Returning select menu");
          loadingAnim();
          clear_status = 1;
          clearTerminal(clear_status);
        }
        else {
          if(create_file(file_name)) {
            printf("File creation is successfully!\n");
            sleep(1);
            
            //clear_status = 1;
          }
          else
            printf("Error occurred while file creation procces.\n");
        }
        break;
      case 3:
        clearTerminal(1);
        printf("Exiting");
        loadingAnim();
        exit(1);
        break;
    }
  }
  
  return 0;
}

void clearTerminal(int cls_stat) {
  if (cls_stat) {
    #if _WIN32 || _WIN64
      //system("cls");
      printf("\e[1;1H\e[2J");
    #elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH))
      //system("clear");
      printf("\e[1;1H\e[2J");
    #endif
  }
}


void loadingAnim() {
  fflush(stdout);
  char dot_side[3];
  for (int i = 0; i < 3; i++) {
    usleep(500000);
    printf(".");
    fflush(stdout);           
  }
  printf("\n");
}
