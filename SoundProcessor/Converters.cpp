#include "Converters.h"

void Mute::setArg(const std::string &start_, const std::string &end_) {
  this->start = stoi(start_);
  this->end = stoi(end_);
}

void Mute::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
  if (start >= end || start < 1 || end > (int)stream.size()) {
    throw std::length_error("Incorrect interval of time (Mute)");
  }
  for (int i = start; i <= end; ++i) {
    stream[i - 1].fill(0);
  }
}

void Mix::setArg(const std::string &file_, const std::string &start_) {
  this->file = file_;
  this->start = stoi(start_);
}

void Mix::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
  std::ifstream fin;
  fin.open(this->file, std::ios_base::binary);
  if (!fin.good()) {
    throw std::length_error("Other file not open. (Mix)");
  }
  WAV otherFile(fin);
  otherFile.readStream(fin);
  std::vector<std::array<int16_t, 44100>> & otherStream = otherFile.getStream();
  fin.close();
  if (start >= (int)stream.size() || start < 1) {
    throw std::length_error("Incorrect interval of time (Mix)");
  }
  int end;
  if (otherStream.size() < stream.size()) {
    end = otherStream.size();
  } else {
    end = stream.size();
  }
  for (int i = start; i <= end; ++i) {
    for (int j = 0; j < 44100; ++j) {
      stream[i - 1][j] = (stream[i - 1][j] / 2) + (otherStream[i - 1][j] / 2);
    }
  }
}
