#include <Player.h>

Player::Player() {
	speedToNextPointX = 0.1f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	targetX = 0.0;
	targetY = 0.0;
	TotalSpeed = 2;
}

void Player::DrawPlayer(sf::RenderWindow *window,float height,float width) {
	playFig.setFillColor(sf::Color::Green);
	playFig.setSize(sf::Vector2f(height,width));
	playFig.setOrigin(10.0f,10.0f);
	//playFig.setPosition(20.0f,20.0f);
	window->draw(playFig);

}


void Player::moveSelf(float speedX,float speedY)

{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			playFig.move(-0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W)) //forward now
		{



		/*	previousPointX = player.getPosition().x;
			previousPointY = player.getPosition().y;
			xLength = targetX - previousPointX;
			yLength = targetY- previousPointY;

			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed*(xLength/Vector);
			speedToNextPointY = TotalSpeed*(yLength/Vector);
			tail1.setPosition(previousPointX-(10*speedToNextPointX), previousPointY-(10*speedToNextPointY));
			tail2.setPosition(previousPointX-(15*speedToNextPointX), previousPointY-(15*speedToNextPointY)); */




			playFig.move(speedX , speedY );
			//playFig.move(0.0f,-0.5f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D) )
		{
			playFig.move(0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			playFig.move(0.0f, 0.5f);
		}

}