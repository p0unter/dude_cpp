#include "./utils.h"

int nowPlaying = -1;
int mouseHoverRec = -1, mouseActiveRec = -1, mouseActiveCounter = 0;

void handleClick(int i) {
  if (i == 0) { OpenURL("https://trycatch.network"); return; }

  int idx = i - 1;
  if (nowPlaying == i) {
    StopSound(memeSounds[idx]);
    nowPlaying = -1;
  } else {
    if (nowPlaying > 0) StopSound(memeSounds[nowPlaying - 1]);
    PlaySound(memeSounds[idx]);
    nowPlaying = i;
  }
}

void drawButton(Rectangle rec, int i) {
  int active = (i == mouseActiveRec), hover = (i == mouseHoverRec);
  const char* label = (i > 0 && nowPlaying == i) ? "STOP AUDIO" : processText[i];

  DrawRectangleRec(rec, active ? GRAY : hover ? SKYBLUE : LIGHTGRAY);
  DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, hover ? BLUE : GRAY);
  DrawTextEx(fontDunkerque, label,
    (Vector2){ rec.x + rec.width/2 - MeasureTextEx(fontDunkerque, label, 15, 2).x/2, rec.y + 9 },
    15.0f, 2.0f, active ? DARKGRAY : hover ? DARKBLUE : DARKGRAY);
}

int main(void) {
  InitWindow(screenWidth, screenHeight, "TryCatch Network");
  InitAudioDevice();
  InitUtils();

  Rectangle toggleRecs[num_processes];
  for (int i = 0; i < num_processes; i++)
    toggleRecs[i] = (Rectangle){ 40.0f, (float)(50 + 50*i), 450.0f, 30.0f };

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (mouseActiveCounter > 0 && ++mouseActiveCounter >= 7) {
      mouseActiveCounter = 0;
      mouseActiveRec = -1;
    }

    if (nowPlaying > 0 && !IsSoundPlaying(memeSounds[nowPlaying - 1]))
      nowPlaying = -1;

    mouseHoverRec = -1;
    for (int i = 0; i < num_processes; i++) {
      if (CheckCollisionPointRec(GetMousePosition(), toggleRecs[i])) {
        mouseHoverRec = i;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
          mouseActiveRec = i;
          mouseActiveCounter = 1;
          handleClick(i);
        }
        break;
      }
    }

    BeginDrawing();
      ClearBackground(RAYWHITE);
      for (int i = 0; i < num_processes; i++)
        drawButton(toggleRecs[i], i);
    EndDrawing();
  }

  for (int i = 0; i < 2; i++) UnloadSound(memeSounds[i]);
  UnloadFont(fontDunkerque);
  CloseAudioDevice();
  CloseWindow();

  return 0;
}
