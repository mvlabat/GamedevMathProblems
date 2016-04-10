//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H
#define GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H

#include <SDL2/SDL_render.h>

class DemoInterface
{
protected:
    SDL_Renderer *m_renderer;
public:
    DemoInterface(SDL_Renderer *renderer):
        m_renderer(renderer)
    { }

    virtual void setupRenderer() = 0;
    virtual void draw() = 0;
};


#endif //GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H
