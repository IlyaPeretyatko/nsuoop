#ifndef CELL_H_
#define CELL_H_

#include <iostream>
#include <set>

class Cell {
    private:
        int x;
        int y;
    public:
        Cell() = default;
        Cell(int x, int y);
        int getX() const;
        int getY() const;
        bool operator<(const Cell &other) const;
};

#endif