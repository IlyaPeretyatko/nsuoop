#pragma once
#include <string.h>
#include <iostream>
#include <vector>


class CommandParser {
    private:
        std::string configPath = "config.txt";
        bool help = false;
        std::vector<std::string> inputFiles;
        std::string outputFile;
    public:
        CommandParser() = default;
        void parser(int argc, char **argv);
};