#include "CommandParser.h"

void CommandParser::parser(const int argc, const char **argv) {
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

std::string CommandParser::getConfigPath() const {
    return this->configPath;
}
std::vector<std::string> CommandParser::getInputFiles() const {
  return this->inputFiles;
}

std::string CommandParser::getOutputFile() const {
  return this->outputFile;
}