#include"Game.h"
using namespace std;

#if DEBUG
int main() {
	Game* juego = new Game();
	juego->Play();
	delete juego;
	return 0;
}
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) {
	Game* juego = new Game();
	juego->Play();
	delete juego;
	return 0;
}
#endif
/*cosas a completar:
+ Agregar el clima.
+ Agregar animacion.
+ Agregar los puntos con el documento.
+ Agregar los creditos y menu.
*/
/*
Musica: http://freemusicarchive.org/music/Dead_Peoples_Records/Just_a_Minute/You_should_have_said_you_were_with_someone_1044
Sonido: http://soundbible.com/511-Squish-1.html
*/