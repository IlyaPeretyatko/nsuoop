#include "SoundProcessor.h"

int main(int argc, char **argv) {
  SoundProcessor workingSession;
  workingSession.launch(argc, (const char **)argv);
  return 0;
}