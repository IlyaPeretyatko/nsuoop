#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

class ConfigParser {
    private:
        std::vector<std::string> converters;
        std::vector<std::string> arguments;

        void readArgMute(std::string const line);
        void readArgMix(std::string const line);
    public:
        ConfigParser() = default;
        void parser(std::string const configPath);
};