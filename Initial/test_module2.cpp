#include "module2.h"
#include "gtest/gtest.h"

namespace {

TEST(Test, GetNameJames) {
    using Module2::getMyName;

    EXPECT_EQ(getMyName(), "James");
}

}