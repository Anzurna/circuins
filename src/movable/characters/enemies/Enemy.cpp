Enemy::Enemy() {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	m_speed = 5;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;
	isActive = true;
	//m_step = 0;
	m_texture.loadFromFile("content/CharSprites/basic2.png");
	this -> m_hasKey = false;
	m_shape.setTexture(&m_texture);

//	alignHelper.setFillColor(sf::Color::Green);
//  alignHelper.setSize(sf::Vector2f(40.0f, 5.0f));
}
/* void Enemy::setPosition(float x, float y)
{
	return this -> characterShape.setPosition(x, y);
} */

void Enemy::behave(std::list<Movable*>& allMovingObjects, sf::Vector2f target, float dt)
{
	srand(time(0));
	int o;
	o = ((rand()+ this -> ID)%5) +1;
	 this -> m_timer1 += dt;
	 if (this -> isActive) {
		if (abs(target.x - (this -> getPosition().x)) > 300 &&
			abs(target.y - (this -> getPosition().y)) > 300) {
			this -> calculateSpeedAndRotation({(int)target.x, (int)target.y},
							{(int)this ->getPosition().x, (int)this ->getPosition().y});
			this -> setRotation(m_movementData.degrees);
		}
		if (abs(target.x - (this -> getPosition().x)) < 600 &&
			abs(target.y - (this -> getPosition().y)) < 600) {
				switch(o) {
					case 3:
						this -> move(m_movementData.speed.y, -m_movementData.speed.x);
						break;
					case 4:
						this -> move(-m_movementData.speed.y, m_movementData.speed.x);
						break;
					case 5:
						this -> move(-m_movementData.speed.x, -m_movementData.speed.y);
						break;
					case 2:
						this -> move(m_movementData.speed.x, m_movementData.speed.y);
						break;
					default:
						break;
				}
			}
		if (m_timer1 > 0.3)	{//		if (Time > 1.0) {
			if (abs(target.x - this -> getPosition().x) < 600 &&
			abs(target.y - this -> getPosition().y) < 600) {
				this ->fire(allMovingObjects, {(int)target.x,
								(int)target.y});
			}
				this -> m_timer1 = 0;
			}
	 }

}
void Enemy::move()
{
	this -> m_shape.move(this -> m_movementData.speed.x, this -> m_movementData.speed.y);
}
void Enemy::move(float x, float y)
{
	this -> m_shape.move(x, y);
}

void Enemy::handle(std::list<Movable*>& list, std::list<Movable*>::iterator&, float)
{
	if (this -> getHP() <=100) {
		if (m_hasKey) {
			this -> dropKey(list);
		}
	}
}
void Enemy::dropKey(std::list<Movable*>& list)
{
	Key *tempKey = new Key();
	list.push_back(tempKey);
	list.back() -> setPosition(this -> getPosition());
}

