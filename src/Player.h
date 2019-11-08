class Player
{
	public:
	Player();
	~Player() {};

	void DrawPlayer(sf::RenderWindow *window,float height,float width);
	void moveSelf(float speedX,float speedY);
	void moveClick(sf::RenderWindow* , sf::View, float targetX,float targetY);
	float getTargX();
	float getTargY();
	float getPreviousX();
	float getPreviousY();
	float getPosX();
	float getPosY();

	void setTargX(float);
	void setTargY(float);

	private:
	sf::RectangleShape playFig;
	float previousPointX;
	float previousPointY;
	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float targetX;
	float targetY;
	float Vector;
	float TotalSpeed;
};
