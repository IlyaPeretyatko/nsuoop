#include "module1.h"
#include "gtest/gtest.h"

namespace {

TEST(Test, GetNameJohn) {
    using Module1::getMyName;

    EXPECT_EQ(getMyName(), "John");
}

}