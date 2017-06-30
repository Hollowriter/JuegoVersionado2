#include"Game.h"
using namespace std;

#if DEBUG
int main() {
	Game* juego = new Game();
	juego->Menu();
	delete juego;
	return 0;
}
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) {
	Game* juego = new Game();
	juego->Menu();
	delete juego;
	return 0;
}
#endif