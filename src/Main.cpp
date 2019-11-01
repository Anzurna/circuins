#include "Main.hpp"
#include "GridInfo.h"
#include "LineGenerator.h"

int main()
{


	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));
	sf::RectangleShape line1(sf::Vector2f(300.0f, 5.0f));
	sf::RectangleShape line2(sf::Vector2f(300.0f, 5.0f));
	sf::RectangleShape tail1(sf::Vector2f(10.0f, 10.0f));
	sf::RectangleShape tail2(sf::Vector2f(5.0f, 5.0f));

	tail2.setOrigin(2.5f, 2.5f);
	tail2.setFillColor(sf::Color::Red);
	tail1.setFillColor(sf::Color::Red);
	tail1.setOrigin(5.0f, 5.0f);

	line1.setRotation(40.0f);
	line1.setFillColor(sf::Color (77, 253, 252, 255));
	line2.setFillColor(sf::Color (77, 253, 252, 255));
	line2.setPosition(225.0f, 191.0f);


#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::CircleShape shape(window.getSize().x/2);
	shape.setFillColor(sf::Color::White);
	player.setFillColor(sf::Color::Red);
	player.setOrigin(10.0f, 10.0f);
	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/Image4.png");
	shape.setTexture(&shapeTexture);

	sf::Event evnt;

	GridInfo infotable;
	LineGenerator TestGenerator;
	std::string xPosition;
	std::string yPosition;
/*
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
	float speedToNextPointX;
	float speedToNextPointY;


	float targetX;
	float targetY;
	float previousPointX;
	float previousPointY;
	float xLength;
	float yLength;
	speedToNextPointY = 0.1f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	targetX = 0.0;
	targetY = 0.0;
	float Vector;
	float TotalSpeed;
	TotalSpeed = 2;
	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			switch (evnt.type){
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: Enter))
		{
			player.setPosition(200.0f, 200.0f);


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			player.move(-0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W)) //forward now
		{

			previousPointX = player.getPosition().x;
			previousPointY = player.getPosition().y;
			xLength = targetX - previousPointX;
			yLength = targetY- previousPointY;

			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed*(xLength/Vector);
			speedToNextPointY = TotalSpeed*(yLength/Vector);
			tail1.setPosition(previousPointX-(10*speedToNextPointX), previousPointY-(10*speedToNextPointY));
			tail2.setPosition(previousPointX-(15*speedToNextPointX), previousPointY-(15*speedToNextPointY));




			player.move(speedToNextPointX , speedToNextPointY );

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D) )
		{
			player.move(0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			player.move(0.0f, 0.5f);
		}
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{



				targetX = mousePos.x;
				targetY = mousePos.y;


		}







		window.clear();


		TestGenerator.drawMultipleLines(&window);
		infotable.showInfo(&window, &player, mousePos, targetX, targetY,
						   previousPointX, previousPointY);
		window.draw(line1);
		window.draw(line2);
		window.draw(player);
		window.draw(tail1);
		window.draw(tail2);

		window.display();
	}

	return 0;
}
