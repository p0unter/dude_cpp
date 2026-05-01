#ifndef UTILS_H
#define UTILS_H

#include "include/raylib.h"

extern int num_processes;

extern int screenWidth;
extern int screenHeight;
extern const char* processText[];
extern Sound memeSounds[3];
extern Font fontDunkerque;

void InitUtils(void);

#endif // !UTILS_H

