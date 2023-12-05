#pragma once

#include <iostream>
#include <vector>
#include <array>

class Converter {
public:
  virtual ~Converter(){}
  virtual void setTimeInterval(const int &start_, const int &end_) = 0;
  virtual void converting(std::vector<std::array<int16_t, 44100>> & stream) const = 0;
};

class Mute : public Converter {
private:
  int start;
  int end;
public:
  void setTimeInterval(const int &start_, const int &end_);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

//class Mix : public Converter {
//public:
//  Mix() = default;
//  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
//};

class Creator {
public:
  virtual Converter *createConverter() = 0;
};

class CreatorMute : Creator {
public:
  CreatorMute() = default;
  Converter *createConverter() { return new Mute(); }
};

//class CreatorMix : Creator {
//public:
//  Converter *createConverter() { return new Mix(); }
//};