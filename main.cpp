#include "compress_file.h"
#include<iostream>
using namespace cimg_library;
int main() {
  Compress_Image File("bw3.png","matrix.txt");
  File.visualization(File.getCompressFile());
  return 0;
}
