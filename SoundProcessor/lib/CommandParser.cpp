#include "CommandParser.h"

void CommandParser::parser(const int argc, const char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            printHelp();
        } else if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 == argc) {
                throw std::length_error("Incorrect command.");
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
        throw std::length_error("Incorrect command.");
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


void CommandParser::printHelp() const {
  std::cout << "Help:" << std::endl;
  std::cout << "./SoundProcessor [-h] [-c config.txt output.wav input1.wav [input2.wav …]]" << std::endl;
  std::cout << "Supported format:" << std::endl;
  std::cout << "1. Audio-format PCM (without coding)." << std::endl;
  std::cout << "2. Mono-sound (1 channel)." << std::endl;
  std::cout << "3. signed 16 bit (little-endian)) — sample." << std::endl;
  std::cout << "4. Frequency 44100 Hz." << std::endl;
  std::cout << "Converters:" << std::endl;
  std::cout << "mute [start] [end] (mute interval)" << std::endl;
  std::cout << "mix $[number] [start] (mix main steam with other)" << std::endl;
  std::cout << "boost [start] [end] [1-10] (up volume)";

}