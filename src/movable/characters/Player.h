
class Player
{
	public:
	Player();
	//Player(int team, int HP){this -> m_team = team;};
	~Player() {};

	void DrawPlayer(sf::RenderWindow *window);
	void moveSelf(float speedX,float speedY);
	void moveClick(sf::RenderWindow& , sf::View, float targetX,float targetY);
	void moveToVertex( sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view);
	float getTargX();
	float getTargY();
	float getPreviousX();
	float getPreviousY();
	float getPosX();
	float getPosY();
	int getHP() {return this -> HP;};
	sf::Vector2i getTransformedPosition();
	void move(sf::RenderWindow& window, sf::View view);

	void changeHP(int amount);

	void setTargX(float);
	void setTargY(float);
	void setPosition(float, float);
	void setHP(int amount);
	void setTeam(int amount);


	private:
	sf::RectangleShape playFig;
	sf::Texture PlayerTexture;
	sf::RectangleShape alignHelper;
	float previousPointX;
	float previousPointY;
	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float m_TargetX;
	float m_TargetY;
	float Vector;
	float TotalSpeed;
	int HP;
	int m_team;
	sf::Vector2i transformedPlayerPosition;

};
