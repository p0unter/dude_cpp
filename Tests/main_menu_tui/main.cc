#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "\033[H\033[2J"
#define usleep_ms(ms) usleep((ms)*1000)
#endif

bool selected[4] = {false};
int counter = 0;

void enable_raw_mode();
void disable_raw_mode();
int kbhit();

std::string getCharacter(char character, int size);
void focusSelected(int item);
void focusSelected(int item, int isOne);

int main() {
  #ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  #endif

  printf(CLEAR_SCREEN);
  fflush(stdout);
  
  #ifndef _WIN32
  enable_raw_mode();
  #endif
  
  selected[0] = true;
  while (true) {
      if (kbhit()) {
          char ch = getchar();
          
          if (ch == 's' || ch == 'S') {
              selected[counter] = false;
              counter = (counter + 1) % 4;
              selected[counter] = true;
          } else if (ch == 'w' || ch == 'W') {
              selected[counter] = false;
              counter = (counter + 3) % 4;
              selected[counter] = true;
          } else if (ch == 'q' || ch == 'Q') {
              break;
          }
      }
      
      printf(CLEAR_SCREEN);
      focusSelected(0, 1);
      printf("%s Option 1\n", selected[0] ? "●" : " ");
      focusSelected(0);
      focusSelected(1);
      printf("%s Option 2\n", selected[1] ? "●" : " ");
      focusSelected(1);
      focusSelected(2);
      printf("%s Option 3\n", selected[2] ? "●" : " ");
      focusSelected(2);
      focusSelected(3);
      printf("%s Option 4\n", selected[3] ? "●" : " ");
      focusSelected(3);
      printf("W/S to navigate, Q to quit\n");
      fflush(stdout);
      
      usleep_ms(100);
  }
  
  #ifndef _WIN32
  disable_raw_mode();
  #endif
  printf("\nGoodbye!\n");
  return 0;
}

void focusSelected(int item) {
  printf("%s\n", selected[item] ? std::string(13, '-').c_str() : "");
}
void focusSelected(int item, int isOne) {
  if (isOne) {
    printf("%s%s\n", std::string(15, '\n').c_str(), selected[item] ? std::string(13, '-').c_str() : "");
  }
}

#ifndef _WIN32
void enable_raw_mode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag |= (ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int kbhit() {
  struct timeval tv = {0, 0};
  fd_set rdfs;
  FD_ZERO(&rdfs);
  FD_SET(STDIN_FILENO, &rdfs);
  select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
}
#endif

#ifdef _WIN32
int kbhit() { return _kbhit(); }
#define usleep_ms(ms) Sleep(ms)
#endif
