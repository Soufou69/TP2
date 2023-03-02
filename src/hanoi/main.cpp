#include <iostream>
#include <string>
#include "game.h"

int askForInt(int min, int max, std::string msg);

int main() {
	int choice=askForInt(0,2,"What do you want to do ?\n\t0 - I want to play the classic game !\n\t1 - I want to play a custom version of the game\n\t2 - Let's use the computer's brain to solve that !");
	
	if(choice==0){
		Game g;
		while(!g.isWin()){
				std::cout << g;
				g.manualPlay();
			}
		std::cout << "\033[32m" << "YOU WIN!!"<< "\033[0m" << std::endl;
	}else if(choice==1){
		int nbrTowers=askForInt(1,std::numeric_limits<int>::max(),"Chose the number of towers (at least 1)");
		int nbrDisks=askForInt(0,std::numeric_limits<int>::max(),"Chose the number of total disks");;
		Game g(nbrTowers,nbrDisks);
		while(!g.isWin()){
				std::cout << g;
				g.manualPlay();
			}
		std::cout << "\033[32m" << "YOU WIN!!"<< "\033[0m" << std::endl;
	}else{
		Game g;
		std::cout << "Start of the game\n" << g << std::endl;
		g.solve(4,0,2,1);
		if(g.isWin())
			std::cout << "Solved !" << std::endl;
		std::cout << g;
	}
			
	
	return 0;
}

int askForInt(int min, int max, std::string msg){
	std::cout << msg << std::endl;
	int out=-1;
	while(out==-1){
        std::cin >> out;
        if(!std::cin.good() ||out<min || out>max){
            std::cout << "\033[1;31m" << "Error please enter a valid integer" << "\033[0m" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            out=-1;
        }
    }
	return out;
}