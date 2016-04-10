//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_COMMANDS_H
#define GAMEDEVMATHPROBLEMS_COMMANDS_H

#include <vector>
#include "SDL2/SDL_events.h"
#include "../../../../My2D/src/My2D.h"

namespace PlainBezierCurveDetails {
    class EventProcessor
    {
    protected:
        bool m_curveIsActual;
        std::vector<point2d> *m_points;
        std::array<int, 2> m_mouseCoords;
        std::array<int, 2> m_prevMouseCoords;
        point2d *m_clickedPoint = nullptr;
        ulong m_clickedPointNumber;
        void (EventProcessor::*action)();

    public:
        EventProcessor(std::vector<point2d> *points) :
            m_points(points)
        {
        }

        void init();
        void processEvent(SDL_Event *sdlEvent);
        void doAction();
        bool curveIsActual() const;

    protected:
        void doNothing() {}
        bool findClickedPoint(std::array<int, 2> point);
        void addPoint();
        void movePoint();
        void deletePoint();
    };
}

#endif //GAMEDEVMATHPROBLEMS_COMMANDS_H
