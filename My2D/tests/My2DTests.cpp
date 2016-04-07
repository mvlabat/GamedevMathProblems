#include <cmath>

#include "gtest/gtest.h"
#include "../src/My2D.h"

double epsilon(ushort power = 1000) {
    return std::pow(1, -power);
}

std::string point2d_to_string(point2d point) {
    std::stringstream output;
    output << "( " << point[0] << "; " << point[1] << " )";
    return output.str();
}

bool expect_double_arrays_eq(std::array<double, 2> expected, std::array<double, 2> actual) {
    ulong length1 = expected.size();
    ulong length2 = actual.size();

    if (length1 != length2) return false;

    for (long i = 0; i < length1; ++i) {
        if (expected[i] - actual[i] > epsilon()) return false;
    }

    return true;
}

TEST(My2DTests, test_calcDistance) {
    EXPECT_DOUBLE_EQ(1, My2D::calcDistance( { 1, 1 }, { 1, 2 } ));
}

TEST(My2DTests, test_calcVectorCoords_vp) {
    vector2d expected_vector = { 2, 4.5 };
    vector2d actual_vector = My2D::calcVectorCoords( {{ { 2, 9 }, { 0, 4.5 } }} );

    EXPECT_EQ(true, expect_double_arrays_eq(expected_vector, actual_vector))
                    << "Actual vector: "
                        << point2d_to_string(actual_vector)
                        << "\nExpected vector: "
                        << point2d_to_string(expected_vector);
}

TEST(My2DTests, test_calcVectorCoords) {
    vector2d expected_vector = { 2, 4.5 };
    vector2d actual_vector = My2D::calcVectorCoords( { 2, 9 }, { 0, 4.5 } );

    EXPECT_EQ(true, expect_double_arrays_eq(expected_vector, actual_vector))
                    << "Actual vector: "
                    << point2d_to_string(actual_vector)
                    << "\nExpected vector: "
                    << point2d_to_string(expected_vector);
}

TEST(My2DTests, test_calcVectorsAngle) {
    double expected_angle = 90;
    vectorp2d v1 = {{ { 2, 3 }, { 5, 3 } }};
    vectorp2d v2 = {{ { 2, 3 }, { 2, 6 } }};
    double actual_angle = My2D::calcVectorsAngle(v1, v2) * 180 / std::acos(-1);
    EXPECT_DOUBLE_EQ(expected_angle, actual_angle);
}
