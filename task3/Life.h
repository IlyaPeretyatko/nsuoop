#ifndef LIFE_H_
#define LIFE_H_

#include <iostream>
#include <set>


class Life {
    private:
        int width;
        int height;
        std::string name;
        std::set<int> survival;
        std::set<int> birth;
        unsigned char **field;
        void allocateMemoryForField();
    public:
        Life();
        Life(int width, int height);
        ~Life();
        unsigned char& operator()(int i, int j);
        void newGeneration();
        void getUniverseFromFile(std::string nameFile);
        void saveToFile(std::string nameFile);
};


#endif