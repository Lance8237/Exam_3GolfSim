#target: dependencies
# 		command

all: golf

golf: main.cpp GolfGame.cpp GolfGame.h GolfHole.h GolfHole.cpp
	g++ -std=c++11 -o golf main.cpp GolfGame.cpp GolfHole.cpp

clean:
	rm -f golf