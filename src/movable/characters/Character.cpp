Character::Character()
{
	hpBar.setOrigin(50.0f, 3.0f);
	hpBar.setFillColor(sf::Color::Red);
	m_shape.setSize(sf::Vector2f(400,400));
	m_shape.setOrigin(200.0f,200.0f);
	HP = 0;
		m_texture.loadFromFile("content/CharSprites/basic1.png");

	m_shape.setTexture(&m_texture);
	m_bulletTexture.loadFromFile("content/particles/laser1.png");
}


void Character::fire(std::list<Movable*>& allBullets, sf::Vector2i target)
{
	Bullet *tempBullet = new Bullet(&m_bulletTexture, m_team);
	allBullets.push_back(tempBullet);
	allBullets.back() -> setPosition(this -> getPosition());
	allBullets.back() -> calculateSpeedAndRotation(target,
	 {(int)this -> getPosX(), (int)this -> getPosY()});
	allBullets.back() -> setRotation(allBullets.back() -> calculateSpeedAndRotation(target,
	 {(int)this -> getPosX(), (int)this -> getPosY()}).degrees);

}
float Character::getPosX()
{
	return (this -> m_shape.getPosition().x);
}

float Character::getPosY()
{
	return (this -> m_shape.getPosition().y);
}
void Character::changeHP(int amount)
{
	if (this -> HP > 0)
		this -> HP +=amount;
}
void Character::setHP(int amount)
{
	this -> HP = amount;
}

void Character::draw(sf::RenderWindow *window)
{

	hpBar.setSize(sf::Vector2f((this -> getHP()/5), 6));
	hpBar.setPosition(this -> getPosX(), this -> getPosY()+60);

	window -> draw(m_shape);
	window -> draw(hpBar);
}

/* void Character::setPosition(float x, float y)
{
	this -> characterShape.setPosition(x, y);
} */