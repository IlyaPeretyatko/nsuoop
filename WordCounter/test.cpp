#include "WordCounter.h"
#include "gtest/gtest.h"

TEST(task1, countWords) {
    WordCounter example;
    std::stringstream inputTestStroke, outTestStroke;
    inputTestStroke << "hello , world,world! hello";
    example.parser(inputTestStroke);
    example.output(outTestStroke);
    EXPECT_EQ(outTestStroke.str(), "hello - 2 - 50\nworld - 2 - 50\n");
}