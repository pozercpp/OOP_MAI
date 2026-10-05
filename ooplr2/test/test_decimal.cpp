#include "decimal.h"
#include <gtest/gtest.h>

TEST(DecimalConstructorTest, UnsignedIntConstructor) {
  Decimal d(123ull);
  EXPECT_TRUE(Decimal::equals(d, Decimal({1, 2, 3})));
}

TEST(DecimalConstructorTest, InitializerListConstructor) {
    Decimal d({9, 9, 9, 9});
    EXPECT_TRUE(Decimal::equals(d, Decimal(9999ull)));
}

TEST(DecimalArithmeticTest, SubtractionNegativeResult) {
    Decimal d1(5ull);
    Decimal d2(10ull);
    Decimal res = Decimal::sub(d1, d2);
    EXPECT_TRUE(Decimal::equals(res, Decimal(0ull)));
}

TEST(DecimalArithmeticTest, SubtractionPositiveResult) {
    Decimal d1(10ull);
    Decimal d2(5ull);
    Decimal res = Decimal::sub(d1, d2);
    EXPECT_TRUE(Decimal::equals(res, Decimal(5ull)));
}

TEST(DecimalArithmeticTest, AdditionCheck) {
    Decimal d1(1000ull);
    Decimal d2(123ull);
    Decimal res = Decimal::plus(d1, d2);
    EXPECT_TRUE(Decimal::equals(res, Decimal(1123ull)));
}

TEST(DecimalComparisonTest, Comparisons) {
    Decimal zero(0ull);
    Decimal one(1ull);
    
    EXPECT_TRUE(Decimal::equals(zero, zero));
    EXPECT_TRUE(Decimal::less(zero, one));
    EXPECT_TRUE(Decimal::greater(one, zero));
    EXPECT_TRUE(Decimal::equalsless(zero, one));
    EXPECT_TRUE(Decimal::equalsgreater(one, zero));
}

TEST(DecimalCopyTest, CopyConstructor) {
    Decimal original({1, 2, 3, 4, 5});
    Decimal copy(original);
    
    EXPECT_TRUE(Decimal::equals(copy, original));
    EXPECT_TRUE(Decimal::equals(original, Decimal(12345ull)));
}