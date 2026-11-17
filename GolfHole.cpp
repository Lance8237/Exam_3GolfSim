#include "GolfHole.h"
#include <cstdlib>
#include <cmath>

GolfHole::GolfHole(int holePar, int holeYardage) {
    par = holePar;
    yardage = holeYardage;
    distanceRemaining = holeYardage;
    strokes = 0;
}

void GolfHole::hitShot(double distance) {
    distanceRemaining = std::abs(distanceRemaining - distance);
    strokes++;
}

double GolfHole::getDistanceRemaining() const {
    return distanceRemaining;
}

int GolfHole::getStrokes() const {
    return strokes;
}

int GolfHole::getPar() const {
    return par;
}

int GolfHole::getYardage() const {
    return yardage;
}