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
public:
  SoundProcessor() = default;
  void launch(int argc, char **argv);
};