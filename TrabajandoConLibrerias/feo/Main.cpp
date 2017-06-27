#include"Game.h"
using namespace std;
int main() {
	srand(time(0));
	Game* juego = new Game();
	juego->Play();
	delete juego;
	return 0;
}
/*cosas a completar:
+ Agregar el clima.
+ Agregar los sprites restantes.
+ Agregar animacion.
+ Agregar musica.
+ Agregar los puntos con el documento.
+ Agregar los arrays de enemigos.
+ Agregar los creditos y menu.
+ Delta time.
*/