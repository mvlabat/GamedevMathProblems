//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H
#define GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H

#include "Demos/PlainBezierCurveDemo/PlainBezierCurveDemo.h"

class DemoDrawer
{
protected:
    SDL_Renderer *m_renderer;
    DemoInterface *demo;
public:
    DemoDrawer(SDL_Renderer *renderer):
        m_renderer(renderer),
        demo(new PlainBezierCurveDemo(renderer))
    {
        demo->setupRenderer();
    }
    ~DemoDrawer();

    void draw();
};


#endif //GAMEDEVMATHPROBLEMS_EXAMPLEDRAWER_H
