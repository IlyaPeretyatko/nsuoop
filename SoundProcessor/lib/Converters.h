#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <limits.h>
#include "WAV.h"

class Converter {
public:
  virtual ~Converter(){}
  virtual void setArg(const std::vector<std::string> args) = 0;
  virtual void converting(std::vector<std::array<int16_t, 44100>> & stream) const = 0;
};

class Mute : public Converter {
private:
  int start;
  int end;
public:
  Mute() = default;
  void setArg(const std::vector<std::string> args);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

class Mix : public Converter {
private:
  std::string file;
  int start;
public:
  Mix() = default;
  void setArg(const std::vector<std::string> args);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

class Boost : public Converter {
private:
  int start;
  int end;
  int koef;
public:
  Boost() = default;
  void setArg(const std::vector<std::string> args);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

class Creator {
public:
  virtual Converter *createConverter() const = 0;
};

class CreatorMute : Creator {
public:
  Converter *createConverter() const { return new Mute(); }
};

class CreatorMix : Creator {
public:
  Converter *createConverter() const { return new Mix(); }
};

class CreatorBoost : Creator {
public:
  Converter *createConverter() const { return new Boost(); }
};