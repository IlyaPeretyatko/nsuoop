#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

class ConfigParser {
    private:
        std::vector<std::string> converters;
        std::vector<std::string> arguments;

        void readArgMute(const std::string & line);
        void readArgMix(const std::string & line);
        void readArgBoost(const std::string & line);
    public:
        ConfigParser() = default;
        void parser(const std::string & configPath);
        std::vector<std::string> getConverters() const;
        std::vector<std::string> getArguments() const;
};