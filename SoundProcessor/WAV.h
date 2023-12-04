#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <array>

typedef struct WAVHeader {
    char chunkID[4];
    uint32_t chunkSize; 
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} WAVHeader;

class WAV {
    private:
        WAVHeader header;
        std::vector<std::array<int16_t, 44100>> stream;
    public:
        WAV(std::istream& in);
        void readStream(std::istream& in);
};


