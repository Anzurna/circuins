class LineGenerator
{
public:
	LineGenerator();
	~LineGenerator() {};
	void drawMultipleLines(sf::RenderWindow *m_window);// , int m_array[2][10], int m_lengthOfArray

private:
int lineCounter;
int lengthOfArray;
sf:: RectangleShape objLine;
sf::Vector2f vect;
sf::Vector2f vect2;
};
