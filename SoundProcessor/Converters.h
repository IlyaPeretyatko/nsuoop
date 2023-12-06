#pragma once

#include <iostream>
#include <vector>
#include <array>
#include "WAV.h"

class Converter {
public:
  virtual ~Converter(){}
  virtual void setArg(const std::string &arg1, const std::string &arg2) = 0;
  virtual void converting(std::vector<std::array<int16_t, 44100>> & stream) const = 0;
};

class Mute : public Converter {
private:
  int start;
  int end;
public:
  Mute() = default;
  void setArg(const std::string &start_, const std::string &end_);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

class Mix : public Converter {
private:
  std::string file;
  int start;
public:
  Mix() = default;
  void setArg(const std::string &file_, const std::string &start_);
  void converting(std::vector<std::array<int16_t, 44100>> & stream) const;
};

class BassBoost : public Converter {
private:
  int start;
  int end;
public:
  BassBoost() = default;
  void setArg(const std::string &start_, const std::string &end_);
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

class CreatorBassBoost : Creator {
public:
  Converter *createConverter() const { return new BassBoost(); }
};