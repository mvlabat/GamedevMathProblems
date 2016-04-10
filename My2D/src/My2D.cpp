//
// Created by mvlabat on 4/6/16.
//

#include "My2D.h"

#include <cmath>

double My2D::epsilon(ushort power) {
    return std::pow(1, -power);
}

double My2D::calcDistance(point2d p1, point2d p2)
{
    return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2));
}

vector2d My2D::calcVectorCoords(vectorp2d vector)
{
    return { vector[0][0] - vector[1][0], vector[0][1] - vector[1][1] };
}

vector2d My2D::calcVectorCoords(point2d p1, point2d p2)
{
    return { p1[0] - p2[0], p1[1] - p2[1] };
}

double My2D::calcVectorsAngle(vectorp2d vp1, vectorp2d vp2)
{
    vector2d v1 = calcVectorCoords(vp1);
    vector2d v2 = calcVectorCoords(vp2);
    return calcVectorsAngle(v1, v2);
}

double My2D::calcVectorsAngle(vector2d v1, vector2d v2)
{
    return std::acos( (v1[0] * v2[0] + v1[1] * v2[1]) / calcDistance(v1, { 0, 0 }) / calcDistance(v2, { 0, 0 }));
}

bool My2D::isWithingRectangular(point2d point, point2d r1, point2d r2)
{
    double minX;
    double maxX;
    double minY;
    double maxY;

    // Fix received coordinates.
    if (r1[0] < r2[0]) {
        minX = r1[0];
        maxX = r2[0];
    }
    else {
        minX = r2[0];
        maxX = r1[0];
    }
    if (r1[1] < r2[1]) {
        minY = r1[1];
        maxY = r2[1];
    }
    else {
        minY = r2[1];
        maxY = r1[1];
    }

    return point[0] >= minX && point[1] >= minY && point[0] <= maxX && point[1] <= maxY;
}

point2d My2D::calcPlainBezierCurvePoint(std::vector<point2d> points, double t)
{
    ulong pointsCount = points.size() - 1;
    while (pointsCount > 0) {
        for (ulong i = 0; i < pointsCount; ++i) {
            points[i][0] = points[i][0] * (1 - t) + points[i + 1][0] * t;
            points[i][1] = points[i][1] * (1 - t) + points[i + 1][1] * t;
        }
        pointsCount -= 1;
        points.pop_back();
    }
    return points[0];
}
