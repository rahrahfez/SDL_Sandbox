#include "Game.h"

int main(int argc, char* args[]) {
	Game g;
	g.init();
	while (g.isRunning()) {
		g.render();
		g.update();
	}
	g.close();
	return 0;
}