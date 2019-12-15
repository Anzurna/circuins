
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
	std::vector<int> moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl,
										  sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder );
	float getTargX();
	float getTargY();
	float getPreviousX();
	float getPreviousY();
	float getPosX();
	float getPosY();
	int getHP() {return this -> HP;};
	sf::Vector2i getTransformedPosition();
	void move(sf::RenderWindow& window, sf::View view);
	void move(sf::RenderWindow& window, sf::View view, int& ia);
	void move(sf::RenderWindow& window, sf::View view, MapHandler& mapHandl, float dt);
	std::vector<int> getPath() { return this -> m_path; };
	void eventListener(sf::Event &event, sf::RenderWindow& window, MapHandler& MapHndl,
						   sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder);

	void fire(std::list<Bullet>& allBullets, sf::Vector2f& mousePos);

	void changeHP(int amount);

	void setTargX(float);
	void setTargY(float);
	void setPosition(float, float);
	void setHP(int amount);
	void setTeam(int amount);

	bool getIsPathExists() { return this -> isPathExists; };
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

	int m_step;
	bool isPathExists;
	sf::Vector2i transformedPlayerPosition;
	std::vector<int> m_path;

};
