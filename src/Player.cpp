


Player::Player() {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;
}
float Player::getPreviousX() {
	return (this->previousPointX);
}

float Player::getPreviousY() {
	return (this->previousPointY);
}

float Player::getTargX() {
	return (this->m_TargetX);
}

float Player::getTargY() {
	return (this->m_TargetY);
}

float Player::getPosX() {
	return (this->playFig.getPosition().x);
}

float Player::getPosY() {
	return (this->playFig.getPosition().y);
}

sf::Vector2i Player::getTransformedPosition(){
	return (this->transformedPlayerPosition);
}

void Player::setTargX(float X)
{
	this->m_TargetX = X;
}
void Player::setTargY(float Y)
{
	this->m_TargetY = Y;
}
void Player::setPosition(float x, float y)
{
	this -> playFig.setPosition(x, y);
}



void Player::DrawPlayer(sf::RenderWindow *window,float height,float width)
{
	playFig.setFillColor(sf::Color::Green);
	playFig.setSize(sf::Vector2f(height,width));
	playFig.setOrigin(10.0f,10.0f);
	//playFig.setPosition(20.0f,20.0f);
	window->draw(playFig);
}

void Player::moveClick(sf::RenderWindow& window, sf::View view, float targetX,float targetY)
{
			transformedPlayerPosition = window.mapCoordsToPixel( playFig.getPosition() , view );
			previousPointX = transformedPlayerPosition.x;
			previousPointY = transformedPlayerPosition.y;
			m_TargetX = targetX;
			m_TargetY = targetY;
			xLength = m_TargetX - previousPointX;
			yLength = m_TargetY - previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed * 3 * (xLength / Vector);
			speedToNextPointY = TotalSpeed * 3 * (yLength / Vector);
/* 			if (abs(xLength) < 4 && abs(yLength) < 4) {
				speedToNextPointX = speedToNextPointY = 0;
			} */
			//playFig.move(speedToNextPointX,speedToNextPointY);
			/* while (true abs(transformedPlayerPosition.x - targetX) >= 15 && abs(transformedPlayerPosition.y - targetY)>=15 ){

			} */
}

void Player::move(sf::RenderWindow& window, sf::View view){
	transformedPlayerPosition = window.mapCoordsToPixel( playFig.getPosition() , view );
	previousPointX = transformedPlayerPosition.x;
	previousPointY = transformedPlayerPosition.y;
	xLength = m_TargetX - previousPointX;
	yLength = m_TargetY - previousPointY;
	if (abs(xLength) < 8 && abs(yLength) < 8) {
				speedToNextPointX = speedToNextPointY = 0;
			} else {
				playFig.move(speedToNextPointX,speedToNextPointY);
			}


}

void Player::moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view )
{
	 //Здесь происходит нечто ужасное

					for (unsigned int i = 0; i < MapHndl.allVertex.size(); i++) {
						if (MapHndl.allVertex[i].checkIsOn(this -> getTransformedPosition())) {
							for (unsigned int a = 0; a < MapHndl.allVertex.size(); a++) {
								if (MapHndl.allVertex[a].checkIsClicked(window, mousePos, view)) {
									for (unsigned int k = 0; k < MapHndl.allVertex[i].getConnectionCodesVectorSize(); k++) {
										if (MapHndl.allVertex[a].getID() == MapHndl.allVertex[i].getConnectionCode(k)) {
											this -> moveClick(window, view,
															MapHndl.allVertex[a].getTransformedVertexPosition().x,
															MapHndl.allVertex[a].getTransformedVertexPosition().y);
									}
								}
							}
						}
					}
				}
			}



/* void Player::moveSelf(float speedX,float speedY)
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
} */
