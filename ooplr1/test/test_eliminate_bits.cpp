#include "eliminate_unset_bits.h"
#include <gtest/gtest.h>

TEST(EliminateUnsetBitsTest, BasicTest) {
    std::string number = "110";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 3);
    EXPECT_EQ(number, "11");
}

TEST(EliminateUnsetBitsTest, AllOnes) {
    std::string number = "111";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 7);
    EXPECT_EQ(number, "111");
}

TEST(EliminateUnsetBitsTest, AllZeros) {
    std::string number = "000";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 0);
    EXPECT_EQ(number, "");
}

TEST(EliminateUnsetBitsTest, MixedBits) {
    std::string number = "101010";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 7);
    EXPECT_EQ(number, "111");
}

TEST(EliminateUnsetBitsTest, LongString) {
    std::string number = "1001001001";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 15);
    EXPECT_EQ(number, "1111");
}

TEST(EliminateUnsetBitsTest, SingleOne) {
    std::string number = "1";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 1);
    EXPECT_EQ(number, "1");
}

TEST(EliminateUnsetBitsTest, SingleZero) {
    std::string number = "0";
    long res = eliminate_unset_bits(number);
    EXPECT_EQ(res, 0);
    EXPECT_EQ(number, "");
}