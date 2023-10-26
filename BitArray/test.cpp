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
    EXPECT_EQ(ar2[1], 1);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 1);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 0);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 0);
    EXPECT_EQ(ar2[9], 0);
    EXPECT_EQ(ar2[10], 0);
    EXPECT_EQ(ar2[11], 0);

    BitArray ar3 = BitArray(ar2);
    EXPECT_EQ(ar3.size(), 11);
    EXPECT_EQ(ar3[1], 1);
    EXPECT_EQ(ar3[2], 0);
    EXPECT_EQ(ar3[3], 1);
    EXPECT_EQ(ar3[4], 0);
    EXPECT_EQ(ar3[5], 0);
    EXPECT_EQ(ar3[6], 0);
    EXPECT_EQ(ar3[7], 0);
    EXPECT_EQ(ar3[8], 0);
    EXPECT_EQ(ar3[9], 0);
    EXPECT_EQ(ar3[10], 0);
    EXPECT_EQ(ar3[11], 0);   
}

TEST(BitArray, resize) {
    BitArray ar = BitArray(11, 5);
    EXPECT_EQ(ar.size(), 11);

    ar.resize(15, 1);
    EXPECT_EQ(ar.size(), 15);
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 1);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
    EXPECT_EQ(ar[9], 0);
    EXPECT_EQ(ar[10], 0);
    EXPECT_EQ(ar[11], 0);
    EXPECT_EQ(ar[12], 1);
    EXPECT_EQ(ar[13], 1);
    EXPECT_EQ(ar[14], 1);   
    EXPECT_EQ(ar[15], 1);

    ar.resize(16, 0);
    EXPECT_EQ(ar.size(), 16);
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 1);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
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
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 1);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
}

TEST(BitArray, push_back) {
    BitArray ar = BitArray(8, 5);
    EXPECT_EQ(ar.size(), 8);
    ar.push_back(1);
    EXPECT_EQ(ar.size(), 9);
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 1);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
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
    EXPECT_EQ(ar2[1], 1);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 1);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 0);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 0); 
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

    EXPECT_EQ(ar2[1], 1);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 1);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 0);
    EXPECT_EQ(ar2[6], 0);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 0); 
}

TEST(BitArray, shift) {
    BitArray ar;
    ar.set(2, 1);
    ar.set(5, 1);
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 1);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 1);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
    ar >>= 3;
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 1);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 1);
    ar <<= 7;
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
}

TEST(BitArray, SetAndReset) {
    BitArray ar = BitArray(12, 8);
    ar.set();
    EXPECT_EQ(ar[1], 1);
    EXPECT_EQ(ar[2], 1);
    EXPECT_EQ(ar[3], 1);
    EXPECT_EQ(ar[4], 1);
    EXPECT_EQ(ar[5], 1);
    EXPECT_EQ(ar[6], 1);
    EXPECT_EQ(ar[7], 1);
    EXPECT_EQ(ar[8], 1);
    EXPECT_EQ(ar[9], 1);
    EXPECT_EQ(ar[10], 1);
    EXPECT_EQ(ar[11], 1);
    EXPECT_EQ(ar[12], 1);
    ar.reset();
    EXPECT_EQ(ar[1], 0);
    EXPECT_EQ(ar[2], 0);
    EXPECT_EQ(ar[3], 0);
    EXPECT_EQ(ar[4], 0);
    EXPECT_EQ(ar[5], 0);
    EXPECT_EQ(ar[6], 0);
    EXPECT_EQ(ar[7], 0);
    EXPECT_EQ(ar[8], 0);
    EXPECT_EQ(ar[9], 0);
    EXPECT_EQ(ar[10], 0);
    EXPECT_EQ(ar[11], 0);
    EXPECT_EQ(ar[12], 0);
}

TEST(BitArray, any) {
    BitArray ar;
    EXPECT_EQ(ar.any(), false);
    ar.set(1, 1);
    EXPECT_EQ(ar.any(), true);
}

TEST(BitArray, none) {
    BitArray ar;
    EXPECT_EQ(ar.none(), true);
    ar.set(1, 1);
    EXPECT_EQ(ar.none(), false);
}

TEST(BitArray, inversion) {
    BitArray ar1;
    BitArray ar2;
    ar2.set(5,1);
    ar1 = ~ar2;
    EXPECT_EQ(ar1[1], 1);
    EXPECT_EQ(ar1[2], 1);
    EXPECT_EQ(ar1[3], 1);
    EXPECT_EQ(ar1[4], 1);
    EXPECT_EQ(ar1[5], 0);
    EXPECT_EQ(ar1[6], 1);
    EXPECT_EQ(ar1[7], 1);
    EXPECT_EQ(ar1[8], 1);
    EXPECT_EQ(ar2[1], 0);
    EXPECT_EQ(ar2[2], 0);
    EXPECT_EQ(ar2[3], 0);
    EXPECT_EQ(ar2[4], 0);
    EXPECT_EQ(ar2[5], 1);
    EXPECT_EQ(ar2[6], 0);
    EXPECT_EQ(ar2[7], 0);
    EXPECT_EQ(ar2[8], 0);   
}

TEST(BitArray, ToString) {
    BitArray ar = BitArray(12, 8);
    EXPECT_EQ(ar.toString(), "000100000000");
    ar.resize(5);
    ar.set(1,1);
    ar.set(2,1);
    ar.set(3,1);
    EXPECT_EQ(ar.toString(), "11110");
}