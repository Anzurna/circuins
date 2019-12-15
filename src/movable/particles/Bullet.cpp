Bullet::Bullet ()
{
	m_texture.loadFromFile("content/particles/red1.png");
	this -> m_shape.setTexture(&m_texture);
	this -> m_shape.setSize({30.0f, 30.0f});

}
Bullet::Bullet (sf::Texture* texture, int team)
{

	this -> m_shape.setTexture(texture);
	this -> m_shape.setSize({30.0f, 30.0f});
	this -> m_team = team;

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
	this -> m_shape.move(speed.x, speed.y);
}

void Bullet::move()
{
	this -> m_shape.move(m_movementData.speed.x, m_movementData.speed.y);
}

void Bullet::setRotation(float& degrees) { this -> m_shape.setRotation(degrees); }
void Bullet::setRotation() { this -> m_shape.setRotation(m_movementData.degrees); }