#include "WordCounter.h"


bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    return a.second > b.second;
}


void WordCounter::output(std::ostream& fileOut) {
    std::vector<std::pair<std::string, int>> mapVector;
    for (auto& it : table) {
        mapVector.push_back(it);
    }
    std::sort(mapVector.begin(), mapVector.end(), cmp);
    size_t count = 0;
    for (auto& it : mapVector) {
        count += it.second;
    }
    for (auto& it : mapVector) {
        fileOut << it.first << " - " << it.second << " - " << (it.second * 100.00) / count << "\n";
    }
}

void WordCounter::parser(std::istream& fileIn) {
    std::string word;
    std::string line;
    while(std::getline(fileIn, line, '\n')) {
        for (size_t i = 0; i < line.size(); ++i) {
            if (isalnum(line[i]) != 0) {
                word += line[i];
            } else if (!word.empty()) {
                if (table.find(word) == table.end()) {
                    table[word] = 1;
                } else {
                    table[word] += 1;
                }
                word.clear();
            }
        }
        if (!word.empty()) {
            if (table.find(word) == table.end()) {
                table[word] = 1;
            } else {
                table[word] += 1;
            }
            word.clear();
        }
        line.clear();
    }
}
