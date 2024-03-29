#include "WAV.h"

WAV::WAV(std::istream &in) {
  in.read(reinterpret_cast<char *>(&header), sizeof(WAVHeader));
  if (header.audioFormat != 1 || header.numChannels != 1 || header.bitsPerSample != 16) {
    throw std::length_error("Wrong format of wav file.");
  }
}

void WAV::readStream(std::istream &in) {
  std::array<int16_t, 44100> second = {0};
  while (in.read((char *)&second[0], sizeof(second[0]) * second.size())) {
    stream.push_back(second);
  }
  std::array<int16_t, 44100> lastSecond = {0};
  in.readsome((char *)&lastSecond[0], sizeof(lastSecond[0]) * lastSecond.size());
  stream.push_back(lastSecond);

}

void WAV::writeHeader(std::ostream &out) const {
  out.write((const char *)(&header), sizeof(WAVHeader));
}

void WAV::writeStream(std::ostream &out) const {
  for (auto i : this->stream) {
    out.write((const char *)&i[0], sizeof(i[0]) * i.size());
  }
}

std::vector<std::array<int16_t, 44100>> & WAV::getStream() {
  return this->stream;
}