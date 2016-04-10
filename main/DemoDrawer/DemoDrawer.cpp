//
// Created by mvlabat on 4/10/16.
//

#include "DemoDrawer.h"

DemoDrawer::~DemoDrawer()
{
    delete demo;
}

void DemoDrawer::draw()
{
    demo->draw();
}