//#include "print_tuple.h"
#include "parser_csv.h"


int main() {
    //auto test = std::make_tuple(10, "aboba", 'x', 10.5);
    //std::cout << test << std::endl;

    std::ifstream file("test.csv");
    CSVParser<int, std::string> parser(file, 0);
    // for (std::tuple<int, std::string> rs : parser) {
    //     std::cout << rs << std::endl;
    // }
    return 0;
}