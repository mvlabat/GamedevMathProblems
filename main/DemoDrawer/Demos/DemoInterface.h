//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H
#define GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <vector>

class DemoInterface
{
protected:
    SDL_Renderer *m_renderer;
    std::vector<SDL_Event*> *m_events;
public:
    DemoInterface(SDL_Renderer *renderer, std::vector<SDL_Event*> *events):
        m_renderer(renderer),
        m_events(events)
    { }

    virtual void setupRenderer() = 0;
    virtual void draw() = 0;
    virtual void processEvents() = 0;
};


#endif //GAMEDEVMATHPROBLEMS_DEMOINTERFACE_H
