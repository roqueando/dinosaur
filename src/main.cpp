#include <iostream>
#include <core/csv.h>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

template<std::size_t... Index, typename Row, typename Reader>
bool read_row_helper(std::index_sequence<Index...>, Row& row, Reader& r)
{
  return r.read_row(std::get<Index>(row)...);
}

template<std::size_t... Index, typename Row>
void fill_values(std::index_sequence<Index...>, Row& row, std::vector<double>& data)
{
  data.insert(data.end(), { std::get<Index>(row)... });
}

int main()
{
  fs::path filepath = "/home/omolu/studdo/dinosaur/data/iris.csv";

  std::ifstream p("../../data/iris.csv");
  io::CSVReader<5> csv_reader(filepath);

  std::vector<std::string> categorical_columns;
  std::vector<double> values;

  using row_type = std::tuple<double, double, double, double, std::string>;
  row_type row;

  try {
    bool done = false;
    while (!done) {
      done = !read_row_helper(std::make_index_sequence<std::tuple_size<row_type>::value>{}, row, csv_reader);
      if (!done) {
        categorical_columns.push_back(std::get<4>(row));
        fill_values(std::make_index_sequence<4>{}, row, values);
      }
    }
  } catch (const io::error::no_digit& err) {
    std::cerr << err.what() << "\n";
  }

  return 0;
}
