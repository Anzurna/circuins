/* #include <Player.h>

void Player::moveSelf(sf::RenderWindow *window)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			Player.move(-0.5f, 0.0f);
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




			Player.move(speedToNextPointX , speedToNextPointY );

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D) )
		{
			Player.move(0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			Player.move(0.0f, 0.5f);
		}
} */