#include "ConfigParser.h"

std::vector<std::string> ConfigParser::getConverters() const {
  return converters;
}

std::vector<std::string> ConfigParser::getArguments() const {
  return arguments;
}

void ConfigParser::parser(std::string const configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        throw std::length_error("File Not Open");
    }
    std::string line;
    while(std::getline(file, line, '\n')) {
        if (line[0] == '#' || line.empty()) {
            continue;
        } else if (line[0] == 'm' && line[1] == 'u' && line[2] == 't' && line[3] == 'e' && line[4] == ' ') {
            readArgMute(line);
        } else if (line[0] == 'm' && line[1] == 'i' && line[2] == 'x' && line[3] == ' ' && line[4] == '$') {
            readArgMix(line);
        } else {
            throw std::length_error("Incorrect Config File");
        }
    }
}

void ConfigParser::readArgMute(std::string const line) {
    converters.push_back("mute");
    std::string start = "";
    std::string end = "";
    bool readStart = true;
    for (int i = 5; i < (int)line.size(); ++i) {
        if (line[i] >= '0' && line[i] <= '9') {
            if (readStart) {
                start += line[i];
            } else {
                end += line[i];
            }
        } else if (line[i] == ' ') {
            if (readStart) {
                readStart = false;
            } else {
                throw std::length_error("Incorrect Converter Setting");
            }
        } else {
            throw std::length_error("Incorrect Converter Setting");
        }
    }
    if (start.empty() || end.empty()) {
        throw std::length_error("Incorrect Converter Setting");
    }
    arguments.push_back(start);
    arguments.push_back(end);
}


void ConfigParser::readArgMix(std::string const line) {
    converters.push_back("mix");
    std::string number = "";
    std::string start = "";
    bool readNumber = true;
    for (int i = 5; i < (int)line.size(); ++i) {
        if (line[i] >= '0' && line[i] <= '9') {
            if (readNumber) {
                number += line[i];
            } else {
                start += line[i];
            }
        } else if (line[i] == ' ') {
            if (readNumber) {
                readNumber = false;
            } else {
                throw std::length_error("Incorrect Converter Setting");
            }
        } else {
            throw std::length_error("Incorrect Converter Setting");
        }
    }
    if (number.empty() || start.empty()) {
        throw std::length_error("Incorrect Converter Setting");
    }
    arguments.push_back(number);
    arguments.push_back(start);
}
