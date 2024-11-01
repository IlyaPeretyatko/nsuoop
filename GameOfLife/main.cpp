#include <iostream>
#include "FileService.h"
#include "ConsoleParser.h"


int main(int argc, char **argv) {
    ConsoleParser *consoleParser = new ConsoleParser();
    Life *life = new Life();
    FileService *fileService = new FileService(life);

    if (!consoleParser->parseOptions(argc, argv)) {
        std::cout << "Uncorrect args." << std::endl;
    }
    int mode = consoleParser->getMode();
    std::string inputFile = consoleParser->getInputFile();
    std::string outputFile = consoleParser->getOutputFile();

    if (mode == 2) {
        std::string path = "../examples/";
        path += inputFile;
        fileService->getUniverseFromFile(path);
        for (int i = 0; i < consoleParser->getCountOfIterations(); ++i) {
            life->newGeneration();
        }
        path = "../";
        path += outputFile;
        fileService->saveToFile(path);
    } else {
        if (mode == 0) {
            fileService->getUniverseFromFile("../examples/example.life");
        } else if (mode == 1) {
            std::string path = "../examples/";
            path += inputFile;
            fileService->getUniverseFromFile(path);
        }
        while (true) {
            std::string command;
            std::getline(std::cin, command);
            std::smatch smatch;
            if (command == "exit") {
                system("clear");
                break;
            } else if (command == "help") {
                system("clear");
                std::cout << "dump <filename> - save universe to file;\n"
                            "tick <n> - calculate n (default 1) iterations and print result;\n"
                            "exit - finish game;\n"
                            "help - print help about commands;\n";
            } else if (std::regex_search(command, smatch, std::regex("^(dump )(\\S*)"))) {
                std::string path = "../";
                path += smatch[2].str();
                fileService->saveToFile(path);
            } else if (std::regex_search(command, std::regex("^tick")) || command.empty()) {
                system("clear");
                int countOfIterations = 1;
                if (std::regex_search(command, smatch, std::regex("^(tick )(\\S*)"))) {
                    countOfIterations = stoi(smatch[2].str());
                }
                for (int i = 0; i < countOfIterations; ++i) {
                    life->newGeneration();
                }
                fileService->printUniverse();
            }
        }
    }
    delete(life);
    delete(consoleParser);
    delete(fileService);
    return 0;
}