//
// Created by mvlabat on 4/10/16.
//

#include "Demo.h"

void PlainBezierCurve::Demo::calculateTPeriod()
{
    tPeriod = 0;
    ulong pCount = points.size();
    ulong i;
    for (i = 0; i < pCount - 1; ++i) {
        tPeriod += My2D::calcDistance(points[i], points[i + 1]);
    }
    tPeriod = 1 / tPeriod;
}

void PlainBezierCurve::Demo::setupRenderer()
{
    points.push_back({ 30, 30 });
    points.push_back({ 300, 200 });
    points.push_back({ 60, 250 });

    calculateCurve();
}

void PlainBezierCurve::Demo::calculateCurve()
{
    pixels.clear();

    if (!points.size()) {
        return;
    }

    //calculateTPeriod();

    ulong pixelsCount = (ulong)(1 / tPeriod) + 1;
    pixels.reserve(pixelsCount);

    pixels.push_back(points[0]);
    for (double i = tPeriod; i < 1; i += tPeriod) {
        pixels.push_back(My2D::calcPlainBezierCurvePoint(points, i));
    }
    pixels.push_back(points[points.size() - 1]);
}

void PlainBezierCurve::Demo::setRect(SDL_Rect *sdlRect, point2d center) {
    sdlRect->x = (int)center[0] - POINT_RADIUS;
    sdlRect->y = (int)center[1] - POINT_RADIUS;
    sdlRect->w = POINT_RADIUS * 2;
    sdlRect->h = POINT_RADIUS * 2;
}

void PlainBezierCurve::Demo::draw()
{
    ulong pointsCount = points.size();

    if (!pointsCount--)
        return;

    SDL_SetRenderDrawColor(m_renderer, 120, 120, 120, 1);
    SDL_Rect sdlRect;
    for (ulong i = 0; i < pointsCount; ++i) {
        setRect(&sdlRect, points[i]);
        SDL_RenderDrawRect(m_renderer, &sdlRect);
        SDL_RenderDrawLine(m_renderer, (int)points[i][0], (int)points[i][1], (int)points[i + 1][0], (int)points[i + 1][1]);
    }
    setRect(&sdlRect, points[pointsCount]);
    SDL_RenderDrawRect(m_renderer, &sdlRect);

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 1);
    for (point2d p : pixels) {
        SDL_RenderDrawPoint(m_renderer, (int)p[0], (int)p[1]);
    }
}

void PlainBezierCurve::Demo::processEvents()
{
    processor.init();
    for (SDL_Event* sdlEvent : *m_events) {
        processor.processEvent(sdlEvent);
    }
    processor.doAction();
    if (processor.curveIsActual()) {
        calculateCurve();
    }
}
