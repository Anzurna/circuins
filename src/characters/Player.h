
class Player
{
	public:
	Player();
	~Player() {};

	void DrawPlayer(sf::RenderWindow *window);
	void moveSelf(float speedX,float speedY);
	void moveClick(sf::RenderWindow& , sf::View, float targetX,float targetY);
	std::vector<int> moveToVertex( sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder);
	float getTargX();
	float getTargY();
	float getPreviousX();
	float getPreviousY();
	float getPosX();
	float getPosY();
	sf::Vector2i getTransformedPosition();
	void move(sf::RenderWindow& window, sf::View view, int& ia);
	void move(sf::RenderWindow& window, sf::View view, int& ia, float dt);
	void move(sf::RenderWindow& window, sf::View view, MapHandler& mapHandl, float dt);
	void eventListener(sf::Event &event, sf::RenderWindow& window,
	MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder);
	std::vector<int> getPath() { return this -> m_path; };

	void setTargX(float);
	void setTargY(float);
	void setPosition(float, float);

	bool getIsPathExists() { return this -> isPathExists; };



	//std::vector<int> algorithmDijkstra(int start, int finish);


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
	int m_step;
	sf::Vector2i transformedPlayerPosition;
	std::vector <int> m_path;
	bool isPathExists;

};
