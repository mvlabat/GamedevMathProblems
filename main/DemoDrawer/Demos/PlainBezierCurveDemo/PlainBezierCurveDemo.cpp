//
// Created by mvlabat on 4/10/16.
//

#include "PlainBezierCurveDemo.h"

void PlainBezierCurveDemo::calculateTPeriod()
{
    tPeriod = 0;
    ulong pCount = points.size();
    ulong i;
    for (i = 0; i < pCount - 1; ++i) {
        tPeriod += My2D::calcDistance(points[i], points[i + 1]);
    }
    tPeriod = 1 / tPeriod;
}

void PlainBezierCurveDemo::setupRenderer()
{
    points.push_back({ 30, 30 });
    points.push_back({ 300, 200 });
    points.push_back({ 60, 250 });

    calculateTPeriod();

    calculateCurve();
}

void PlainBezierCurveDemo::calculateCurve()
{
    ulong pixelsCount = (ulong)(1 / tPeriod) + 1;
    pixels.clear();
    pixels.reserve(pixelsCount);

    pixels.push_back(points[0]);
    for (double i = tPeriod; i < 1; i += tPeriod) {
        pixels.push_back(My2D::calcPlainBezierCurvePoint(points, i));
    }
    pixels.push_back(points[points.size()]);
}

void PlainBezierCurveDemo::draw()
{
    for (point2d p : pixels) {
        SDL_RenderDrawPoint(m_renderer, (int)p[0], (int)p[1]);
    }
}
