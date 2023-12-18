#include "print_tuple.h"


int main() {
    auto test = std::make_tuple(10, "aboba", 'x', 10.5);
    std::cout << test << std::endl;
    return 0;
}