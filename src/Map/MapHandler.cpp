

MapHandler::MapHandler()
{
	mapTile1.loadFromFile("content/MapTiles/connectionCentralNode.png");
/* 	mapTile2.loadFromFile("content/MapTiles/map2.bmp");
	mapTile3.loadFromFile("content/MapTiles/map3.bmp");
	mapTile4.loadFromFile("content/MapTiles/map4.bmp"); */

	parallaxTile1.loadFromFile("content/MapTiles/testparallax.png");

	mapTile_1.setSize(sf::Vector2f(1000.0f,1000.0f));
/* 	mapTile_2.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_3.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_4.setSize(sf::Vector2f(512.0f,512.0f)); */

	parallaxTile_1.setSize(sf::Vector2f(1920.0f,1080.0f));
	parallaxTile_2.setSize(sf::Vector2f(1920.0f,1080.0f));
	parallaxTile_3.setSize(sf::Vector2f(1920.0f,1080.0f));
	parallaxTile_4.setSize(sf::Vector2f(1920.0f,1080.0f));

	mapTile_1.setTexture(&mapTile1);
/* 	mapTile_2.setTexture(&mapTile2);
	mapTile_3.setTexture(&mapTile3);
	mapTile_4.setTexture(&mapTile4); */

	parallaxTile_1.setTexture(&parallaxTile1);
	parallaxTile_2.setTexture(&parallaxTile1);
	parallaxTile_3.setTexture(&parallaxTile1);
	parallaxTile_4.setTexture(&parallaxTile1);
/*
	mapTile_2.setPosition(0.0f, mapTile_1.getPosition().y - mapTile1.getSize().y);
	mapTile_3.setPosition(512.0f, -512.0f);
	mapTile_4.setPosition(512.0f, 0); */

	parallaxTile_1.setPosition(0.0f, 0.0f);
	parallaxTile_2.setPosition(-1920.0f, 0.0f);
	parallaxTile_3.setPosition(0.0f, -1080.0f);
	parallaxTile_4.setPosition(-1920.0f, -1080.0f);



	std::vector<unsigned int> dummyArr1 = {2,3,4,5,6,7,8,9};
	std::vector<unsigned int> dummyArr2 = {1};
	std::vector<unsigned int> dummyArr3 = {1};
	std::vector<unsigned int> dummyArr4 = {1};
	std::vector<unsigned int> dummyArr5 = {1};



	allVertex[0].init(1, {526, 520}, dummyArr1);
	allVertex[1].init(2, {135, 876}, dummyArr2);
	allVertex[2].init(3, {863, 848}, dummyArr3);
	allVertex[3].init(4, {189, 186}, dummyArr4);
	allVertex[4].init(5, {835, 200}, dummyArr5);

}

void MapHandler::drawMap(sf::RenderWindow* window)
{

	window -> draw(mapTile_1);
	window -> draw(mapTile_2);
	window -> draw(mapTile_3);
	window -> draw(mapTile_4);


}
void MapHandler::drawParallax(sf::RenderWindow* window)
{
	window -> draw(parallaxTile_1);
	window -> draw(parallaxTile_2);
	window -> draw(parallaxTile_3);
	window -> draw(parallaxTile_4);
}

std::vector<Vertex> MapHandler::getVertexArray()
{
	return this -> allVertex;
}
Vertex MapHandler::getVertexArrayElement(unsigned int index)
{
	return this -> allVertex[index];
}