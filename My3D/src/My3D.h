#ifndef GAMEDEVMATHPROBLEMS_MY2D_H
#define GAMEDEVMATHPROBLEMS_MY2D_H

#include <array>

typedef std::array<double, 3> point3d;
typedef std::array<double, 3> vector3d;
typedef std::array<point3d, 3> vectorp3d;

class My3D
{
public:
    static double calcDistance(point3d p1, point3d p2);
};

#endif //GAMEDEVMATHPROBLEMS_MY2D_H
