#include "Main.hpp"
#include "GridInfo.h"

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
	/* std::string xPosition;
	std::string yPosition;
 *//*
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
	float targetX;
	float targetY;
	float previousPointX;
	float previousPointY;
	previousPointX = 0.0;
	previousPointY = 0.0;
	targetX = 0.0;
	targetY = 0.0;
	float xLength;
	float yLength;

	float speedToNextPointX;
	float speedToNextPointY;
	float TotalSpeed = 4;

	//view.setCenter(player.getPosition());
	//sf::Vector2f parPos(256.0f, 256.0f);
	//parallaxView.setCenter(parPos);
	 //bool kostyl = 1;
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
			float Vector;
			sf::Vector2i transformedPlayerPosition = window.mapCoordsToPixel( player.getPosition() , view );
			previousPointX = transformedPlayerPosition.x;
			previousPointY = transformedPlayerPosition.y;
			xLength = targetX - previousPointX;
			yLength = targetY- previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed*(xLength/Vector);
			speedToNextPointY = TotalSpeed*(yLength/Vector);

			//tail1.setPosition(previousPointX-(10*speedToNextPointX), previousPointY-(10*speedToNextPointY));
			//tail2.setPosition(previousPointX-(15*speedToNextPointX), previousPointY-(15*speedToNextPointY));
			player.move(speedToNextPointX , speedToNextPointY );

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



		window.clear();
/* 		if (kostyl){

			kostyl = 0;
		} else {
			window.setView(parallaxView);
			kostyl = 1;
		} */


		//window.setView(parallaxView);
		window.setView(parallaxView);
		mapHandl.drawParallax(&window);
		window.setView(view);
		mapHandl.drawMap(&window);
		window.draw(player);
		infotable.showInfo(&window, &player, mousePos, targetX, targetY,
						   previousPointX, previousPointY);


		window.display();
	}

	return 0;
}
