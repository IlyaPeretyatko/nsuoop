#include "ConsoleParser.h"
#include <cstring>
#include <regex>

bool ConsoleParser::parseOptions(int argc, char **argv) {
    if (argc == 1) {
        this->mode = 0;
    } else if (argc == 2) {
        this->mode = 1;
        this->inputFile = argv[1];
    } else if (argc == 7) {
        this->mode = 2;
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "--input") == 0 || strcmp(argv[i], "-I") == 0) {
                this->inputFile = argv[i + 1];
                ++i;
            } else if (strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0) {
                this->outputFile = argv[i + 1];
                ++i;   
            } else  if (strcmp(argv[i], "--iterations") == 0 || strcmp(argv[i], "-i") == 0) {
                this->countOfIterations = atoi(argv[i + 1]);
                ++i;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int ConsoleParser::getMode() const { return mode; }

std::string ConsoleParser::getInputFile() const { return inputFile; }

std::string ConsoleParser::getOutputFile() const { return outputFile; }

int ConsoleParser::getCountOfIterations() const { return countOfIterations; }

