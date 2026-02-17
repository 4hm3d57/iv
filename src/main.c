// #include "../include/raylib/raylib.h"
#include "../include/headers/file_manager.h"



int main() {
    FileManager fm;
    const char* start_path = "assets";
    InitFileManager(&fm, start_path);

    return 0;
}
