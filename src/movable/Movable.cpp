speedAndRotation Movable::calculateSpeedAndRotation(sf::Vector2i &target, sf::Vector2i &position)
{
	 		m_TargetX = target.x;
			m_TargetY = target.y;
			xLength = m_TargetX - position.x;
			yLength = m_TargetY - position.y;
			Vector = sqrt(pow((m_TargetX - position.x),2)
					+ pow(m_TargetY - position.y,2));
			speedToNextPointX = 7 * (xLength / Vector);
			speedToNextPointY = 7 * (yLength / Vector);

			float degrees = atan2(xLength, -yLength) *(180/M_PI) - 90;

			speedAndRotation sar;
			sar.speed.x = speedToNextPointX;
			sar.speed.y = speedToNextPointY;
			sar.degrees = degrees;
			return sar;


}