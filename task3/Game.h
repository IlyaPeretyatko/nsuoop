#ifndef GAME_H_
#define GAME_H_

#include <iostream>

class Game {
    private:
        std::string inputFile;
        std::string outputFile;
        int countOfIterations;
        int mode;
        void offlineLaunch();
        void onlineLaunch();
    public:
        Game() = default;
        bool getOptions(int argc, char **argv);
        void launch();
};


#endif