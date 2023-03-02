#include <iostream>
#include "game.h"

int main() {
	Game g;
	while(!g.isWin()){
		std::cout << g;
		g.manualPlay();
	}
	std::cout << "\033[32m" << "YOU WIN!!"<< "\033[0m" << std::endl;
	return 0;
}