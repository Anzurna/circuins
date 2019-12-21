

class MapHandler
{
	public:

	MapHandler();
	~MapHandler() {};
	void drawMap(sf::RenderWindow* window);
	void drawParallax(sf::RenderWindow*);
	std::vector<Vertex>  getVertexArray();
	Vertex getVertexArrayElement(unsigned int index);

	private:


	sf:: Texture mapTile1;
	sf:: Texture mapTile2;
	sf:: Texture mapTile3;
	sf:: Texture mapTile4;
	sf:: Texture parallaxTile1;

	sf::RectangleShape mapTile_1;
	sf::RectangleShape mapTile_2;
	sf::RectangleShape mapTile_3;
	sf::RectangleShape mapTile_4;

	sf::RectangleShape parallaxTile_1;
	sf::RectangleShape parallaxTile_2;
	sf::RectangleShape parallaxTile_3;
	sf::RectangleShape parallaxTile_4;

	public:

	std::vector<Vertex> allVertex;

};