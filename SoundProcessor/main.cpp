#include "CommandParser.h"
#include "ConfigParser.h"
#include "Converters.h"
#include "WAV.h"

int main(int argc, char **argv) {
  CommandParser settings;
  ConfigParser instruction;
  settings.parser(argc, argv);
  instruction.parser(settings.getConfigPath());
  std::ifstream fin;
  fin.open("input1.wav", std::ios_base::binary);
  if (!fin.good()) {
    return 0;
  }
  WAV file1(fin);
  file1.readStream(fin);
  std::ofstream fout;
  fout.open("output.wav", std::ios_base::binary);
  if (!fout.good()) {
    return 0;
  }

  CreatorMix creatorMixObject;
  Converter * mixObject = creatorMixObject.createConverter();
  mixObject->setArg("input2.wav", "2");
  mixObject->converting(file1.getStream());

  file1.writeHeader(fout);
  file1.writeStream(fout);
  fout.close();
  fin.close();
  return 0;
}