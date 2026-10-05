#include <gtest/gtest.h>
#include <point.h>
#include <triangle.h>
#include <square.h>
#include <octagon.h>

TEST(TriangleTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    Triangle triangle(p1, p2, p3);
    EXPECT_NEAR(static_cast<double>(triangle.Area()), 6.0, 1e-10);
}

TEST(SquareTest, AreaCalculation) {
    Point p1(1, 1);
    Point p2(1, 2);
    Point p3(2, 2);
    Point p4(2, 1);
    Square square(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(square.Area()), 1.0, 1e-10);
}