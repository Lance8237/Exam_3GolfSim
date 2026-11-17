#ifndef GOLFHOLE_H
#define GOLFHOLE_H

class GolfHole {
    private:
        int par;
        int yardage;
        double distanceRemaining;
        int strokes;

    public:
        GolfHole(int holePar, int holeYardage);
        void hitShot(double distance);
        double getDistanceRemaining() const;
        int getStrokes() const;
        int getPar() const;
        int getYardage() const;
};











#endif