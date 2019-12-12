class Bullet : public Movable {

	public:
	Bullet();
	Bullet (sf::Texture* texture);
	~Bullet(){};
	void setPosition(sf::Vector2f);
	void draw(sf::RenderWindow&);
	void move(sf::Vector2f );
	void move();
	void setRotation(float& degrees);
	void setRotation();



	private:

	sf::RectangleShape m_shape;
	sf::Texture m_texture;

};