#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H



#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>


#define MAX_SIZE 1024
#define MAX_PATHS 256
#define EXT_PATH 8


typedef struct {
    char path[MAX_PATHS];
    char filename[MAX_PATHS];
    char extension[EXT_PATH];
    bool isImage;
    size_t image_size;
} FileEntry;


typedef struct {
    FileEntry file[MAX_SIZE];
    int file_count;
    int curr_index;
    char current_directory[MAX_PATHS];
    bool directory_loaded;
} FileManager;

    
void InitFileManager(FileManager *fm, const char* start_path);
    

bool load_dir(FileManager *fm, const char* path);


#endif

