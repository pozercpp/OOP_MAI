#include <gtest/gtest.h>
#include <vectorpoints.h>
#include <vectorfigure.h>
#include <point.h>
#include <triangle.h>
#include<square.h>

TEST(VectorPointsTest, AddAndGetPoints) {
    Vectorpoints vp;
    Point p1(1, 2);
    Point p2(3, 4);
    vp.push(p1);
    vp.push(p2);
    EXPECT_EQ(vp.len(), 2);
    EXPECT_TRUE(vp.get(0) == p1);
    EXPECT_TRUE(vp.get(1) == p2);
}

TEST(VectorFigureTest, AddAndTotalArea) {
    Vectorfigure vf;
    Square square;
    Triangle triangle(Point(0,0), Point(3,0), Point(0,4));
    vf.push(&square);
    vf.push(&triangle);
    EXPECT_EQ(vf.len(), 2);
}