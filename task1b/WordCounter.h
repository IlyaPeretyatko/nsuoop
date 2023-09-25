#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_

#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b);

class WordCounter {
    private:
        std::map<std::string, int> table;
        std::vector<std::pair<std::string, int>> mapVector;
        void mapSortToVector();
    public:
        void parser(std::istream& fileIn);
        void output(std::ostream& fileOut);
};

#endif