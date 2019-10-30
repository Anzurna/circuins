#include "LineGenerator.h"

LineGenerator:: LineGenerator(){
	lengthOfArray = 3600;
	vect = sf::Vector2f(300.0f, 0.5f);
	vect2 = sf::Vector2f(350.0f, 0.5f);
	objLine.setPosition(600.0f, 360.0f);
}
void LineGenerator::drawMultipleLines(sf::RenderWindow *m_window)
{ //, int m_array[2][10], int m_lengthOfArray
	for(lineCounter =0; (lineCounter < lengthOfArray); lineCounter++)
	{

		if (lineCounter % 2 == 0)
		{
		objLine.setFillColor(sf::Color::Cyan);
		objLine.setSize(vect);

		}
		if (lineCounter % 2 != 0)
		{
			objLine.setFillColor(sf::Color::Black);
			objLine.setSize(vect2);
		}
		if (lineCounter % 3 != 0)
		{
			objLine.setFillColor(sf::Color::Yellow);
		}
		objLine.setRotation((float)(lineCounter*0.1));
		m_window -> draw(objLine);
	}
}