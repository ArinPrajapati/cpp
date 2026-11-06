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

struct FileInfo{
    std::string fileName;
    bool exists;
    std::string absPath;
};

FileInfo fileValidate(const std::string& filePath){
    FileInfo result;
    std::filesystem::path p(filePath);
    result.fileName = p.filename();
    result.exists = std::filesystem::exists(filePath);
    result.absPath = std::filesystem::absolute(filePath);
    return result;
}


int main(int argc,char* argv[]){
    // argc is count of argument
    // argv is vector/array of argument provided when calling the program
    if(argc < 2) return 1;

    std::cout << fileValidate(argv[0]).exists << "\n";
    std::cout << fileValidate(argv[0]).fileName << "\n";
    std::cout << fileValidate(argv[0]).absPath << "\n";
    return 0;
}
