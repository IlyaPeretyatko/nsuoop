#include "Converters.h"

void Mute::setArg(const std::vector<std::string> args) {
  this->start = stoi(args[0]);
  this->end = stoi(args[1]);
  if (start >= end || start < 1) {
    throw std::length_error("Incorrect interval of time (Mute)");
  }
}

void Mute::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
  if (end > (int)stream.size()) {
    throw std::length_error("Count second in file less then end of time interval. (Mute)");
  }
  for (int i = start; i <= end; ++i) {
    stream[i].fill(0);
  }
}

void Mix::setArg(const std::vector<std::string> args) {
  this->file = args[0];
  this->start = stoi(args[1]);
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
    throw std::length_error("Incorrect interval of time. (Mix)");
  }
  int end;
  if (otherStream.size() < stream.size()) {
    end = otherStream.size();
  } else {
    end = stream.size();
  }
  for (int i = start; i <= end; ++i) {
    for (int j = 0; j < 44100; ++j) {
      stream[i][j] = (stream[i][j] / 2) + (otherStream[i][j] / 2);
    }
  }
}

void Boost::setArg(const std::vector<std::string> args) {
  this->start = stoi(args[0]);
  this->end = stoi(args[1]);
  this->koef = stoi(args[2]);
  if (koef < 2 || koef > 10) {
    throw std::length_error("Coefficient boost should be from 2 to 10. (Boost)");
  }
  if (start >= end || start < 1) {
    throw std::length_error("Incorrect interval of time. (Boost)");
  }
}

void Boost::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
  if (end > (int)stream.size()) {
    throw std::length_error("Count second in file less then end of time interval. (Boost)");
  }
  for (int i = start; i <= end; ++i) {
    for (int j = 0; j < 44100; ++j) {
      int tmp = stream[i][j];
      tmp *= koef;
      if (tmp > SHRT_MAX) {
        stream[i][j] = SHRT_MAX;
      } else if (tmp < SHRT_MIN) {
        stream[i][j] = SHRT_MIN;
      } else {
        stream[i][j] *= koef;
      }
    }
  }
}
