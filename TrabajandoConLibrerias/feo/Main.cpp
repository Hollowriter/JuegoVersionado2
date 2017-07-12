#include"Game.h"
using namespace std;
int main() {
	Game* juego = new Game();
	juego->Menu();
	delete juego;
	return 0;
}