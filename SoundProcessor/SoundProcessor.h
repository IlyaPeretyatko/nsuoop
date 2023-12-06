#pragma once

#include "CommandParser.h"
#include "ConfigParser.h"
#include "Converters.h"
#include "WAV.h"
#include <iostream>
#include <vector>
#include <array>

class SoundProcessor {
private:
  CommandParser settings;
  ConfigParser instruction;

  void startConverters(WAV fileWAV) const;
public:
  SoundProcessor() = default;
  void launch(const int argc, const char **argv);
};