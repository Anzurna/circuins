#include <Player.h>

Player::Player() {
	speedToNextPointX = 0.1f;
	speedToNextPointY = 0.0f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	targetX = 0.0;
	targetY = 0.0;
	TotalSpeed = 2;
}
float Player::getPreviousX() {
	return (this->previousPointX);
}

float Player::getPreviousY() {
	return (this->previousPointY);
}

float Player::getTargX() {
	return (this->targetX);
}

float Player::getTargY() {
	return (this->targetY);
}

float Player::getPosX() {
	return (this->playFig.getPosition().x);
}

float Player::getPosY() {
	return (this->playFig.getPosition().y);
}

void Player::setTargX(float X)
{
	this->targetX = X;
}
void Player::setTargY(float Y)
{
	this->targetY = Y;
}



void Player::DrawPlayer(sf::RenderWindow *window,float height,float width) {
	playFig.setFillColor(sf::Color::Green);
	playFig.setSize(sf::Vector2f(height,width));
	playFig.setOrigin(10.0f,10.0f);
	//playFig.setPosition(20.0f,20.0f);
	window->draw(playFig);

}

void Player::moveClick(sf::RenderWindow* window, sf::View view, float targetX,float targetY) {



			sf::Vector2i transformedPlayerPosition = window -> mapCoordsToPixel( playFig.getPosition() , view );
			previousPointX = transformedPlayerPosition.x;
			previousPointY = transformedPlayerPosition.y;
			xLength = targetX - previousPointX;
			yLength = targetY- previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed*5*(xLength/Vector);
			speedToNextPointY = TotalSpeed*5*(yLength/Vector);
			playFig.move(speedToNextPointX,speedToNextPointY);
}


void Player::moveSelf(float speedX,float speedY)

{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: Enter))
		{
			playFig.setPosition(10.0f, 10.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			playFig.move(-speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W))
		{
			playFig.move(0.0f , -speedY );
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D))
		{
			playFig.move(speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			playFig.move(0.0f, speedY);
		}

}
