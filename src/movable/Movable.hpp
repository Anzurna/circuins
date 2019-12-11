class Movable {

	public:

	Movable();
	~Movable(){};
	speedAndRotation calculateSpeedAndRotation(sf::Vector2i &target, sf::Vector2i &position);


	protected:
	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float m_TargetX;
	float m_TargetY;
	float Vector;
	float TotalSpeed;


	// Define for yourself — is it transformed or not!



};