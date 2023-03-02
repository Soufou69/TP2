#include "game.h"

Game::Game(){
    Game::initGame();
}

void Game::createTower(std::string name){
    Tower* t = new Tower(name);
    myTowers.push_back(t);
}
void Game::initGame(){
    createTower("Début");
    createTower("Intermédiaire");
    createTower("Arrivée");

    for(int i=0; i<4; i++){
        myTowers[0]->addDisk(Disk(i+1));
    }
    Game::totalDisk = 4;
}

bool Game::isWin(){
    if (myTowers.back()->getDiskCount() == totalDisk)
        return true;
    else
        return false;
}