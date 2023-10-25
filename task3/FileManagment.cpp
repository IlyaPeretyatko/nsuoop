#include "FileManagment.h"
#include <fstream>

void FileManagment::getUniverseFromFile(std::string nameFile) {
    std::string path = "../examples/";
    path += nameFile;
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::length_error("File Not Open");
    }
    std::string line;
    while(std::getline(file, line, '\n')) {
        if (line[0] == '#' && line[1] == 'N' && line[2] == ' ') {
            for (int i = 3; i < (int)line.size(); ++i) {
                this->name += line[i];
            }
        } else if (line[0] == '#' && line[1] == 'R' && line[2] == ' ') {
            bool readB = true;
            for (int i = 3; i < (int)line.size(); ++i) {
                if (line[i] == 'S') {
                    readB = false;
                } else if (line[i] >= '0' && line[i] <= '9') {
                    if (readB) {
                        this->birth.insert((unsigned char)line[i] - '0');
                    } else {
                        this->survival.insert((unsigned char)line[i] - '0');
                    }
                }
            }
        } else if (line[0] == '#' && line[1] == 'S' && line[2] == ' ') {
            std::string w = "";
            std::string h = "";
            bool readW = true;  
            for (int i = 3; i < (int)line.size(); ++i) {
                if (line[i] == '/') {
                    readW = false;
                } else if (line[i] >= '0' && line[i] <= '9') {
                    if (readW) {
                        w += line[i];
                    } else {
                        h += line[i];
                    }
                }
            }
            this->width = stoi(w);
            this->height = stoi(h);
            allocateMemoryForField();
        } else if (line[0] == '#') {
            continue;
        } else {
            std::string x = "";
            std::string y = "";
            bool readX = true;
            for (int i = 0; i < (int)line.size(); ++i) {
                if (line[i] == ' ') {
                    readX = false;
                    continue;
                }
                if (readX) {
                    x += line[i];
                } else {
                    y += line[i];
                }
            }
            this->field[std::stoi(x)][std::stoi(y)] = 1;
        }
    }
    file.close();
}

void FileManagment::saveToFile(std::string nameFile) {
    std::string path = "../";
    path += nameFile;
    std::ofstream fout(path);
    if (!fout.is_open()) {
        throw std::length_error("File Not Open");
    }
    fout << "#Life 1.06" << std::endl;
    fout << "#N " << this->name << std::endl;
    fout << "#R " << "B";
    for (auto& it: this->birth) {
        fout << it;
    }
    fout << "/S";
    for (auto& it: this->survival) {
        fout << it;
    }
    fout << std::endl << "#S ";
    fout << this->width << "/" << this->height << std::endl;
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (field[i][j]) {
                fout << i << " " << j << std::endl;
            }
        }
    }
    fout.close();
}

void FileManagment::printUniverse() {
    std::cout << "\t" << this->name << std::endl;
    std::cout << "width x height : " << this->width << " x " << this->height << std::endl;
    std::cout << "Birth / Survival : ";
    for (auto& it: this->birth) {
        std::cout << it << " ";
    }
    std::cout << "/ ";
    for (auto& it: this->survival) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < this->width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < this->height; ++i) {
        std::cout << "#";
        for (int j = 0; j < this->width; ++j) {
            if (field[i][j]) {
                std::cout << "@";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "#" << std::endl;
    }
    for (int i = 0; i < this->width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
}