#include <Map/MapHandler.h>

MapHandler::MapHandler()
{
	mapTile1.loadFromFile("content/MapTiles/map1(2).png");
	mapTile2.loadFromFile("content/MapTiles/map2.bmp");
	mapTile3.loadFromFile("content/MapTiles/map3.bmp");
	mapTile4.loadFromFile("content/MapTiles/map4.bmp");

	parallaxTile1.loadFromFile("content/MapTiles/Image2red.bmp");

	mapTile_1.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_2.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_3.setSize(sf::Vector2f(512.0f,512.0f));
	mapTile_4.setSize(sf::Vector2f(512.0f,512.0f));

	parallaxTile_1.setSize(sf::Vector2f(512.0f,512.0f));

	mapTile_1.setTexture(&mapTile1);
	mapTile_2.setTexture(&mapTile2);
	mapTile_3.setTexture(&mapTile3);
	mapTile_4.setTexture(&mapTile4);

	parallaxTile_1.setTexture(&parallaxTile1);

	mapTile_2.setPosition(0.0f, mapTile_1.getPosition().y - mapTile1.getSize().y);
	mapTile_3.setPosition(512.0f, -512.0f);
	mapTile_4.setPosition(512.0f, 0);

	parallaxTile_1.setPosition(1000.0f, 1000.0f);
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