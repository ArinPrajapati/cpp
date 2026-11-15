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

  constexpr int BYTES_PER_LINE = 16;
  char buffer[BYTES_PER_LINE];
  size_t offset = 0;

  std::cout << "Offset    Hex bytes                                        Text\n";
  while(file.read(buffer,BYTES_PER_LINE) || file.gcount() > 0){
      int count = static_cast<int>(file.gcount());

      std::cout << std::hex << std::setw(8) << std::setfill('0') << offset << "  ";

      for(int i = 0;i<BYTES_PER_LINE;i++){
          if(i < count){
              std::count << std::setw(2) << static_cast<int>(static_cast<unsigned char>(buffer[i])) << " ";
          }else{
              std::cout << "   "; //Padding
          }
      }
      std::cout << "  ";
      for(int i = 0; i < count;i++){
          unsigned char c = static_cast<unsigned char>(buffer[i]);
          std::cout << (std::isprint(c) ? static_cast<char>(c) : ".");
      }

      std::cout << "\n";
      offset += count;
  }

  file.close();
  return 0;
}
