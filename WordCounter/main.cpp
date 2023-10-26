#include "WordCounter.h"



int main(int argc, char* argv[]) {
    if (argc != 3) return -1;
    std::fstream fileIn, fileOut;
    fileIn.open(argv[1], std::ios::in);
    fileOut.open(argv[2], std::ios::out);
    if ((!fileIn.is_open()) || (!fileOut.is_open())) return -1;

    WordCounter countWords;
    countWords.parser(fileIn);
    countWords.output(fileOut);
    fileIn.close();
    fileOut.close();
    return 0;
}