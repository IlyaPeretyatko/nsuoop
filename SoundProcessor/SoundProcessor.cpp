#include "SoundProcessor.h"


void SoundProcessor::launch(int argc, char **argv) {
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

  std::vector<std::string> converters = instruction.getConverters();
  std::vector<std::string> arguments = instruction.getArguments();
  for (int i = 0; i < (int)converters.size(); ++i) {
    if (converters[i] == "mute") {
      CreatorMute creatorMuteObject;
      Converter * muteObject = creatorMuteObject.createConverter();
      muteObject->setArg(arguments[i * 2], arguments[i * 2 + 1]);
      muteObject->converting(fileWAV.getStream());
    } else if (converters[i] == "mix") {
      CreatorMix creatorMixObject;
      Converter * mixObject = creatorMixObject.createConverter();
      mixObject->setArg(inputFiles[stoi(arguments[i * 2]) - 1], arguments[i * 2 + 1]);
      mixObject->converting(fileWAV.getStream());
    } else if (converters[i] == "boost") {
      CreatorBassBoost creatorBoostObject;
      Converter * boostObject = creatorBoostObject.createConverter();
      boostObject->setArg(arguments[i * 2], arguments[i * 2 + 1]);
      boostObject->converting(fileWAV.getStream());
    }
  }

  std::ofstream fout;
  fout.open(settings.getOutputFile(), std::ios_base::binary);
  if (!fout.is_open()) {
    throw std::length_error("File not open.");
  }
  fileWAV.writeHeader(fout);
  fileWAV.writeStream(fout);
  fout.close();
}
