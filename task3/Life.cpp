#include "Life.h"

Life::Life() : width(0), height(0), name("") {
    field = nullptr;
}

Life::Life(int width, int height) : width(width), height(height) {
    allocateMemoryForField();
}

void Life::allocateMemoryForField() {
    field = new unsigned char*[this->height];
    if (field == nullptr) {
        throw std::length_error("Allocate Memory Error");
    }
    for (int i = 0; i < this->height; ++i) {
        field[i] = new unsigned char[this->width];
        if (field[i] == nullptr) {
            throw std::length_error("Allocate Memory Error");
        }
        for (int j = 0; j < this->width; ++j) {
            field[i][j] = 0;
        }
  }
}

Life::~Life() {
    if (field != nullptr) {
        for (int i = 0; i < this->height; ++i) {
            if (field[i] != nullptr) {
                delete[] field[i];
            } else {
                break;
            }
        }
    delete[] field;
  }
}

unsigned char& Life::operator()(int i, int j) {
  if (i >= this->height || j >= this->width) {
        throw std::length_error("Wrong Index");
  }
  return field[i][j];
}


void Life::newGeneration() {
    Life nextGeneration(this->width, this->height);
    int countOfNeighbours = 0;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            countOfNeighbours += field[(i + 1 + this->height) % this->height][(j - 1 + this->width) % this->width];
            countOfNeighbours += field[(i + 1 + this->height) % this->height][(j + 1 + this->width) % this->width];
            countOfNeighbours += field[(i - 1 + this->height) % this->height][(j - 1 + this->width) % this->width];
            countOfNeighbours += field[(i - 1 + this->height) % this->height][(j + 1 + this->width) % this->width];
            countOfNeighbours += field[(i + 1 + this->height) % this->height][j];
            countOfNeighbours += field[i][(j + 1 + this->width) % this->width];
            countOfNeighbours += field[(i - 1 + this->height) % this->height][j];
            countOfNeighbours += field[i][(j - 1 + this->width) % this->width];
            if ((*this)(i, j) == 1) {
                if ((this->survival).count(countOfNeighbours) != 0) {
                    nextGeneration(i, j) = 1;
                } else {
                    nextGeneration(i, j) = 0;
                }
            } else {
                if ((this->birth).count(countOfNeighbours) != 0) {
                    nextGeneration(i, j) = 1;
                }
            }
            countOfNeighbours = 0;
        }
    }
    for (int i = 0; i < this->height; ++i) {
        std::copy(nextGeneration.field[i], nextGeneration.field[i] + nextGeneration.width, field[i]);
    }
}
