//
// Created by mvlabat on 4/10/16.
//

#ifndef GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H
#define GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H

#include <vector>
#include "../DemoInterface.h"
#include "../../../../My2D/src/My2D.h"

class PlainBezierCurveDemo : public DemoInterface
{
protected:
    double tPeriod = 0.005;
    std::vector<point2d> points;
    std::vector<point2d> pixels;
public:
    PlainBezierCurveDemo(SDL_Renderer *renderer): DemoInterface(renderer) {
    }

    virtual void setupRenderer();

    void calculateCurve();

    virtual void draw();

protected:
    void calculateTPeriod();
};


#endif //GAMEDEVMATHPROBLEMS_PLAINBEZIERCURVEDEMO_H
