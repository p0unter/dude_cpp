#include <stdio.h>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "./include/raygui.h"

int main() {
  InitWindow(400, 200, "RayGUI Test");

  SetTargetFPS(60);

  bool showMessageBox = false;

  int scMonitor = GetCurrentMonitor();
  int scWidth = GetMonitorWidth(scMonitor);
  int scHeight = GetMonitorHeight(scMonitor);

  SetWindowPosition(0, 0);
  SetWindowSize(scWidth, scHeight);

  int comboboxSelected = 0;
  const char *comboboxContent = "This is ComboBox;Select 1;Select 2;Select 3";

  Color pickerColor;

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      
      GuiColorPicker((Rectangle){ 25, 20, 180, 80}, "Color Picker", &pickerColor);
      GuiComboBox((Rectangle){ 25, 200, 180, 30 }, comboboxContent, &comboboxSelected); 
      
      if (GuiButton((Rectangle){ 25, 230, 180, 30 }, "#191#Show Message")) 
        showMessageBox = true;

      if (showMessageBox) {
        int result = GuiMessageBox((Rectangle){ scWidth / 2 - 125, scHeight / 2 - 100, 250, 100 },
            "#191#Message Box", "Hi, there! This a message box from RayGUI library.", "Good;Fine");

        if (result >= 0)
          showMessageBox = false;

        //printf("MessageBox returned value: %d", result);
      }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
