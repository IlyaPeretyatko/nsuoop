#include "parser_csv.h"
#include "print_tuple.h"

int main() {
//  auto tuple = std::make_tuple();
//  std::cout << tuple << std::endl;

    std::ifstream file("test.csv");
    CSVParser<int, double> parser(file, 0);
     for (auto rs : parser) {
         std::cout << rs << std::endl;
     }
    return 0;
}