#include <filesystem>
#include <fstream>
#include <iostream>
#include <cctype>

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

struct FileInfo {
  std::string fileName;
  bool exists;
  std::string absPath;
};

FileInfo fileValidate(const std::string &filePath) {
  FileInfo result;
  std::filesystem::path p(filePath);
  result.fileName = p.filename().string();
  result.exists = std::filesystem::exists(filePath);
  result.absPath = std::filesystem::absolute(filePath);
  return result;
}

int main(int argc, char *argv[]) {
  // argc is count of argument
  // argv is vector/array of argument provided when calling the program
  if (argc < 2)
    return 1;

  FileInfo fileInfo = fileValidate(argv[1]);

  if (fileInfo.exists == 0) {
    std::cerr << "File " + fileInfo.fileName + " does not exists\n";
    return 1;
  }
  /// opening file                mode binary
  std::ifstream file(argv[1], std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "File can't be opened";
    return 1;
  }

  char byte;
  while (file.get(byte)) {
    unsigned char value = static_cast<unsigned char>(byte);

    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value) << " ";
  }
  std::cout << byte;
  file.close();
  return 0;
}
