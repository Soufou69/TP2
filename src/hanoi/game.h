#ifndef __GAME_H__
#define __GAME_H__

#include "tower.h"
#include <vector>
#include <string>
class Game {
    public:
        Game();
        void solve();
        void initGame();
        void createTower(std::string name);
        void moveDisk(int from, int to);
        bool isWin();

    private:
    std::vector<Tower*> myTowers;
    int totalDisk;
};

#endif