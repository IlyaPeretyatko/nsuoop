#ifndef LIFE_H_
#define LIFE_H_

#include <iostream>
#include <set>
#include <vector>

class Cell {
    private:
        int x;
        int y;
    public:
        Cell() = default;
        Cell(int x, int y);
        int getX();
        int getY();
        bool operator<(const Cell &other) const;
};

class Life {
    protected:
        int width;
        int height;
        std::string name;
        std::set<int> survival;
        std::set<int> birth;
        std::set<Cell> livingCells;

        int checkNeighbours(int i, int j, int x, int y);
        bool operator()(int i, int j);
    public:
        Life() = default;
        void newGeneration();
};


#endif