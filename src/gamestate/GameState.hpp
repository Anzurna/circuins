class GameState {
	public:
	GameState(int width, int height);
	~GameState(){};
	void handle(sf::Event&, sf::RenderWindow&, /* sf::Vector2i&, */ GlobalContext& glob);
	bool getIsGameStateActive() { return this -> IsGameStateActive;}
	void setGameStateActive(bool condition) { this -> IsGameStateActive = condition; }
	//void drawScene(sf::RenderWindow& window);


	private:
	MapHandler mapHandl; //Создание карты
	GridInfo infotable;
	Player Figure1;
	Player Enemy1;
	bool ToggleParallax = true;
	int m_width;
	int m_height;
	bool IsGameStateActive = false;
	sf::View view;
	sf::View parallaxView;

};