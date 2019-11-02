class Player
{
	public:
	Player();
	~Player() {};

	void DrawPlayer(sf::RenderWindow *window,float height,float width);
	void moveSelf(float speedX,float speedY);
	//void moveClick(float speedToPointX,float speedToPointY);

	private:
	sf::RectangleShape playFig;
	float previousPointX;
	float previousPointY;
	float speedToNextPointX;
	float xLength;
	float yLength;
	float targetX;
	float targetY;
	float Vector;
	float TotalSpeed=2;
};