#ifndef GOLFGAME_H
#define GOLFGAME_H
#include "GolfHole.h"
#include <vector>
#include <random>
#include <string>

class GolfGame {
    public:
        GolfGame();
        void play();

    private:
        std::vector<GolfHole> holes;
        std::mt19937 gen;
        double getClubDistance(int clubChoice);
        void playHole(GolfHole& hole);
        void putt(GolfHole& hole);
        void showScorecard(int numHoles);
        std::string getScoreName(int strokes, int par);

};








#endif