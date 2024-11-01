#ifndef CONSOLEPARSER_H_
#define CONSOLEPARSER_H_

#include <iostream>
#include <regex>

class ConsoleParser {
    private:
        std::string inputFile;
        std::string outputFile;
        int countOfIterations;
        int mode;
    public:
        ConsoleParser() = default;
        int getMode() const;
        bool parseOptions(int argc, char **argv);
        std::string getInputFile() const;
        std::string getOutputFile() const;
        int getCountOfIterations() const;
};


#endif