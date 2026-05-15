#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

int main() {

  InitWindow(100, 100, "3D Test");

  int scMonitor = GetCurrentMonitor();
  int scWidth = GetMonitorWidth(scMonitor);
  int scHeight = GetMonitorHeight(scMonitor);
  
  printf("[INFO] SCWIDTH: %d, SCHEIGHT: %d, CURRENT MONITOR: %d\n", scWidth, scHeight, scMonitor);

  SetWindowPosition(0, 0);
  SetWindowSize(scWidth, scHeight);

  ToggleFullscreen();

  Rectangle fullscreenButton = { scWidth-300, 0, 300, 50 };
  int fullscreenButtonHover = 0;
  
  char* fullscreenButtonContent = { 0 };

  /*-----3D Definitions-----*/
  Camera3D camera = { 0 };
  camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 60.0f; // Field-of-view
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

  Model character = LoadModel("./Barbarian.glb");
  Vector3 position = { 0.0f, 0.0f, 0.0f };
  Texture2D texture = LoadTexture("./barbarian_texture.png");
  for (int i = 0; i < character.materialCount; i++) {
    character.materials[i].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
  }
  GenTextureMipmaps(&texture);
  SetTextureFilter(texture, TEXTURE_FILTER_BILINEAR);
  /*------------------------*/

  DisableCursor();
  
  SetTargetFPS(60);

  int fontSize = 30;

  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

  while (!WindowShouldClose()) {
    float wheel = GetMouseWheelMove();
    if (wheel != 0) {
      camera.fovy += wheel * 2.0f;
      if (camera.fovy < 60.0f) camera.fovy = 60.0f;
      if (camera.fovy > 160.0f) camera.fovy = 160.0f;
    }

    if (IsWindowFocused()) {
      if (IsCursorHidden()) {
        Vector2 mouseDelta = GetMouseDelta();
        Vector3 rotation = { mouseDelta.x * 0.1f, mouseDelta.y * 0.1f, 0.0f }; 
        UpdateCameraPro(&camera, (Vector3){0, 0, 0}, rotation, 0.0f);

        Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, camera.up));

        float speed = 0.15f;
        if (IsKeyDown(KEY_LEFT_SHIFT)) speed = 0.45f;
        Vector3 velocity = { 0 };

        if (IsKeyDown(KEY_W)) velocity = Vector3Add(velocity, forward);
        if (IsKeyDown(KEY_S)) velocity = Vector3Subtract(velocity, forward);
        if (IsKeyDown(KEY_D)) velocity = Vector3Add(velocity, right);
        if (IsKeyDown(KEY_A)) velocity = Vector3Subtract(velocity, right);

        if (IsKeyDown(KEY_E)) velocity = Vector3Add(velocity, camera.up);
        if (IsKeyDown(KEY_Q)) velocity = Vector3Subtract(velocity, camera.up);

        if (Vector3Length(velocity) > 0) {
            velocity = Vector3Scale(Vector3Normalize(velocity), speed);
        }

        camera.position = Vector3Add(camera.position, velocity);
        camera.target = Vector3Add(camera.target, velocity);
      }
    }
    
    //if (IsCursorHidden() && IsWindowFocused()) UpdateCamera(&camera, CAMERA_FREE);
    if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

    if (IsKeyPressed(KEY_X)) {
      if (IsCursorHidden()) {
        EnableCursor();
      } else {
        DisableCursor();
      }
    }

    if (CheckCollisionPointRec(GetMousePosition(), fullscreenButton)) {
      fullscreenButtonHover = 1;
      if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        ToggleFullscreen();
      }
    } else {
      fullscreenButtonHover = 0;
    }

    fullscreenButtonContent = "Window Mode";
    if (!IsWindowFullscreen()) {
      fullscreenButtonContent = "Fullscreen Mode";
    }

    BeginDrawing();

      ClearBackground(RAYWHITE);

      BeginMode3D(camera);

        DrawModel(character, position, 1.0f, WHITE);
        
        //DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        //DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        
        DrawGrid(1000, 1.0f);

      EndMode3D();

      DrawRectangleRec(fullscreenButton, fullscreenButtonHover ? GRAY : LIGHTGRAY);
      DrawText(
        fullscreenButtonContent, 
        fullscreenButton.x + (fullscreenButton.width / 2) - (MeasureText(fullscreenButtonContent, fontSize) / 2), 
        fullscreenButton.y + (fullscreenButton.height / 2) - (fontSize / 2), 
        fontSize, 
        BLACK
      );

      DrawRectangle( 10, 10, 500, 93, Fade(SKYBLUE, 0.5f));
      DrawRectangleLines( 10, 10, 500, 93, BLUE);
      DrawText("Controls:", 20, 20, 20, BLACK);
      DrawText("- Hide/Show Cursor: press X", 40, 40, 30, DARKGRAY);

    EndDrawing();
  }

  UnloadTexture(texture);
  UnloadModel(character);
  CloseWindow();

  return 0;
}
