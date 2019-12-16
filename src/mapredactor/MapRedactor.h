class MapRedactor
{
	private:
	int redactcount;
	int concount;
	bool setconn;
	unsigned int index;
	sf::Vector2f TransformedmousePos;

	public:
	MapRedactor();
	~MapRedactor() {};
	void SetRedact(sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view);
	void MoveRedact(MapHandler& MapHndl,float speedx, float speedy);
	void Reset(MapHandler& MapHndl);
	void SetConnectBasis (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view);
	void DrawConnection (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view);
	void WriteFile(MapHandler& MapHndl);
	void SetVertex(sf::RenderWindow& window,MapHandler& MapHndl,int ID, sf::Vector2i mousePos,
	std::vector<unsigned int> connectionVector,sf::View view);

};