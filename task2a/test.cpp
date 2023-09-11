#include "BitArray.h"
#include "gtest/gtest.h"




TEST(BitArray, constructors) {
    BitArray ar1;
    EXPECT_EQ(ar1.size(), 8);
    EXPECT_EQ(ar1[1], 0);
    EXPECT_EQ(ar1[2], 0);
    EXPECT_EQ(ar1[3], 0);
    EXPECT_EQ(ar1[4], 0);
    EXPECT_EQ(ar1[5], 0);
    EXPECT_EQ(ar1[6], 0);
    EXPECT_EQ(ar1[7], 0);
    EXPECT_EQ(ar1[8], 0);

    BitArray ar2 = BitArray(11, 5);
    EXPECT_EQ(ar2.size(), 11);
    EXPECT_EQ(ar2[1], 0);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 0);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 1);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 1);
    EXPECT_EQ(ar2[9], 0);
    EXPECT_EQ(ar2[10], 0);
    EXPECT_EQ(ar2[11], 0);

    BitArray ar3 = BitArray(ar2);
    EXPECT_EQ(ar3.size(), 11);
    EXPECT_EQ(ar3[1], 0);
    EXPECT_EQ(ar3[2], 0);
    EXPECT_EQ(ar3[3], 0);
    EXPECT_EQ(ar3[4], 0);
    EXPECT_EQ(ar3[5], 0);
    EXPECT_EQ(ar3[6], 1);
    EXPECT_EQ(ar3[7], 0);
    EXPECT_EQ(ar3[8], 1);
    EXPECT_EQ(ar3[9], 0);
    EXPECT_EQ(ar3[10], 0);
    EXPECT_EQ(ar3[11], 0);   
}

TEST(BitArray, resize) {
    BitArray ar = BitArray(11, 5);
    EXPECT_EQ(ar.size(), 11);

    ar.resize(15, 1);
    EXPECT_EQ(ar.size(), 15);
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 1);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 1);
    EXPECT_EQ(ar[9], 0);
    EXPECT_EQ(ar[10], 0);
    EXPECT_EQ(ar[11], 0);
    EXPECT_EQ(ar[12], 1);
    EXPECT_EQ(ar[13], 1);
    EXPECT_EQ(ar[14], 1);   
    EXPECT_EQ(ar[15], 1);

    ar.resize(16, 0);
    EXPECT_EQ(ar.size(), 16);
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 1);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 1);
    EXPECT_EQ(ar[9], 0);
    EXPECT_EQ(ar[10], 0);
    EXPECT_EQ(ar[11], 0);
    EXPECT_EQ(ar[12], 1);
    EXPECT_EQ(ar[13], 1);
    EXPECT_EQ(ar[14], 1);   
    EXPECT_EQ(ar[15], 1);
    EXPECT_EQ(ar[16], 0);

    ar.resize(8, 0);
    EXPECT_EQ(ar.size(), 8);
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 1);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 1);
}

TEST(BitArray, push_back) {
    BitArray ar = BitArray(8, 5);
    EXPECT_EQ(ar.size(), 8);
    ar.push_back(1);
    EXPECT_EQ(ar.size(), 9);
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 1);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 1);
    EXPECT_EQ(ar[9], 1);
    ar.push_back(0);
    EXPECT_EQ(ar.size(), 10);
    EXPECT_EQ(ar[10], 0);   
}

TEST(BitArray, clear) {
    BitArray ar = BitArray(8, 123);
    EXPECT_EQ(ar.size(), 8);
    ar.clear();
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0); 
}

TEST(BitArray, equating) {
    BitArray ar1 = BitArray(15, 5);
    BitArray ar2;
    ar2 = ar1;
    EXPECT_EQ(ar2.size(), 15);
    EXPECT_EQ(ar2[1], 0);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 0);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 1);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 1); 
}

TEST(BitArray, swap) {
    BitArray ar1 = BitArray(15, 5);
    BitArray ar2;
    ar1.swap(ar2);

    EXPECT_EQ(ar1.size(), 8);
    EXPECT_EQ(ar2.size(), 15);

    EXPECT_EQ(ar1[1], 0);
    EXPECT_EQ(ar1[2], 0);
    EXPECT_EQ(ar1[3], 0);
    EXPECT_EQ(ar1[4], 0);
    EXPECT_EQ(ar1[5], 0);
    EXPECT_EQ(ar1[6], 0);
    EXPECT_EQ(ar1[7], 0);
    EXPECT_EQ(ar1[8], 0);

    EXPECT_EQ(ar2[1], 0);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 0);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 1);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 1); 
}