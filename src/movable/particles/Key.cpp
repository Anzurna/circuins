Key::Key()
{
	this -> m_texture.loadFromFile("content/particles/red1.png");
	this -> m_shape.setTexture(&m_texture);
	this -> m_shape.setSize({60.0f, 15.0f});
	this -> m_type = 3;
}
void Key::draw(sf::RenderWindow *window)
{
	window -> draw(this -> m_shape);
}