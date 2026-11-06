#include <fstream>
#include <filesystem>
#include <iostream>

/***

 // input of filepath.
 // open that file.
 // read its contents as bytes.
 // convert each bit in to hexadecimal.
 // Display pritable character next to the hex.
 // Repeat untill the file ends.

Uscase ==

Input file

./main.cpp filePath
Offset    Hex bytes         Text
00000000  48 65 6C 6C 6F   Hello

*/


int main(int argc,char* argv[]){
    // argc is count of argument
    // argv is vector/array of argument provided when calling the program
    if(argc < 2) return 1;

    std::filesystem::path full_path(argv[1]);

    std::cout << "Filename: " << full_path.filename() << std::endl;

    std::cout << "Stem: " << full_path.stem() << std::endl;

    return 0;
}
