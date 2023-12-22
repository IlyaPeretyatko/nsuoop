#pragma once

#include <iostream>
#include <fstream>
#include <tuple>
#include <string>


template <typename ...Args>
class CSVParser {
    public:
        CSVParser(std::ifstream & file, size_t countLineSkip, char rowSeparator = '\n', char columnSeparator = ',', char escapeSeparator = '\"') :
        file_(file), countLineSkip_(countLineSkip), rowSeparator_(rowSeparator), columnSeparator_(columnSeparator), escapeSeparator_(escapeSeparator) {
            if (!file.is_open()) {
                //error
            }
            currentLine_ = 0;
            std::string lineSkip;
            for (size_t i = 0; i < countLineSkip_; ++i) {
                std::getline(file_, lineSkip, rowSeparator_);
            }
        }
    private:
        std::ifstream & file_;
        size_t countLineSkip_;
        char rowSeparator_;
        char columnSeparator_;
        char escapeSeparator_;
        size_t currentLine_;
};