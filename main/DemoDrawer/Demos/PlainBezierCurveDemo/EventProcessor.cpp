//
// Created by mvlabat on 4/10/16.
//

#include <iostream>
#include "EventProcessor.h"
#include "Demo.h"

void PlainBezierCurveDetails::EventProcessor::init()
{
    m_curveIsActual = true;
    action = &EventProcessor::doNothing;
}

void PlainBezierCurveDetails::EventProcessor::processEvent(SDL_Event *sdlEvent)
{
    switch (sdlEvent->type) {
        case SDL_MOUSEBUTTONDOWN:
            switch (sdlEvent->button.button) {
                case SDL_BUTTON_LEFT:
                    findClickedPoint( { sdlEvent->motion.x, sdlEvent->motion.y } );
                    break;

                case SDL_BUTTON_RIGHT:
                    findClickedPoint( { sdlEvent->motion.x, sdlEvent->motion.y } );
                    break;
            }
            break;

        case SDL_MOUSEMOTION:
            m_mouseCoords = { sdlEvent->motion.x, sdlEvent->motion.y };
            if (m_clickedPoint != nullptr) {
                action = &EventProcessor::movePoint;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            switch (sdlEvent->button.button) {
                case SDL_BUTTON_LEFT:
                    if (m_clickedPoint != nullptr) m_clickedPoint = nullptr;
                    else action = &EventProcessor::addPoint;
                    break;

                case SDL_BUTTON_RIGHT:
                    if (m_clickedPoint != nullptr) {
                        action = &EventProcessor::deletePoint;
                    }
                    break;
            }
            break;
    }
}

void PlainBezierCurveDetails::EventProcessor::doAction()
{
    (*this.*action)();
}

bool PlainBezierCurveDetails::EventProcessor::curveIsActual() const
{
    return m_curveIsActual;
}

bool PlainBezierCurveDetails::EventProcessor::findClickedPoint(std::array<int, 2> point)
{
    for (ulong i = 0; i < m_points->size(); ++i) {
        if (My2D::isWithingRectangular({ point[0], point[1] },
                                       { (*m_points)[i][0] - POINT_RADIUS, (*m_points)[i][1] - POINT_RADIUS },
                                       { (*m_points)[i][0] + POINT_RADIUS, (*m_points)[i][1] + POINT_RADIUS } )
            ) {
            m_clickedPoint = &(*m_points)[i];
            m_clickedPointNumber = i;
            return true;
        }
    }
}

void PlainBezierCurveDetails::EventProcessor::addPoint()
{
    m_curveIsActual = false;
    m_points->push_back({ m_mouseCoords[0], m_mouseCoords[1] });
}

void PlainBezierCurveDetails::EventProcessor::movePoint()
{
    (*m_clickedPoint)[0] = m_mouseCoords[0];
    (*m_clickedPoint)[1] = m_mouseCoords[1];
    m_curveIsActual = false;
}

void PlainBezierCurveDetails::EventProcessor::deletePoint()
{
    m_points->erase(m_points->begin() + m_clickedPointNumber);
    m_clickedPoint = nullptr;
    m_curveIsActual = false;
}
