#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

template <typename... Args> class CSVParser {
public:
  class Iterator;

  CSVParser(std::ifstream &file, size_t countLineSkip, char rowSeparator = '\n',
            char columnSeparator = ',', char escapeSeparator = '\"')
      : file_(file), countLineSkip_(countLineSkip), rowSeparator_(rowSeparator),
        columnSeparator_(columnSeparator), escapeSeparator_(escapeSeparator) {
    if (!file.is_open()) {
      // error
    }
    currentLine_ = 0;
    std::string lineSkip;
    for (size_t i = 0; i < countLineSkip_; ++i) {
      std::getline(file_, lineSkip, rowSeparator_);
    }
  }

private:
  std::ifstream &file_;
  size_t countLineSkip_;
  char rowSeparator_;
  char columnSeparator_;
  char escapeSeparator_;
  size_t currentLine_;

  std::string getLine() {
    std::string line;
    getline(file_, line, rowSeparator_);
    currentLine_++;
    return line;
  }

  std::vector<std::string> getTupleOfLine(std::string &line) {
    std::vector<std::string> tupleVector;
    std::stringstream str(line);
    std::string substr;
    while (std::getline(str, substr, columnSeparator_)) {
      tupleVector.push_back(substr);
    }
    if (tupleVector.size() != sizeof...(Args)) {
      // error
    }
    return tupleVector;
  }
};

template <typename... Args> class CSVParser<Args...>::Iterator {
public:
  std::tuple<Args...> &operator*() const { return *iter; }

  bool operator==(const Iterator &other) const { return (iter == other.iter); }

  bool operator!=(const Iterator &other) const { return (iter != other.iter); }

private:
  CSVParser<Args...> &father;
  std::shared_ptr<std::tuple<Args...>> iter;

  void nextLine() {
    std::string line = father.getLine();
    if (line.empty()) {
      iter = nullptr;
    } else {
      iter = std::make_shared<std::tuple<Args...>>(MakeTuple(father.getTupleOfLine(line)));
    }
  }
};

template <typename T> T convert(const std::string str) {
  std::istringstream iss(str);
  T value;

  iss >> value;
  return value;
}

template <typename ...Args, size_t ...Iters>
std::tuple<Args...> makeTupleHelper(std::vector<std::string> params, std::index_sequence<Iters...>) {
  return make_tuple(convert<Args>(params[Iters])...);
}

template <typename ...Args>
std::tuple<Args...> makeTuple(std::vector<std::string> params) {
  return makeTupleHelper<Args...>(params, std::index_sequence_for<Args...>{});
}