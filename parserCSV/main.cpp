#include "print_tuple.h"
//#include "parser_csv.h"


int main() {
  auto tuple = std::make_tuple(1, "dog", 3.14, 5, 7, 'y', 8, "aboba");
  std::cout << tuple << std::endl;

//    std::ifstream file("test.csv");
//    CSVParser<int, std::string> parser(file, 0);
    // for (std::tuple<int, std::string> rs : parser) {
    //     std::cout << rs << std::endl;
    // }
    return 0;
}