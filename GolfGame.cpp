#include "GolfGame.h"
#include <iostream>

GolfGame::GolfGame() : gen(std::random_device{}()) {
    //front 9
    holes.push_back(GolfHole(4, 388));
    holes.push_back(GolfHole(4, 412));
    holes.push_back(GolfHole(5, 591));
    holes.push_back(GolfHole(3, 192));
    holes.push_back(GolfHole(5, 612));
    holes.push_back(GolfHole(4, 309));
    holes.push_back(GolfHole(3, 164));
    holes.push_back(GolfHole(4, 373));
    holes.push_back(GolfHole(4, 329));

    //back 9
    holes.push_back(GolfHole(5, 601));
    holes.push_back(GolfHole(4, 346));
    holes.push_back(GolfHole(4, 357));
    holes.push_back(GolfHole(4, 391));
    holes.push_back(GolfHole(3, 174));
    holes.push_back(GolfHole(4, 314));
    holes.push_back(GolfHole(4, 297));
    holes.push_back(GolfHole(3, 204));
    holes.push_back(GolfHole(5, 578));
}

void GolfGame::play() {
    std::cout << " ============================" << std::endl;
    std::cout << "| Welcome to Golf Simulator! |" << std::endl;
    std::cout << " ============================" << std::endl;

    int numHoles;
    std::cout << "Would you like to play 9 or 18 holes? ";
    std::cin >> numHoles;

    while (numHoles != 9 && numHoles != 18) {
        std::cout << "Invalid choice. Enter 9 or 18: ";
        std::cin >> numHoles;
    }

    for (int i = 0; i < numHoles; i++) {
        std::cout << "===============" << std::endl;
        std::cout << "Hole " << i + 1 << std::endl;
        std::cout << "===============" << std::endl;

        playHole(holes[i]);
    }

    showScorecard(numHoles);
}

double GolfGame::getClubDistance(int clubChoice) {
    //Driver
    if (clubChoice == 1) {
        std::uniform_real_distribution<double> dist(270.0, 290.0);
        return dist(gen);
    }

    //3 Wood
    else if (clubChoice == 2) {
        std::uniform_real_distribution<double> dist(250.0, 265.0);
        return dist(gen);
    }

    //Hybrid
    else if (clubChoice == 3) {
        std::uniform_real_distribution<double> dist(230.0, 245.0);
        return dist(gen);
    }

    //4 Iron
    else if (clubChoice == 4) {
        std::uniform_real_distribution<double> dist(205.0, 215.0);
        return dist(gen);
    }

    //5 Iron
    else if (clubChoice == 5) {
        std::uniform_real_distribution<double> dist(190.0, 200.0);
        return dist(gen);
    }

    //6 Iron
    else if (clubChoice == 6) {
        std::uniform_real_distribution<double> dist(175.0, 185.0);
        return dist(gen);
    }

    //7 Iron
    else if (clubChoice == 7) {
        std::uniform_real_distribution<double> dist(160.0, 170.0);
        return dist(gen);
    }

    //8 Iron
    else if (clubChoice == 8) {
        std::uniform_real_distribution<double> dist(145.0, 155.0);
        return dist(gen);
    }

    //9 Iron
    else if (clubChoice == 9) {
        std::uniform_real_distribution<double> dist(130.0, 140.0);
        return dist(gen);
    }

    //Pitching Wedge
    else if (clubChoice == 10) {
        std::uniform_real_distribution<double> dist(120.0, 125.0);
        return dist(gen);
    }

    //54 Degree
    else if (clubChoice == 11) {
        std::uniform_real_distribution<double> dist(105.0, 110.0);
        return dist(gen);
    }

    //60 Degree
    else if (clubChoice == 12) {
        std::uniform_real_distribution<double> dist(95.0, 100.0);
        return dist(gen);
    }

    else {
        return 0;
    }
}

