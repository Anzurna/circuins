

MapHandler::MapHandler()
{
	mapTile1.loadFromFile("content/MapTiles/web.png");
/* 	mapTile2.loadFromFile("content/MapTiles/map2.bmp");
	mapTile3.loadFromFile("content/MapTiles/map3.bmp");
	mapTile4.loadFromFile("content/MapTiles/map4.bmp"); */

	parallaxTile1.loadFromFile("content/MapTiles/Image2red.bmp");

	mapTile_1.setSize(sf::Vector2f(1280.0f,720.0f));
/* 	mapTile_2.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_3.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_4.setSize(sf::Vector2f(512.0f,512.0f)); */

	parallaxTile_1.setSize(sf::Vector2f(512.0f,512.0f));

	mapTile_1.setTexture(&mapTile1);
/* 	mapTile_2.setTexture(&mapTile2);
	mapTile_3.setTexture(&mapTile3);
	mapTile_4.setTexture(&mapTile4); */

	parallaxTile_1.setTexture(&parallaxTile1);
/*
	mapTile_2.setPosition(0.0f, mapTile_1.getPosition().y - mapTile1.getSize().y);
	mapTile_3.setPosition(512.0f, -512.0f);
	mapTile_4.setPosition(512.0f, 0); */

	parallaxTile_1.setPosition(1000.0f, 1000.0f);



	std::vector<unsigned int> dummyArr1 = {2,3,4,5,6,7,8,9};
	std::vector<unsigned int> dummyArr2 = {1, 3, 9};
	std::vector<unsigned int> dummyArr3 = {1, 4, 2};
	std::vector<unsigned int> dummyArr4 = {1, 3, 5};
	std::vector<unsigned int> dummyArr5 = {1, 4, 6};
	std::vector<unsigned int> dummyArr6 = {1, 5, 7};
	std::vector<unsigned int> dummyArr7 = {1, 6, 8};
	std::vector<unsigned int> dummyArr8 = {1, 9, 7};
	std::vector<unsigned int> dummyArr9 = {1, 2, 8};


	allVertex[0].init(1, {585, 282}, dummyArr1);
	allVertex[1].init(2, {298, 93}, dummyArr2);
	allVertex[2].init(3, {585, 37}, dummyArr3);
	allVertex[3].init(4, {857, 93}, dummyArr4);
	allVertex[4].init(5, {952, 282}, dummyArr5);
	allVertex[5].init(6, {857, 518}, dummyArr6);
	allVertex[6].init(7, {585, 555}, dummyArr7);
	allVertex[7].init(8, {307, 518}, dummyArr8);
	allVertex[8].init(9, {187, 282}, dummyArr9);
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
}

std::vector<Vertex> MapHandler::getVertexArray()
{
	return this -> allVertex;
}
Vertex MapHandler::getVertexArrayElement(unsigned int index)
{
	return this -> allVertex[index];
}