#include "SoundProcessor.h"


void SoundProcessor::launch(const int argc, const char **argv) {
  settings.parser(argc, argv);
  instruction.parser(settings.getConfigPath());
  std::vector<std::string> inputFiles = settings.getInputFiles();
  std::ifstream fin;
  fin.open(inputFiles[0], std::ios_base::binary);
  if (!fin.is_open()) {
    throw std::length_error("File not open.");
  }
  WAV fileWAV(fin);
  fileWAV.readStream(fin);
  fin.close();
  startConverters(fileWAV);
  std::ofstream fout;
  fout.open(settings.getOutputFile(), std::ios_base::binary);
  if (!fout.is_open()) {
    throw std::length_error("File not open.");
  }
  fileWAV.writeHeader(fout);
  fileWAV.writeStream(fout);
  fout.close();
}

void SoundProcessor::startConverters(WAV & fileWAV) const {
  std::vector<std::string> inputFiles = settings.getInputFiles();
  std::vector<std::string> converters = instruction.getConverters();
  std::vector<std::string> arguments = instruction.getArguments();
  int j = 0;
  for (int i = 0; i < (int)converters.size(); ++i) {
    std::vector<std::string> params;
    if (converters[i] == "mute") {
      CreatorMute creatorMuteObject;
      Converter * muteObject = creatorMuteObject.createConverter();
      for (int k = 0; k < 2; ++k) {
        params.push_back(arguments[j++]);
      }
      muteObject->setArg(params);
      muteObject->converting(fileWAV.getStream());
    } else if (converters[i] == "mix") {
      CreatorMix creatorMixObject;
      Converter * mixObject = creatorMixObject.createConverter();
      params.push_back(inputFiles[stoi(arguments[j++]) - 1]);
      params.push_back(arguments[j++]);
      mixObject->setArg(params);
      mixObject->converting(fileWAV.getStream());
    } else if (converters[i] == "boost") {
      CreatorBoost creatorBoostObject;
      Converter * boostObject = creatorBoostObject.createConverter();
      for (int k = 0; k < 3; ++k) {
        params.push_back(arguments[j++]);
      }
      boostObject->setArg(params);
      boostObject->converting(fileWAV.getStream());
    }
  }
}