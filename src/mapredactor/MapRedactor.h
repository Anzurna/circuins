class MapRedactor
{
	private:
	int redactcount;

	public:
	MapRedactor();
	~MapRedactor() {};
	void SetRedact(sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view);
	void MoveRedact(MapHandler& MapHndl,float speedx, float speedy);
	void Reset(MapHandler& MapHndl);
	void WriteFile(MapHandler& MapHndl);

};