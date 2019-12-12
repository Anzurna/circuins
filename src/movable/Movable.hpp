class Movable {

	struct MovementData {
		sf::Vector2f speed; // x,y speed to target
		float degrees; // Rotation to target
	};


	public:

	Movable(){};
	~Movable(){};
	virtual Movable::MovementData calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position);


	protected:
	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float m_TargetX;
	float m_TargetY;
	float Vector;
	float TotalSpeed;
	MovementData m_movementData;


	// Define for yourself — is it transformed or not!



};