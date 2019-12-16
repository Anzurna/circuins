class Movable {




	public:

	struct MovementData {
		sf::Vector2f speed; // x,y speed to target
		float degrees; // Rotation to target
	};


	virtual Movable::MovementData calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position);
	virtual void setTeam(int team) { this -> m_team = team; };
	virtual void setPosition(float x, float y);
	virtual void setPosition(sf::Vector2f);
	virtual int getTeam() { return this -> m_team; };
	virtual sf::Vector2f getPosition() { return this -> m_shape.getPosition(); };
	virtual void draw(sf::RenderWindow*){};
	virtual void move(){};
	virtual void changeHP(int){};
	virtual void setRotation(float);



	protected:
	virtual ~Movable(){};
	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float m_TargetX;
	float m_TargetY;
	float Vector;
	float TotalSpeed;
	int m_team;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
	MovementData m_movementData;


	// Define for yourself — is it transformed or not!



};