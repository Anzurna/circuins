#include "Main.hpp"
#include "GridInfo.h"
#include "LineGenerator.h"
#include "Map/MapHandler.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));

	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	player.setFillColor(sf::Color::Red);
	player.setOrigin(10.0f, 10.0f);

	sf::Event evnt;
	MapHandler mapHandl; //Создание карты
	GridInfo infotable;
	std::string xPosition;
	std::string yPosition;

 	//const unsigned int Colums = 2;
	//const unsigned int Rows = 10;
/*   	int splineArray[Rows][Colums] = {
		{200,200},
		{274,308},
		{450,350},
		{400,422},
		{270,200},
		{274,308},
		{450,360},
		{410,483},
		{240,280},
		{204,108},

	}; */
	float targetX;
	float targetY;
	float previousPointX;
	float previousPointY;
	previousPointX = 0.0;
	previousPointY = 0.0;
	targetX = 0.0;
	targetY = 0.0;
	while (window.isOpen()) {
		while (window.pollEvent(evnt)) {
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: Enter)) {
			player.setPosition(200.0f, 200.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A)) {
			player.move(-1.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W)) { //forward now
/* 			previousPointX = player.getPosition().x;
			previousPointY = player.getPosition().y;
			xLength = targetX - previousPointX;
			yLength = targetY- previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed*(xLength/Vector);
			speedToNextPointY = TotalSpeed*(yLength/Vector);
			//tail1.setPosition(previousPointX-(10*speedToNextPointX), previousPointY-(10*speedToNextPointY));
			//tail2.setPosition(previousPointX-(15*speedToNextPointX), previousPointY-(15*speedToNextPointY));
			player.move(speedToNextPointX , speedToNextPointY ); */
			player.move(0.0f , -1.5f );
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D)) {
			player.move(1.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S)) {
			player.move(0.0f, 1.5f);
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				targetX = mousePos.x;
				targetY = mousePos.y;
		}

		window.clear();

		window.setView(view);
		view.setCenter(player.getPosition());

		mapHandl.drawMap(&window);
		window.draw(player);
		infotable.showInfo(&window, &player, mousePos, targetX, targetY,
						   previousPointX, previousPointY);


		window.display();
	}

	return 0;
}
