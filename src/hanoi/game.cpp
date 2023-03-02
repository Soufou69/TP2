#include "game.h"

Game::Game(){
    Game::initClassicGame();
}

void Game::createTower(std::string name){
    Tower t(name);
    myTowers.push_back(t);
}
void Game::initClassicGame(){
    Game::initCustomGame(3,4);
}

void Game::initCustomGame(int nbrTowers, int nbrDisks){
    if(nbrTowers==0){
        throw std::string("ERROR: there must be at least 1 tower !");
    }
    std::string name="";
    for(int i=0;i<nbrTowers;i++){
        if(i==0)
            name="Début";
        else if(i==(nbrTowers-1))
            name="Arrivée";
        else{
            name="Intermédiaire";
            if(nbrTowers!=3)
                name+=std::to_string(i);
        }
        
        createTower(name);
    }
    Game::totalDisk = nbrDisks;
    for(int i=4;i>0;i--){
        Disk d(i);
        Game::myTowers[0].addDisk(d);
    }
        
}

bool Game::isWin(){
    if (myTowers.back().getDiskCount() == totalDisk)
        return true;
    else
        return false;
}

void Game::moveDisk(int from, int to){
    if(from!=to && from*to>=0 && from < Game::getNumberTowers() && to < Game::getNumberTowers() && Game::myTowers[from].getDiskCount() >0){
        std::cout << "Moving top disk of tower " << std::to_string(from) << " to tower " << std::to_string(to) << std::endl;
        if(Game::myTowers[to].addDisk(Game::myTowers[from].getTopDisk()))
            Game::myTowers[from].removeTopDisk();
    }else{
        std::cout << "\033[1;31m" << "Error INPUT: Select a valid and not EMPTY tower !" << "\033[0m" << std::endl;
    }
}

void Game::solve(){

}

void Game::manualPlay(){
    int from=-1;
    std::cout << "choose a Tower to move the disk on the top"<< std::endl;
    while(from==-1){
        std::cin >> from;
        if(!std::cin.good() ||from<0 || from>= Game::getNumberTowers()){
            std::cout << "\033[1;31m" <<"Error: please enter a valid integer" << "\033[0m" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            from=-1;
        }
            
    }
    int to=-1;
    std::cout << "Choose where to move the disk"<< std::endl;
    while(to==-1){
        std::cin >> to;
        if(!std::cin.good() || to<0 || to>= Game::getNumberTowers() || from==to){
            std::cout << "\033[1;31m" <<"Error: please enter a valid integer and not the same as previously"<< "\033[0m" <<std::endl; 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            to=-1;
        }
            
    }

    Game::moveDisk(from, to);
}

int Game::getNumberTowers() const{
    return static_cast<int>(Game::myTowers.size());
}


std::ostream& operator<<(std::ostream& out, const Game & g){
    out << "-------------------------------------------" << std::endl;
    out << "Total number of disks: " << g.totalDisk << std::endl;
    out << "state of Towers: " << std::endl;
    for(int i=0;i< g.getNumberTowers();i++)
        out << g.myTowers[i] << "______________" <<  std::endl;
    return out;
}