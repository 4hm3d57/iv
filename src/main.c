#include "../include/raylib/raylib.h"
#include "../include/headers/file_manager.h"


int main() {
    const int win_width = 800;
    const int win_height=  600;

    
    InitWindow(win_width, win_height, "image viewer");
    SetTargetFPS(60);
    
    
    ImageManager *manager = CreateImageManager(3);


    LoadImageToManager(manager, 0, "assets/test1.png");
    LoadImageToManager(manager, 1, "assets/test2.png");
    LoadImageToManager(manager, 2, "assets/test3.png");
    
    

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_RIGHT))
            next_image(manager);
    
        if(IsKeyPressed(KEY_LEFT))
            prev_image(manager);

        BeginDrawing();
            ClearBackground(GRAY);

            ImageObject* img = GetCurrImage(manager);
            // image width and height
            float image_width = img->texture.width;
            float image_height = img->texture.height;

            // calculate scale
            float scaleX = (float)win_width / image_width;
            float scaleY = (float)win_height / image_height;

            float scale = scaleX < scaleY ? scaleX : scaleY;

            // calculate final size
            float draw_width = image_width * scale;
            float draw_height = image_height * scale;

            // center the image
            float posX = (win_width - draw_width) / 2.0f;
            float posY = (win_height - draw_height) / 2.0f;
            Rectangle source = { 0, 0, image_width, image_height, };
            Rectangle dest = { posX, posY, draw_width, draw_height };
            Vector2 origin = { 0, 0 };
            DrawTexturePro(img->texture, source, dest, origin, 0.0f, WHITE);
        EndDrawing();
    }

    
    destroy_images(manager);
    CloseWindow();

    return 0;
}
