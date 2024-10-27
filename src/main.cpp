#include <iostream>
#include <core/csv.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include <dlib/matrix.h>

namespace fs = std::filesystem;

int main()
{
  dlib::matrix<double> data;

  std::ifstream file("../../data/iris.csv");

  if (!file) {
    std::cerr << "error opening file" << std::endl;
    return 1;
  }

  file >> data;
  if (data.size() == 0) {
    std::cerr << "error on loading csv to matrix" << std::endl;
  }

  std::cout << data << std::endl;

  return 0;
}
