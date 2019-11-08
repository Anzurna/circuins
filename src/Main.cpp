#include "Main.hpp"
#include "GridInfo.h"
#include "Player.h"
#include "Map/MapHandler.h"

int main() {
	int WINDOWS_HEIGHT = 512;
	int WINDOWS_WIDTH = 512;
	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOWS_WIDTH, WINDOWS_HEIGHT));
	sf::View parallaxView(sf::Vector2f(1256.0f, 1256.0f), sf::Vector2f(WINDOWS_WIDTH, WINDOWS_HEIGHT));

	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	player.setFillColor(sf::Color::Red);
	player.setOrigin(10.0f, 10.0f);

	sf::Event evnt;
	MapHandler mapHandl; //Создание карты
	GridInfo infotable;
	Player Figure1;
/*
 	const unsigned int Colums = 4;
	const unsigned int Rows = 4;
   	int splineArray[Rows][Colums] = {
		{200,200},
		{400,200},
		{400,400},
		{200,400},

	};
	const unsigned int Colums1 = 4;
	const unsigned int Rows1 = 4;
   	int vertexArray[Rows1][Colums1] = {
		{2, 1, 0, 1},
		{1, 2, 1, 0},
		{0, 1, 2, 1},
		{1, 0, 1, 2},
	}; */


	//view.setCenter(player.getPosition());
	//sf::Vector2f parPos(256.0f, 256.0f);
	//parallaxView.setCenter(parPos);
	 //bool kostyl = 1;
	/* int mouseTarX;
	int mouseTarY; */
			int i = 0;

	std::vector<sf::CircleShape> dote(4);
	dote[0].setFillColor(sf::Color::White);
	dote[0].setRadius(10.0f);
	dote[0].setPosition(10.0f,350.0f);
	dote[0].setOrigin(10.0f,10.0f);
	dote[1].setFillColor(sf::Color::White);
	dote[1].setRadius(10.0f);
	dote[1].setPosition(1000.0f,1000.0f);
	dote[1].setOrigin(10.0f,10.0f);
	dote[2].setFillColor(sf::Color::White);
	dote[2].setRadius(10.0f);
	dote[2].setPosition(210.0f,650.0f);
	dote[2].setOrigin(10.0f,10.0f);
	dote[3].setFillColor(sf::Color::White);
	dote[3].setRadius(10.0f);
	dote[3].setPosition(510.0f,350.0f);
	dote[3].setOrigin(10.0f,10.0f);
	while (window.isOpen()) {

		while (window.pollEvent(evnt)) {

			if (evnt.type==sf::Event::MouseButtonPressed) {
			float pos_x, pos_y;
			Figure1.setTargX(dote[i].getPosition().x);
			Figure1.setTargY(dote[i].getPosition().y);
			Figure1.moveClick(&window, view, Figure1.getTargX(),Figure1.getTargY());
			pos_x=Figure1.getPosX();
			pos_y=Figure1.getPosY();
			if (((abs(pos_x-Figure1.getTargX()))<=5)&&((abs(pos_y-Figure1.getTargY()))<=5)) {
				i++;
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


	 	sf::Vector2i mousePos = sf::Mouse::getPosition(window);


		if (mousePos.x > WINDOWS_WIDTH - 10) {
			view.move(5.0f, 0.0f);
			parallaxView.move(0.3f, 0.0f);
		} else if (mousePos.x < 10) {
			view.move(-5.0f, 0.0f);
			parallaxView.move(-0.3f, 0.0f);
		} else if (mousePos.y < 5) {
			view.move(0.0f, -5.0f);
			parallaxView.move(0.0f, -0.3f);
		} else if (mousePos.y > WINDOWS_HEIGHT - 10) {
			view.move(0.0f, 5.0f);
			parallaxView.move(0.0f, 0.3f);
		}


		//Figure1.moveClick(&window, view, mousePos.x, mousePos.y);

		window.clear();

		window.setView(parallaxView);
		mapHandl.drawParallax(&window);

		window.setView(view);
		mapHandl.drawMap(&window);

		Figure1.DrawPlayer(&window, 30.0f, 30.0f);
		infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
						   Figure1.getPreviousX(), Figure1.getPreviousY());


		window.display();
	}

	return 0;
}
