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
/*cosas a completar:
+ Agregar el clima.
+ Agregar animacion.
+ Agregar los puntos con el documento.
*/
/*
Musica: http://freemusicarchive.org/music/Dead_Peoples_Records/Just_a_Minute/You_should_have_said_you_were_with_someone_1044
Sonido: http://soundbible.com/511-Squish-1.html
Fuente: http://www.1001fonts.com/times-new-roman-fonts.html?page=1&items=10
*/