void GolfGame::playHole(GolfHole& hole) {
    std::cout << "PAR: " << hole.getPar() << std::endl;
    std::cout << "YARDAGE: " << hole.getYardage() << std::endl;
    std::cout << "STROKES: " << hole.getStrokes() << std::endl;

    while (hole.getDistanceRemaining() > 10) {
        std::cout << "Choose your club:" << std::endl;
        std::cout << "1. Driver (270-290 yards)" << std::endl;
        std::cout << "2. 3 Wood (250-265 yards)" << std::endl;
        std::cout << "3. Hybrid (230-245 yards)" << std::endl;
        std::cout << "4. 4 Iron (205-215 yards)" << std::endl;
        std::cout << "5. 5 Iron (190-200 yards)" << std::endl;
        std::cout << "6. 6 Iron (175-185 yards)" << std::endl;
        std::cout << "7. 7 Iron (160-170 yards)" << std::endl;
        std::cout << "8. 8 Iron (145-155 yards)" << std::endl;
        std::cout << "9. 9 Iron (130-140 yards)" << std::endl;
        std::cout << "10. Pitching Wedge (120-125 yards)" << std::endl;
        std::cout << "11. 54 Degree (105-110 yards)" << std::endl;
        std::cout << "12. 60 Degree (95-100 yards)" << std::endl;

        int clubChoice;
        std::cin >> clubChoice;

        if (clubChoice < 1 || clubChoice > 12) {
            std::cout << "Invalid club choice" << std::endl;
            continue;
        }

        double distance = getClubDistance(clubChoice);

        if (clubChoice == 12) {
            int power;
            std::cout << "Enter power percentage (1-100): ";
            std::cin >> power;

            if (power >=1 && power <=100) {
                distance = distance * (power / 100.0);
            }

            else {
                std::cout << "Invalid power percentage!" << std::endl;
                continue;
            }
        }

        std::cout << "Shot distance: " << distance << " yards" << std::endl;

        hole.hitShot(distance);

        std::cout << "After hitting shot:" << std::endl;
        std::cout << "Distance Remaining: " << hole.getDistanceRemaining() << " yards." << std::endl;
        std::cout << "Strokes: " << hole.getStrokes() << std::endl;
    }

    std::cout << "You're on the green!" << std::endl;
    putt(hole);

    std::cout << "Hole completed in " << hole.getStrokes() << " strokes!" << std::endl;
}

void GolfGame::putt(GolfHole& hole) {
    while (hole.getDistanceRemaining() > 0) {
        double remaining = hole.getDistanceRemaining();

        std::cout << "Putting distance: " << remaining << " yards" << std::endl;

        std::uniform_int_distribution<int> chance(1, 100);
        int roll = chance(gen);

        int makeChance;

        if (remaining <= 0.33) {
            makeChance = 99;
        }

        else if (remaining <= 1) {
            makeChance = 90;
        }

        else if (remaining <= 2) {
            makeChance = 50;
        }

        else if (remaining <= 3) {
            makeChance = 33;
        }

        else {
            makeChance = 15;
        }

        if (roll <= makeChance) {
            hole.hitShot(remaining);
            std::cout << "You made the putt!" << std::endl;           
        }

        else {
            hole.hitShot(remaining + 0.5);

            std::cout << "You missed! The ball is now " << hole.getDistanceRemaining() << " yards away." << std::endl;
        }
    }
}

void GolfGame::showScorecard(int numHoles) {
    int totalPar = 0;
    int totalStrokes = 0;

    std::cout << "\n======= SCORECARD ========\n";
    std::cout << "Hole  Par  Strokes  +/-  Result\n";

    for (int i = 0; i < numHoles; i++) {
        int par = holes[i].getPar();
        int strokes = holes[i].getStrokes();
        int score = strokes - par;

        totalPar += par;
        totalStrokes += strokes;

        std::cout << i + 1 << "      " << par << "      " << strokes << "      " << score << "      " << getScoreName(strokes, par) << std::endl;
    }

    std::cout << "===========================\n";
    std::cout << "TOTAL  " << totalPar << "  " << totalStrokes << "  " << totalStrokes - totalPar << std::endl;
}

std::string GolfGame::getScoreName(int strokes, int par) {
    int difference = strokes - par;

    if (strokes == 1) {
        return "Hole in One";
    }
    else if (difference <= -3) {
        return "Albatross";
    }
    else if (difference == -2) {
        return "Eagle";
    }
    else if (difference == -1) {
        return "Birdie";
    }
    else if (difference == 0) {
        return "Par";
    }
    else if (difference == 1) {
        return "Bogey";
    }
    else if (difference == 2) {
        return "Double Bogey";
    }
    else {
        return "Triple Bogey or Worse";
    }
}