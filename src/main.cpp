#include "../include/raylib/raylib.h"
#include <iostream>


const int window_width = 800;
const int window_height = 600;


int main() {
    InitWindow(window_width, window_height, "image_viewer");
    
    SetTargetFPS(60);
    
    Texture2D image = LoadTexture("assets/test.png");


    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(GRAY);
            DrawTexture(image, window_width/2 - image.width/2, window_height/2 - image.height/2, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(image);
    CloseWindow();

    return 0;
}

