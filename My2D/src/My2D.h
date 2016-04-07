//
// Created by mvlabat on 4/6/16.
//

#ifndef GAMEDEVMATHPROBLEMS_MY2D_H
#define GAMEDEVMATHPROBLEMS_MY2D_H

#include <array>

typedef std::array<double, 2> point2d;
typedef std::array<double, 2> vector2d;
typedef std::array<point2d, 2> vectorp2d;

class My2D
{
public:
    static double calcDistance(point2d p1, point2d p2);
    static vector2d calcVectorCoords(vectorp2d vector);
    static vector2d calcVectorCoords(point2d p1, point2d p2);
    static double calcVectorsAngle(vectorp2d p1, vectorp2d p2);
    static double calcVectorsAngle(vector2d p1, vector2d p2);
};

#endif //GAMEDEVMATHPROBLEMS_MY2D_H
