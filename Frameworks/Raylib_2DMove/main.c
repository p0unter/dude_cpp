#include "raylib.h"
#include <stdio.h>

int scWidth = 1280, scHeight = 720;

float chSpeed = 1.5f;
int inBoost = 0;

void drawCircle(Vector2 charPos, int boosted) {
    DrawCircle(charPos.x, charPos.y, 100, GOLD);
    DrawCircle(charPos.x - 40, charPos.y - 35, 20, BLACK);
    DrawCircle(charPos.x + 40, charPos.y - 35, 20, BLACK);
    DrawCircleSector((Vector2){ charPos.x, charPos.y }, 100, 180, 0, 100, RED);
    if (boosted) {
      DrawRectangle(charPos.x - 60, charPos.y - 70, 35, 7, BLACK);
    }
}

int main(void)
{
  //scWidth = GetScreenWidth();
  //scHeight = GetScreenHeight(); 
  InitWindow(scWidth, scHeight, "raylib example - 2d move");

  Image winIcon = LoadImage("./logo.png");
  ImageFormat(&winIcon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
  SetWindowIcon(winIcon);
  UnloadImage(winIcon);

  Vector2 characterPos = (Vector2){ 0, 0 };

  Camera2D camera = { 0 };
  camera.target = (Vector2){ characterPos.x + scWidth, characterPos.y + scHeight };
  camera.offset = (Vector2){ scWidth/2.0f, scHeight/2.0f };
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
  
  printf("w: %d, h: %d\n", scWidth, scHeight);
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) characterPos.x += chSpeed;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) characterPos.x -= chSpeed;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) characterPos.y += chSpeed;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) characterPos.y -= chSpeed;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (IsKeyDown(KEY_LEFT_SHIFT)) {
      chSpeed = 3.0f;
      inBoost = 1;
    } else {
      chSpeed = 1.5f;
      inBoost = 0;
    }

    camera.target = (Vector2){ characterPos.x, characterPos.y };

    BeginMode2D(camera);

    DrawRectangle(250, 250, 40, 40, BLACK);
    drawCircle(characterPos, inBoost);
    
    EndMode2D();
    
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
