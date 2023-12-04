#include "WAV.h"

 WAV::WAV(std::istream& in) {
    in.read(reinterpret_cast<char*>(&header), sizeof(WAVHeader));
}

void WAV::readStream(std::istream& in) {
    std::array<int16_t, 44100> second = {0};
    while (in.read((char *)&second[0], 44100)) {
        stream.push_back(second);
    }
}