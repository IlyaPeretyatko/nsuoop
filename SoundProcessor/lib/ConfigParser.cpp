#include "ConfigParser.h"

std::vector<std::string> ConfigParser::getConverters() const {
  return converters;
}

std::vector<std::string> ConfigParser::getArguments() const {
  return arguments;
}

void ConfigParser::parser(const std::string & configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        throw std::length_error("File not open. (Config)");
    }
    std::string line;
    while(std::getline(file, line, '\n')) {
        if (line[0] == '#' || line.empty()) {
            continue;
        } else if (line[0] == 'm' && line[1] == 'u' && line[2] == 't' && line[3] == 'e' && line[4] == ' ') {
            readArgMute(line);
        } else if (line[0] == 'm' && line[1] == 'i' && line[2] == 'x' && line[3] == ' ' && line[4] == '$') {
            readArgMix(line);
        } else if (line[0] == 'b' && line[1] == 'o' && line[2] == 'o' && line[3] == 's' && line[4] == 't' && line[5] == ' ') {
            readArgBoost(line);
        } else {
            throw std::length_error("Incorrect config file.");
        }
    }
}

void ConfigParser::readArgMute(const std::string & line) {
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
                throw std::length_error("Incorrect converter settings. (Mute)");
            }
        } else {
            throw std::length_error("Incorrect converter settings. (Mute)");
        }
    }
    if (start.empty() || end.empty()) {
        throw std::length_error("Incorrect converter settings. (Mute)");
    }
    arguments.push_back(start);
    arguments.push_back(end);
}


void ConfigParser::readArgMix(const std::string & line) {
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
                throw std::length_error("Incorrect converter settings. (Mix)");
            }
        } else {
            throw std::length_error("Incorrect converter settings. (Mix)");
        }
    }
    if (number.empty() || start.empty()) {
        throw std::length_error("Incorrect converter settings. (Mix)");
    }
    arguments.push_back(number);
    arguments.push_back(start);
}

void ConfigParser::readArgBoost(const std::string & line) {
    converters.push_back("boost");
    std::string start = "";
    std::string end = "";
    std::string koef = "";
    bool readStart = true;
    bool readEnd = false;
    for (int i = 6; i < (int)line.size(); ++i) {
        if (line[i] >= '0' && line[i] <= '9') {
            if (readStart) {
                start += line[i];
            } else if (readEnd) {
                end += line[i];
            } else {
                koef += line[i];
            }
        } else if (line[i] == ' ') {
            if (readStart) {
                readStart = false;
                readEnd = true;
            } else if (readEnd) {
                readEnd = false;
            } else {
                throw std::length_error("Incorrect converter settings. (Boost)");
            }
        } else {
            throw std::length_error("Incorrect converter settings. (Boost)");
        }
    }
    if (start.empty() || end.empty() || koef.empty()) {
        throw std::length_error("Incorrect converter settings. (Boost)");
    }
    arguments.push_back(start);
    arguments.push_back(end);
    arguments.push_back(koef);
}
