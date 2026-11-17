# Golf Simulator

## Description
This is a C++ golf simulator that allows the user to play 9 or 18 holes of golf. The player selects clubs, hits shots with randomized distances, and putts to complete each hole. At the end of the round, a scorecard displays the player's results.

## How to Run
Compile the program:

make

Run the program:

./golf

Clean the executable:

make clean

## Features
- 9 or 18 hole rounds
- 12 different golf clubs
- Randomized shot distances
- Adjustable wedge power
- Probability-based putting
- Scorecard and stroke tracking

## Required Feature
- std::vector

## Classes
- GolfGame: Handles the game logic, club selection, putting, and scorecard.

- GolfHole: Stores the hole information, remaining distance, and stroke count.