#include <iostream>
#include "game.h"

int main() {
	Game* g = new Game();
	while(!g->isWin()){
		g->solve();
	}
	return 0;
}