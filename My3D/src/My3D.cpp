#include "My3D.h"

#include <cmath>

double My3D::calcDistance(point3d p1, point3d p2)
{
    return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2) + std::pow(p1[2] - p2[2], 2));
}
