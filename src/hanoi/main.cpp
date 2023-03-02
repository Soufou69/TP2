#include <iostream>
#include "game.h"

int main() {
	Game g;
	while(!g.isWin()){
		std::cout << g;
		g.manualPlay();
	}
	std::cout << "C'est GAGNGE !!"<< std::endl;
	return 0;
}