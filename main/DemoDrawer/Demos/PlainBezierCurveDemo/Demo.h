//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H
#define GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <vector>
#include "EventProcessor.h"
#include "../DemoInterface.h"
#include "../../../../My2D/src/My2D.h"

using namespace PlainBezierCurveDetails;

namespace PlainBezierCurveDetails {
    const ushort POINT_RADIUS = 5;
}

namespace PlainBezierCurve {
    class Demo : public DemoInterface
    {
    protected:
        EventProcessor processor;
        double tPeriod = 0.0005;
        std::vector<point2d> points;
        std::vector<point2d> pixels;

    public:
        Demo(SDL_Renderer *renderer, std::vector<SDL_Event*> *events): DemoInterface(renderer, events),
                                                                       processor(&points)
        {
        }

        virtual void setupRenderer();
        void calculateCurve();
        void setRect(SDL_Rect *sdlRect, point2d center);
        virtual void draw();
        virtual void processEvents();

    protected:
        void calculateTPeriod();
    };
}


#endif //GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H
