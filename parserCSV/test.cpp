#include "print_tuple.h"
#include "parser_csv.h"
#include "gtest/gtest.h"



TEST(PrintTuple, empty) {
  auto tuple = std::make_tuple();
  std::stringstream ss;
  ss << tuple;
  EXPECT_EQ(ss.str(), "");
}

TEST(PrintTuple, standart1) {
  auto tuple = std::make_tuple("aboba", 10, 10.5, 'h', 567);
  std::stringstream ss;
  ss << tuple;
  EXPECT_EQ(ss.str(), "aboba, 10, 10.5, h, 567");
}

TEST(PrintTuple, standart2) {
  auto tuple = std::make_tuple(105);
  std::stringstream ss;
  ss << tuple;
  EXPECT_EQ(ss.str(), "105");
}

TEST(PrintTuple, standart3) {
  auto tuple = std::make_tuple(105, 105, 105, 105, 105);
  std::stringstream ss;
  ss << tuple;
  EXPECT_EQ(ss.str(), "105, 105, 105, 105, 105");
}

TEST(PrintTuple, standart4) {
  auto tuple = std::make_tuple("print", "tuple", 105, 105.222, 105.124);
  std::stringstream ss;
  ss << tuple;
  EXPECT_EQ(ss.str(), "print, tuple, 105, 105.222, 105.124");
}

TEST(ParserCSV, standart1) {
  std::ifstream file("../csv_for_tests/test1.csv");
  std::stringstream ss;
  CSVParser<int, double> parser(file, 0);
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "1, 2\n3, 4\n");
}

TEST(ParserCSV, standart2) {
  std::ifstream file("../csv_for_tests/test2.csv");
  std::stringstream ss;
  CSVParser<int, double, std::string> parser(file, 0);
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "1, 2, aboba\n1, 5.5, wowdamn\n");
}

TEST(ParserCSV, standart3) {
  std::ifstream file("../csv_for_tests/test1.csv");
  std::stringstream ss;
  CSVParser<int, double, std::string> parser(file, 2);
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "");
}

TEST(ParserCSV, empty) {
  std::ifstream file("../csv_for_tests/test3.csv");
  std::stringstream ss;
  CSVParser<int, double, std::string> parser(file, 0);
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "");
}

TEST(ParserCSV, improved1) {
  std::ifstream file("../csv_for_tests/test4.csv");
  std::stringstream ss;
  CSVParser<int, std::string, std::string> parser(file, 0, '+', '-', '^');
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "1, \"hahahaha\"bebra, aboba\n1, kek, wow\"damn\"\n");
}

TEST(ParserCSV, improved2) {
  std::ifstream file("../csv_for_tests/test5.csv");
  std::stringstream ss;
  CSVParser<int, std::string, int, int, std::string> parser(file, 0, '\n', ';', '^');
  for (auto line : parser) {
    ss << line << std::endl;
  }
  EXPECT_EQ(ss.str(), "1, tw;o, 3, 4, 5\n6, 7, 8, 9, 10\n");
}