#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


#include "../raylib/raylib.h"


    
typedef struct {
    Texture2D texture;
    int width;
    int height;
    const char* path;
} ImageObject;


typedef struct {
    ImageObject *img;
    int current;
    int count;
} ImageManager;

    
ImageManager *CreateImageManager(int count);
void LoadImageToManager(ImageManager *manager, int index, const char* path);
ImageObject *GetCurrImage(ImageManager* manager);



void next_image(ImageManager *manager);
void prev_image(ImageManager *manager);
void destroy_images(ImageManager *manager);


#endif
