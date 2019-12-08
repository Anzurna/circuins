#include "Main.hpp"

int main() {
	int WINDOWS_HEIGHT = 720;
	int WINDOWS_WIDTH = 1280;
	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Circuins",
							sf::Style::Close | sf::Style::Resize);

	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::Event evnt;
	GlobalContext glob;
	//Заглушка для меню
	sf::RectangleShape startButton(sf::Vector2f(500.0f, 100.0f));
	sf::RectangleShape exitButton(sf::Vector2f(500.0f, 100.0f));
	sf::Texture sb;
	sf::Texture eb;
	sb.loadFromFile("content/interface/startbutn.bmp");
	eb.loadFromFile("content/interface/exitbutn.bmp");
	startButton.setTexture(&sb);
	exitButton.setTexture(&eb);

	startButton.setPosition(400.0f, 300.0f);
	exitButton.setPosition(400.0f, 450.0f);

	while (window.isOpen()) {
		//sf::Vector2i mousePos = sf::Mouse::getPosition(window);






		while (window.pollEvent(evnt)) {

		/* 	if (evnt.type==sf::Event::MouseButtonPressed) {
			float pos_x, pos_y;
			Figure1.setTargX(dote[i].getPosition().x);
			Figure1.setTargY(dote[i].getPosition().y);
			Figure1.moveClick(&window, view, Figure1.getTargX(),Figure1.getTargY());
			pos_x=Figure1.getPosX();
			pos_y=Figure1.getPosY();
			if (((abs(pos_x-Figure1.getTargX()))<=5)&&((abs(pos_y-Figure1.getTargY()))<=5)) {
				i++;
			} */

		if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Enter) {
				GameState newGameState(WINDOWS_WIDTH, WINDOWS_HEIGHT);
				glob.setGameStateActive(true);
				if (glob.getIsGameStateActive()){
				newGameState.handle(evnt, window, /* mousePos, */ glob);
				//newGameState.drawScene(window);
		}
			}

		switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "New window width: " << evnt.size.width << "New window height: " << evnt.size.height;
					break;
				default:
				break;
			}
		}

		if(!glob.getIsGameStateActive()) {
		window.clear();
		// Отрисовка меню
		window.draw(startButton);
		window.draw(exitButton);
		window.display();
		}
	}
	return 0;
}
