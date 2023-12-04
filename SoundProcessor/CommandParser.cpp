#include "CommandParser.h"

void CommandParser::parser(int argc, char **argv) {
    if (argc < 3) {
        throw std::length_error("Incorrect Command");
    }
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            help = true;
        } else if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 == argc) {
                throw std::length_error("Incorrect Command");
            }
            this->configPath = argv[i + 1];
            i++;
        } else if (outputFile.empty()) {
            outputFile = argv[i];
        } else {
            this->inputFiles.push_back(argv[i]);
        }
    }
    if (inputFiles.empty()) {
        throw std::length_error("Incorrect Command");
    }
}