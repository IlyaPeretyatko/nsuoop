#pragma once

#include <iostream>
#include <vector>


class Launch {
    private:
        std::string configPath = "config.txt";
        bool help = false;
        std::vector<std::pair<std::string, int>> inputFiles;
        std::string outputFile;

        void parserCommand(int argc, char **argv);
    public:
        Launch() = default;
        void start(int argc, char **argv);
};