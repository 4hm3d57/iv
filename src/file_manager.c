#include "../include/headers/file_manager.h"
#include <winnt.h>



void InitFileManager(FileManager *fm, const char* start_path) {
    fm->file_count = 0;
    fm->curr_index = 0;
    fm->directory_loaded = false;


    strcpy(fm->current_directory, start_path);

    printf("File manager initialized with directory: %s\n", start_path);
}



bool load_dir(FileManager *fm, const char* path) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    char search_path[MAX_PATHS + 2];
    
    snprintf(search_path, sizeof(search_path), "%s\\", path);
   

    hFind = FindFirstFile(search_path, &findFileData);
    if(hFind == INVALID_HANDLE_VALUE) {
        printf("Failed to open directory, error code: %lu\n", GetLastError());
        return false;
    }


    do {
        //TODO: Process each file 
    } while(FindNextFile(hFind, &findFileData) != 0);

    return true;
}
