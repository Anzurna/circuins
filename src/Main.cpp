#include "Main.hpp"
#include "GridInfo.h"
#include "LineGenerator.h"
#include "Map/MapHandler.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));

	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));

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

	sf::RectangleShape button1(sf::Vector2f(500.0f, 100.0f));
	button1.setFillColor(sf::Color::Green);
	button1.setPosition(sf::Vector2f(390.0f, 360.0f));
	sf::RectangleShape button2(sf::Vector2f(500.0f, 100.0f));
	button2.setFillColor(sf::Color::Green);
	button2.setPosition(sf::Vector2f(390.0f, 480.0f));
	sf::RectangleShape button3(sf::Vector2f(500.0f, 100.0f));
	button3.setFillColor(sf::Color::Green);
	button3.setPosition(sf::Vector2f(390.0f, 600.0f));

	while (window.isOpen()) {
			int SizeWidth = 1280;
			int SizeHeight = 720;
		while (window.pollEvent(evnt)) {
			SizeWidth = evnt.size.width;//ловлю размер окна
			SizeHeight = evnt.size.height;

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
		if ((SizeWidth >= 550) && (SizeHeight >= 720)) {//условия где размеры кнопок не меняются{
				int button1x = ((SizeWidth-500)/2);
				int button1y = 600;

				button1.setPosition(sf::Vector2f(button1x, button1y));
				button1.setSize(sf::Vector2f(500.0f, 100.0f));

				int button2x = ((SizeWidth - 500) / 2);
				int button2y = 480;

				button2.setPosition(sf::Vector2f(button2x, button2y));
				button2.setSize(sf::Vector2f(500.0f, 100.0f));

				int button3x = ((SizeWidth - 500) / 2);
				int button3y = 360;

				button3.setPosition(sf::Vector2f(button3x, button3y));
				button3.setSize(sf::Vector2f(500.0f, 100.0f));
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

		//window.setView(view);
		//view.setCenter(player.getPosition());

		mapHandl.drawMap(&window);
		window.draw(player);
		infotable.showInfo(&window, &player, mousePos, targetX, targetY,
						   previousPointX, previousPointY);

		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.display();
	}

	return 0;
}
