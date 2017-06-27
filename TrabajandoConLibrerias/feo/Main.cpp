#include"Game.h"
using namespace std;
int main() {
	Game* juego = new Game();
	juego->Play();
	delete juego;
	return 0;
}
/*cosas a completar:
+ Agregar el clima.
+ Agregar animacion.
+ Agregar musica.
+ Agregar los puntos con el documento.
+ Agregar los creditos y menu.
*/