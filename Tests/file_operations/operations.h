#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>

 
#if _WIN32 || _WIN64
#include <windows.h>
#elif defined(__unix__) || defined (__unix)
#include <unistd.h>
#endif

int create_file(char* filename);
int read_file(char* filename);

#endif // OPERATIONS_H
