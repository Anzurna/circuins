class Bullet : public Movable {

	public:
	Bullet();
	Bullet (sf::Texture* texture, int team);
	~Bullet(){};
	void setPosition(sf::Vector2f);
	void draw(sf::RenderWindow*);
	void move(sf::Vector2f );
	void move();
	void setRotation(float degrees);
	void setRotation();

	sf::Vector2f getPosition() { return this -> m_shape.getPosition(); };
	int getTeam() { return this -> m_team; };



	private:

	sf::RectangleShape m_shape;
	sf::Texture m_texture;
	int m_team;


};