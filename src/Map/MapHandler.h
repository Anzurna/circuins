class MapHandler
{
	public:
	MapHandler();
	~MapHandler() {};
	void drawMap(sf::RenderWindow* window);

	private:

	sf:: Texture mapTile1;
	sf:: Texture mapTile2;
	sf:: Texture mapTile3;
	sf:: Texture mapTile4;

	sf::RectangleShape mapTile_1;
	sf::RectangleShape mapTile_2;
	sf::RectangleShape mapTile_3;
	sf::RectangleShape mapTile_4;

};