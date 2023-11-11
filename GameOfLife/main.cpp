#include <iostream>
#include "Game.h"


int main(int argc, char **argv) {
    Game gamingSession;
    if (gamingSession.getOptions(argc, argv)) {
        gamingSession.launch();
    }
    return 0;
}