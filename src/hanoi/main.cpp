#include <iostream>
#include "game.h"

int main() {
	std::cout << "What do you want to do ?\n\t0 - I want to play !\n\t1 - Let's use the computer's brain to solve that !" << std::endl;
	int choice=-1;
    while(choice==-1){
        std::cin >> choice;
        if(!std::cin.good() ||choice<0 || choice>1){
            std::cout << "\033[1;31m" <<"Error: please enter a valid choice" << "\033[0m" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice=-1;
        }
    }
	Game g;
	switch(choice){
		case 0:
			while(!g.isWin()){
				std::cout << g;
				g.manualPlay();
			}
			std::cout << "\033[32m" << "YOU WIN!!"<< "\033[0m" << std::endl;
		break;
		case 1:
			std::cout << "Start of the game\n" << g << std::endl;
			g.solve(4,0,2,1);
			if(g.isWin())
				std::cout << "Solved !" << std::endl;
			std::cout << g;
		break;
	}
	
	return 0;
}