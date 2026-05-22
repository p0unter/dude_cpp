#include "operations.h"

FILE* fptr;

int read_file(char* filename) {
  fptr = fopen(filename, "r");

  char data[256];

  if (fptr != NULL) {
    printf("File is begin...");

    while (fgets(data, 256, fptr) != NULL) {
      printf("%s", data);
    }

    fclose(fptr);

    return 1;
  }

  return 0;
}

int create_file(char* filename) {
  fptr = fopen(filename, "w");

  if (fptr != NULL) {
    return 1;
  }
  return 0;
}
