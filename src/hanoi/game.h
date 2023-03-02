#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "tower.h"
#include <vector>
#include <string>
#include <limits>
class Game {
    public:
        Game();
        void solve(int n, int D, int A, int I);
        void initClassicGame();
        void initCustomGame(int nbrTowers, int nbrDisks);
        void createTower(std::string name);
        void moveDisk(int from, int to);
        bool isWin();
        void manualPlay();
        int getNumberTowers() const;
        friend std::ostream& operator<<(std::ostream& out, const Game & g);

    private:
    std::vector<Tower> myTowers;
    int totalDisk;
};

#endif