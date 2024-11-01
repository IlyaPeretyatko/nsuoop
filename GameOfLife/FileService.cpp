#include "FileService.h"
#include <fstream>


FileService::FileService(Life * life) {
    this->life = life;
}

void FileService::getCellFromFile(const std::string &line) {
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
    life->addCell(std::stoi(x), std::stoi(y));
}

void FileService::getSizeFromFile(const std::string & line) {
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
    life->setWidth(stoi(w));
    life->setHeight(stoi(h));
}

void FileService::getRuleFromFile(const std::string & line) {
    bool readB = true;
    for (int i = 3; i < (int)line.size(); ++i) {
        if (line[i] == 'S') {
            readB = false;
        } else if (line[i] >= '0' && line[i] <= '9') {
            if (readB) {
                life->addBirth((unsigned char)line[i] - '0');
            } else {
                life->addSurvival((unsigned char)line[i] - '0');
            }
        }
    }
}

void FileService::getUniverseFromFile(const std::string  & path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::length_error("File Not Open");
    }
    std::string line;
    std::string name;
    while(std::getline(file, line, '\n')) {
        if (line[0] == '#' && line[1] == 'N' && line[2] == ' ') {
            for (int i = 3; i < (int)line.size(); ++i) {
                name += line[i];
            }
        } else if (line[0] == '#' && line[1] == 'R' && line[2] == ' ') {
            getRuleFromFile(line);
        } else if (line[0] == '#' && line[1] == 'S' && line[2] == ' ') {
            getSizeFromFile(line);
        } else if (line[0] == '#' || line.empty()) {
            continue;
        } else {
            getCellFromFile(line);
        }
    }
    life->setName(name);
    file.close();
}

void FileService::saveToFile(const std::string & path) const {
    std::ofstream fout(path);
    if (!fout.is_open()) {
        throw std::length_error("File Not Open");
    }
    fout << "#Life 1.06" << std::endl;
    fout << "#N " << life->getName() << std::endl;
    fout << "#R " << "B";
    for (auto& it: life->getBirth()) {
        fout << it;
    }
    fout << "/S";
    for (auto& it: life->getSurvival()) {
        fout << it;
    }
    fout << std::endl << "#S ";
    fout << life->getWidth() << "/" << life->getHeight() << std::endl;
    for (int i = 0; i < life->getHeight(); ++i) {
        for (int j = 0; j < life->getWidth(); ++j) {
            if (life->cellIsExists(i, j)) {
                fout << i << " " << j << std::endl;
            }
        }
    }
    fout.close();
}

void FileService::printUniverse() const {
    int width = life->getWidth();
    int height = life->getHeight();
    std::cout << "\t" << life->getName() << std::endl;
    std::cout << "width x height : " << width << " x " << height << std::endl;
    std::cout << "Birth / Survival : ";
    for (auto& it: life->getBirth()) {
        std::cout << it << " ";
    }
    std::cout << "/ ";
    for (auto& it: life->getSurvival()) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < height; ++i) {
        std::cout << "#";
        for (int j = 0; j < width; ++j) {
            if (life->cellIsExists(i, j)) {
                std::cout << "@";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "#" << std::endl;
    }
    for (int i = 0; i < width + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

