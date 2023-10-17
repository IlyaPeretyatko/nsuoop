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
        char **field;
        void allocateMemoryForField();
    public:
        Life();
        Life(int width, int height, std::string name, std::set<int> survival, std::set<int> birth);
        ~Life();
        char& operator()(int i, int j);
        int getWidth();
        int getHeight();
        std::string getName();
        void newGeneration();    
};


#endif