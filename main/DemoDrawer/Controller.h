//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H
#define GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H

#include "Demos/PlainBezierCurveDemo/Demo.h"

class Controller
{
protected:
    SDL_Renderer *m_renderer;
    std::vector<SDL_Event*> events;
    DemoInterface *demo;
public:
    Controller(SDL_Renderer *renderer):
        m_renderer(renderer),
        demo(new PlainBezierCurve::Demo(renderer, &events))
    {
        demo->setupRenderer();
    }
    ~Controller();

    void addEvent(SDL_Event *sdlEvent);
    void processEvents();
    void draw();
};


#endif //GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H
