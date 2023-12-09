#pragma once
#include <string.h>
#include <iostream>
#include <vector>


class CommandParser {
    private:
        std::string configPath = "config.txt";
        std::vector<std::string> inputFiles;
        std::string outputFile;
    public:
        CommandParser() = default;
        void parser(const int argc, const char **argv);
        std::string getConfigPath() const;
        std::vector<std::string> getInputFiles() const;
        std::string getOutputFile() const;
        void printHelp() const;
};