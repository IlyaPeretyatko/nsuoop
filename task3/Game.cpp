#include "Game.h"
#include "Life.h"
#include <cstring>
#include <regex>

bool Game::getOptions(int argc, char **argv) {
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

void Game::launch() {
    if (mode == 2) {
        this->offlineLaunch();
    } else {
        this->onlineLaunch();
    }

}

void Game::offlineLaunch() {
    Life universe;
    universe.getUniverseFromFile(this->inputFile);
    for (int i = 0; i < countOfIterations; ++i) {
        universe.newGeneration();
    }
    universe.saveToFile(this->outputFile);
}

void Game::onlineLaunch() {
    Life universe;
    if (mode == 0) {
        universe.getUniverseFromFile("../examples/example.life");
    } else if (mode == 1) {
        universe.getUniverseFromFile(this->inputFile);
    }
    while (true) {
        std::string command;
        std::getline(std::cin, command);
        std::smatch smatch;
        if (command == "exit") {
            break;
        } else if (command == "help") {
            system("clear");
            std::cout << "dump <filename> - save universe to file;\n"
                         "tick <n> - calculate n (default 1) iterations and print result;\n"
                         "exit - finish game;\n"
                         "help - print help about commands;\n";
        } else if (std::regex_search(command, smatch, std::regex("^(dump )(\\S*)"))) {
            universe.saveToFile(smatch[2].str());
        } else if (std::regex_search(command, std::regex("^tick")) || command.empty()) {
            system("clear");
            countOfIterations = 1;
            if (std::regex_search(command, smatch, std::regex("^(tick )(\\S*)"))) {
            countOfIterations = stoi(smatch[2].str());
            }
            for (int i = 0; i < countOfIterations; ++i) {
               universe.newGeneration();
            }
            universe.printUniverse();
        }
    }

}
