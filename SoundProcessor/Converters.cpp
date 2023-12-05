#include "Converters.h"

void Mute::setTimeInterval(const int &start_, const int &end_) {
  this->start = start_;
  this->end = end_;
}

void Mute::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
  if (start >= end || start <= 1 || end > (int)stream.size()) {
    throw std::length_error("Incorrect interval of time (Mute)");
  }
  for (int i = start; i <= end; ++i) {
    stream[i - 1].fill(0);
  }
}

//void Mix::converting(std::vector<std::array<int16_t, 44100>> & stream) const {
//
//}