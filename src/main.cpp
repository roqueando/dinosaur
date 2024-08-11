#include <iostream>
#include <core/csv.h>
#include <filesystem>

namespace fs = std::filesystem;

template<std::size_t... index, typename T, typename R>
bool read_row_helper(std::index_sequence<index...>, T& row, R& r)
{
  return r.read_row(std::get<index>(row)...);
}


int main()
{
  fs::path filepath = "/home/omolu/studdo/dinosaur/data/iris.csv";
  io::CSVReader<5> csv_reader(filepath);

  std::vector<std::string> categorical_columns;
  std::vector<double> values;

  using row_type = std::tuple<double, double, double, double, std::string>;
  row_type row;
  std::cout << "hello there" << std::endl;

  return 0;
}
