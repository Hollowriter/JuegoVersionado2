#include"Game.h"
using namespace std;
int main() {
	srand(time(0));
	Game* juego = new Game();
	juego->Play();
	delete juego;
	return 0;
}