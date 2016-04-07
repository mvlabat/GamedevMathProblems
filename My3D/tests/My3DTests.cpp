#include <cmath>

#include "gtest/gtest.h"
#include "../src/My3D.h"

TEST(My3DTests, test_calcDistance) {
    EXPECT_DOUBLE_EQ(5, My3D::calcDistance( { 5, 0, 5 }, { 2, 4, 5 } ));
}
