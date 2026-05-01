#include "./utils.h"

int screenWidth = 800;
int screenHeight = 450;
int num_processes = 0;

const char* processText[] = {
  "TRYCATCH NETWORK OFFICIAL WEB SITE",
  "CHICIHI",
  "EMOTIONAL DAMAGE",
  "BING CHILLING"
};

Font fontDunkerque;

Sound memeSounds[3];

void InitUtils(void) {
  num_processes = sizeof(processText) / sizeof(processText[0]); 

  memeSounds[0] = LoadSound("./memes/meme1.mp3");
  memeSounds[1] = LoadSound("./memes/meme2.mp3");
  memeSounds[2] = LoadSound("./memes/meme3.mp3");
  fontDunkerque = LoadFont("./Dunkerque.otf");
}
