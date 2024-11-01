#include "Cell.h"

Cell::Cell(int x, int y) : x(x), y(y) {}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }