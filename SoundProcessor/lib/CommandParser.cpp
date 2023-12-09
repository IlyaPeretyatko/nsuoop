#include "CommandParser.h"

void CommandParser::parser(const int argc, const char **argv) {
    if (argc < 3) {
        throw std::length_error("Incorrect command.");
    }
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            help = true;
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

bool CommandParser::getFlagHelp() const {
  return help;
}

void CommandParser::printHelp() const {
  std::cout << "./SoundProcessor [-h] [-c config.txt output.wav input1.wav [input2.wav …]]\n" << std::endl;
  std::cout << "Поддерживаемый формат:" << std::endl;
  std::cout << "1. Аудио-формат PCM (без кодирования)." << std::endl;
  std::cout << "2. Моно-звук (1 канал)." << std::endl;
  std::cout << "3. Разрядность 16 бит со знаком (signed 16 bit (little-endian)) — это значит, что один сэмпл представлен целым 16-битным числом со знаком." << std::endl;
  std::cout << "4. Частота 44100 Гц." << std::endl;
  std::cout << "Конвертеры:" << std::endl;
  std::cout << "mute [start] [end] (заглушить интервал)" << std::endl;
  std::cout << "mix $[number] [start] (смиксовать основной поток с другим потоком с определённой секунды)" << std::endl;
  std::cout << "boost [start] [end] (бассбуст на интервале)" << std::endl;

}