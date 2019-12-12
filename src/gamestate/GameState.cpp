GameState::GameState(int width, int height)
{
	m_width = width;
	m_height = height;
	IsGameStateActive = true;

	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(m_width, m_height));

	parallaxView.setCenter(sf::Vector2f(1256.0f, 1256.0f));
	parallaxView.setSize(sf::Vector2f(m_width, m_height));

	parallaxView.zoom(0.3f);
}



void GameState::handle(sf::Event& evnt, sf::RenderWindow& window, /* sf::Vector2i& mousePos, */ GlobalContext& glob)
{
	sf::RectangleShape test(sf::Vector2f(40.0f, 40.0f));
	m_pathfinder.init(mapHandl);
	while (glob.getIsGameStateActive()) {
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt)) {
			/* if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::R) {
						Figure1.setPosition(585.0f, 282.0f);
					}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::L) {
						Figure1.setPosition(200.0f, 282.0f);
					} */
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Escape) {
						glob.setGameStateActive(false);
				}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Tilde) {
				for (unsigned int i = 0; i < mapHandl.allVertex.size(); i++) {
					mapHandl.allVertex[i].toggleVisibility();
				}
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::P) {
				ToggleParallax = (ToggleParallax ? false : true);
			}
		/* 	if (evnt.type == sf::Event::MouseButtonReleased && (evnt.mouseButton.button ==  sf::Mouse::Right)) {
				Figure1.moveToVertex( window, mapHandl, mousePos1, view, m_pathfinder);
			} */

			Figure1.eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
		}

		if (mousePos1.x > m_width - 10) { // Перемещение видов, позже бует вынесено в отдельный объект
			view.move(5.0f, 0.0f);
			parallaxView.move(0.3f, 0.0f);

		} else if (mousePos1.x < 10) {
			view.move(-5.0f, 0.0f);
			parallaxView.move(-0.3f, 0.0f);

		} else if (mousePos1.y < 5) {
			view.move(0.0f, -5.0f);
			parallaxView.move(0.0f, -0.3f);

		} else if (mousePos1.y > m_height - 10) {
			view.move(0.0f, 5.0f);
			parallaxView.move(0.0f, 0.3f);
		}

		//infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
					//	   Figure1.getPreviousX(), Figure1.getPreviousY());
		window.clear();
		window.setView(parallaxView);
		if (ToggleParallax) { mapHandl.drawParallax(&window); }

		window.setView(view);
		mapHandl.drawMap(&window);

		Figure1.DrawPlayer(&window);
		Figure1.move(window, view);
		for (unsigned int i = 0; i < mapHandl.getVertexArray().size(); i++ ) {
			mapHandl.allVertex[i].draw(&window, view);
		}
		window.display();
	}
}

/* void GameState::drawScene(sf::RenderWindow& window) {


} */