#include "../include/headers/file_manager.h"
#include <stdlib.h>


ImageManager *CreateImageManager(int count) {
    ImageManager *manager = malloc(sizeof(ImageManager));
    manager->count = count;
    manager->current = 0;
    manager->img = malloc(sizeof(ImageObject) * count);


    return manager;
}


void LoadImageToManager(ImageManager *manager, int index, const char* path) {
    Image img = LoadImage(path);

    manager->img[index].texture = LoadTextureFromImage(img);
    manager->img[index].width = img.width;
    manager->img[index].height = img.height;
    manager->img[index].path = path;

    UnloadImage(img);
}



ImageObject *GetCurrImage(ImageManager *manager) {
    return &manager->img[manager->current];
}




void next_image(ImageManager *manager) {
    manager->current++;
    if(manager->current >= manager->count)
        manager->current = 0;
}


void prev_image(ImageManager *manager) {
    manager->current--;
    if(manager->current < 0) 
        manager->current = manager->count - 1;
}



void destroy_images(ImageManager *manager) {
    for(int i=0; i<manager->count; i++) {
        UnloadTexture(manager->img[i].texture);
    }

    free(manager->img);
    free(manager);
}

