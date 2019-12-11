Bullet::Bullet ()
{
	m_texture.loadFromFile("content/particles/red1.png");
	m_shape.setTexture(&m_texture);
	m_shape.setSize({30.0f, 30.0f});

}

void Bullet::setPosition(sf::Vector2f position)
{
	this -> m_shape.setPosition(position.x, position.y);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(this -> m_shape);
}

void Bullet::move(sf::Vector2f speed)
{
	this -> m_shape.move(speed.x, speed.y)
}