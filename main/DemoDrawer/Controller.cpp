//
// Created by mvlabat on 4/10/16.
//

#include "Controller.h"

Controller::~Controller()
{
    delete demo;
}

void Controller::addEvent(SDL_Event* sdlEvent)
{
    events.push_back(sdlEvent);
}

void Controller::processEvents()
{
    demo->processEvents();
    events.clear();
}

void Controller::draw()
{
    demo->draw();
}