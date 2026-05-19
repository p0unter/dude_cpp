#include <raylib.h>
#include <stdio.h>

#define STOP_POINT 1000

int main() {
  InitWindow(200, 200, "Game Menu Preview");

  SetTargetFPS(60);

  int current_fps = { 0 };

  int scMonitor = GetCurrentMonitor(), scWidth = { 0 }, scHeight = { 0 }, wWidth = { 0 }, wHeight = { 0 };
  char resolution[256] = { 0 };
  float circleRadius = 0.0f;
  
  scWidth = GetMonitorWidth(scMonitor);
  scHeight = GetMonitorHeight(scMonitor);

  ToggleFullscreen();

  SetExitKey(0);
  
  int step_index = 0, is_out = 0;
  while (!WindowShouldClose()) {
    if (step_index != STOP_POINT) step_index++;

    if (circleRadius > scHeight - 100) is_out = 1;
    if (circleRadius < 0.0f) is_out = 0;

    if (!is_out) {
      circleRadius += 1.0f;
    } else {
      circleRadius -= 1.0f;
    }
    printf("Radius = %f, step_index = %d\n", circleRadius, step_index);
    
    current_fps = GetFPS();
    
    scMonitor = GetCurrentMonitor();
    scWidth = GetMonitorWidth(scMonitor);
    scHeight = GetMonitorHeight(scMonitor);

    wWidth = GetScreenWidth();
    wHeight = GetScreenHeight();
    
    if (IsKeyPressed(KEY_ESCAPE)){ 
      ToggleFullscreen();
      
      int check_and_append = IsWindowFullscreen() ? 200 : -200;
      wHeight += check_and_append;
      wWidth += check_and_append;
      SetWindowPosition((wWidth / 2) - 200, (wHeight / 2) - 200);
      SetWindowSize(wWidth, wHeight);
    }

    snprintf(resolution, sizeof(resolution), "%dx%d - %dx%d\n%s", scWidth, scHeight, wWidth, wHeight, GetMonitorName(scMonitor));
    printf("Resolution: %s, scWidth: %d, scHeight: %d\n", resolution, wWidth, wHeight);

    BeginDrawing();
  
    ClearBackground(RAYWHITE);
    
    for (int i = 0; i <= step_index; i++) {
      DrawCircleLines(wWidth/2, wHeight/2, circleRadius + i/0.1f, BLACK);
    }

    DrawFPS(20, 20);

    DrawText(resolution, 20, 40, 20, DARKGREEN);
    
    EndDrawing();
  }

  CloseWindow();
}
