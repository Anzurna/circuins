Enemy::Enemy() {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;

	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;
	//m_step = 0;
	m_texture.loadFromFile("content/CharSprites/Golden/1small.png");

	m_shape.setTexture(&m_texture);
	m_bulletTexture.loadFromFile("content/particles/red1.png");
//	alignHelper.setFillColor(sf::Color::Green);
//  alignHelper.setSize(sf::Vector2f(40.0f, 5.0f));
}
/* void Enemy::setPosition(float x, float y)
{
	return this -> characterShape.setPosition(x, y);
} */