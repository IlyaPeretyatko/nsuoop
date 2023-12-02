#include "Launch.h"
#include <string.h>


void Launch::start(int argc, char **argv) {
    this->parserCommand(argc, argv);


}

void Launch::parserCommand(int argc, char **argv) {
    int countInputFiles = 1;
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
            std::pair<std::string, int> newFile = {argv[i], countInputFiles};
            this->inputFiles.push_back(newFile);
            countInputFiles++;
        }
    }
}