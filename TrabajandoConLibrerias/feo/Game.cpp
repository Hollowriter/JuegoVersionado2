#include "Game.h"

Game::Game()
:
puntaje(0),
puntajeMasAlto(0){
	srand(time(0));
	myomi = new PlayerP();
	mineral = new Rock();
	for (int i = 0; i < TOPE; i++) {
		if (i < TOPE / 2) {
			bichos[i] = new Radroach();
		}
		else if (i >= TOPE / 2) {
			bichos[i] = new Beatle();
		}
	}
}
Game::~Game(){
	delete myomi;
	delete mineral;
	for (int i = 0; i < TOPE; i++){
		if (bichos[i] != NULL) {
			delete bichos[i];
			bichos[i] = NULL;
		}
	}
	myomi = NULL;
	mineral = NULL;
}
void Game::Menu(){
	/*try {
		sf::Http http("http://query.yahooapis.com/");
		sf::Http::Request requesting;
		requesting.setUri("/v1/public/yql?q=select%20item.condition.code%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22buenos%20aires%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
		sf::Http::Response answer = http.sendRequest(requesting);
		nlohmann::json jdata = nlohmann::json::parse(answer.getBody().c_str());
		clima = atoi(reportero.c_str());
	}
	catch (exception e){
		clima = 2000;
		throw "tralalala";
	}*/ // json me tira un error de linkeo
	sf::RenderWindow window(sf::VideoMode(ventanaX, ventanaY), "Myomi and the bugs");
	puntuacion.open("puntos.txt");
	if (!puntuacion){
		ofstream creador;
		creador.open("puntos.txt");
		creador.close();
		puntuacion.open("puntos.txt");
	}
	if (puntuacion.is_open()){
		puntuacion >> detectorPuntos;
		puntajeMasAlto = atoi(detectorPuntos.c_str());
	}
	puntuacion.close();
	quieroJugar = false;
	sf::Font thyFont;
	thyFont.loadFromFile("Assets/Crimson-Roman.ttf");
	sf::Text thyText("Myomi and the bugs", thyFont, 40);
	sf::Text otherText("Press space to start", thyFont, 25);
	sf::Text marcador("High score: " + detectorPuntos, thyFont, 30);
	thyText.setFillColor(sf::Color::Black);
	otherText.setFillColor(sf::Color::Black);
	marcador.setFillColor(sf::Color::Black);
	thyText.move(200.0f, 100.0f);
	otherText.move(250.0f, 150.0f);
	marcador.move(500.0f, 140.0f);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				quieroJugar = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
				Credits(window);
			}
		}
		if (quieroJugar == true) {
			Play(window);
			marcador.setString("High score: " + to_string(puntajeMasAlto));
		}
		/*switch (clima) {
		case sunny:
		window.clear(sf::Color::Yellow);
		break;
		case windy:
		window.clear(sf::Color::Blue);
		break;
		case cloudy:
		window.clear(sf::Color::Green);
		break;
		case hot:
		window.clear(sf::Color::Red);
		break;
		case cold:
		window.clear(sf::Color::Black);
		break;
		default:
		window.clear(sf::Color::White);
		break;
		}*/ // json me tira errores de linkeo
		window.clear(sf::Color::White);
		window.draw(thyText);
		window.draw(otherText);
		window.draw(marcador);
		window.display();
	}
}
void Game::Play(sf::RenderWindow &window){
	musiquita.openFromFile("Assets/someone.ogg");
	musiquita.play();
	myomi->SetHealth(basicHealth);
	for (int i = 0; i < TOPE; i++) {
		if (bichos[i] != NULL) {
			bichos[i]->Positioning(myomi);
		}
	}
	contando = relojito.restart();
	while (window.isOpen() && !(myomi->Death()) && quieroJugar == true) {
		sf::Event event;
		contando = relojito.restart();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		myomi->Move(contando);
		myomi->Throwing(mineral);
		mineral->Path(window, contando);
		for (int i = 0; i < TOPE; i++){
			if (bichos[i] != NULL) {
				bichos[i]->Attack(contando, myomi);
				bichos[i]->CollideRock(mineral);
				if (myomi->GetShape().getGlobalBounds().intersects(bichos[i]->GetShape().getGlobalBounds()) &&
					!(bichos[i]->Death())) {
					myomi->SetHealth(myomi->GetHealth() - bichos[i]->GetHealth());
					bichos[i]->SetHealth(bichos[i]->GetHealth() - bichos[i]->GetHealth());
				}
				bichos[i]->AfterLife(myomi);
			}
		}
		window.clear(sf::Color::White);
		window.draw(myomi->GetShape());
		window.draw(mineral->GetShape());
		for (int i = 0; i < TOPE; i++){
			if (bichos[i] != NULL) {
				window.draw(bichos[i]->GetShape());
			}
		}
		window.display();
		puntaje++;
	}
	if (puntaje > puntajeMasAlto){
		puntajeMasAlto = puntaje;
		puntuacion.open("puntos.txt");
		puntuacion << puntajeMasAlto;
		puntuacion.close();
	}
	musiquita.stop();
	quieroJugar = false;
	puntaje = 0;
	window.clear(sf::Color::White);
	mineral->SetThrown(false);
}
void Game::Credits(sf::RenderWindow &window){
	sf::Font thyFont;
	thyFont.loadFromFile("Assets/Crimson-Roman.ttf");
	sf::Text texty("'arte' y programacion: Rodrigo Diaz Klipphan", thyFont, 25);
	sf::Text textou("Herramientas: Piskel, Visual Studio", thyFont, 20);
	sf::Text superTextou("Musica: http://freemusicarchive.org/music/Dead_Peoples_Records/", thyFont, 20);
	sf::Text thyTextou("Sonido: http://soundbible.com/511-Squish-1.html", thyFont, 20);
	sf::Text testo("Fuente: http://www.1001fonts.com/times-new-roman-fonts.html?page=1&items=10", thyFont, 20);
	texty.setFillColor(sf::Color::Black);
	textou.setFillColor(sf::Color::Black);
	superTextou.setFillColor(sf::Color::Black);
	thyTextou.setFillColor(sf::Color::Black);
	testo.setFillColor(sf::Color::Black);
	texty.move(200.0f, 200.0f);
	textou.move(200.0f, 250.0f);
	superTextou.move(200.0f, 300.0f);
	thyTextou.move(200.0f, 350.0f);
	testo.move(200.0f, 400.0f);
	while (window.isOpen() && !(sf::Keyboard::isKeyPressed(sf::Keyboard::M))) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::White);
		window.draw(texty);
		window.draw(textou);
		window.draw(superTextou);
		window.draw(thyTextou);
		window.draw(testo);
		window.display();
	}
}