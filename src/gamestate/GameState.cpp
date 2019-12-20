GameState::GameState(int width, int height)
{
	m_width = width;
	m_height = height;
	IsGameStateActive = true;

	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(m_width, m_height));

	parallaxView.setCenter(sf::Vector2f(1256.0f, 1256.0f));
	parallaxView.setSize(sf::Vector2f(500, 500));

	parallaxView.zoom(0.3f);
}



void GameState::handle(sf::Event& evnt, sf::RenderWindow& window, /* sf::Vector2i& mousePos, */ GlobalContext& glob)
{
	sf::RectangleShape test(sf::Vector2f(40.0f, 40.0f));
	m_pathfinder.init(mapHandl);
	std::list<Movable*> allMovingObjects;
	const std::list<Movable*>::iterator iterToPlayer;
	std::list<Movable*>::iterator drawingIter;
	std::list<Movable*>::iterator collideIter1;
	std::list<Movable*>::iterator collideIter2;

	sf::Clock clock;
	float Time = 0;
	float Time2 = 0;
	float Time3 = 0;

	std::vector<Player> enemies;
	enemies.push_back(Player());
	enemies[0].setPosition(800.0, 800.0);
	enemies[0].setHP(500);
	enemies[0].setTeam(2);
	//Character mainCharacter1;

	allMovingObjects.push_back(&enemies.back());

	Player mainPlayer;
	allMovingObjects.push_back(&mainPlayer);
	mainPlayer.setHP(500);
	//*iterToPlayer = allMovingObjects.back();

	while (glob.getIsGameStateActive()) {
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt)) {

			//Place event listeners here

			mainPlayer.eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			//eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			// Заняты клавиши R, L и ПКМ (12.12.19)

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
			if (evnt.type == sf::Event::MouseButtonReleased && (evnt.mouseButton.button ==  sf::Mouse::Left)) {


			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Time3 > 0.3) {
				sf::Vector2i transformedMousePosition;
				transformedMousePosition.x  = (int)(window.mapPixelToCoords( mousePos1, view ).x);
				transformedMousePosition.y  = (int)(window.mapPixelToCoords( mousePos1, view ).y);
				mainPlayer.fire(allMovingObjects, transformedMousePosition);
				Time3 = 0;
			}
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

		if (Time > 1.0) {
			if (abs(mainPlayer.getPosition().x - enemies[0].getPosition().x) < 1000 &&
				abs(mainPlayer.getPosition().y - enemies[0].getPosition().y) < 1000) {
					enemies[0].fire(allMovingObjects, {(int)mainPlayer.getPosition().x,
								   (int)mainPlayer.getPosition().y});
				}
			Time = 0;
		}

			for (collideIter1 = allMovingObjects.begin(); collideIter1 != allMovingObjects.end(); ++collideIter1) {
				for (collideIter2 = allMovingObjects.begin(); collideIter2 != allMovingObjects.end(); ++collideIter2) {
					if ((abs((**collideIter1).getPosition().x - ((**collideIter2).getPosition().x)) < 50) &&
					abs((**collideIter1).getPosition().y - ((**collideIter2).getPosition().y) < 50)) {
						if ((**collideIter1).getTeam() != (**collideIter2).getTeam()) {
							if (Time2 > 0.2f) {
								(**collideIter1).changeHP(-20);
								Time2 = 0;
							}
							if ((**collideIter2).getType() == 1) {
								(**collideIter2).Movable::~Movable();
								allMovingObjects.erase(collideIter2--);
							}
						}
					}
				}
			}


				//infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
							//	   Figure1.getPreviousX(), Figure1.getPreviousY());
		mainPlayer.realTimeListener();
			if (abs(mainPlayer.getPosition().x - enemies[0].getPosition().x) > 200 &&
				abs(mainPlayer.getPosition().y - enemies[0].getPosition().y) > 200 ) {
						float s1 =  enemies[0].calculateSpeedAndRotation({(int)mainPlayer.getPosition().x, (int)mainPlayer.getPosition().y},
									{(int)enemies[0].getPosition().x, (int)enemies[0].getPosition().y}).speed.x;
						float s2 =  enemies[0].calculateSpeedAndRotation({(int)mainPlayer.getPosition().x, (int)mainPlayer.getPosition().y},
									{(int)enemies[0].getPosition().x, (int)enemies[0].getPosition().y}).speed.y;
						float deg = enemies[0].calculateSpeedAndRotation({(int)mainPlayer.getPosition().x, (int)mainPlayer.getPosition().y},
									{(int)enemies[0].getPosition().x, (int)enemies[0].getPosition().y}).degrees;
						enemies[0].move((s1/1.3)-1, (s2/1.3)-1);
						enemies[0].setRotation(deg);
				}



		window.clear();
		//window.setView(parallaxView);
		if (ToggleParallax) { mapHandl.drawParallax(&window); }

		window.setView(view);
		mapHandl.drawMap(&window);
		view.setCenter(mainPlayer.getPosition());
		parallaxView.setCenter({mainPlayer.getPosition().x + 1256, mainPlayer.getPosition().y + 1256});

		//std::cout << speedToNextPointX << " " << speedToNextPointY << std::endl;
		for (drawingIter = allMovingObjects.begin(); drawingIter != allMovingObjects.end(); ++drawingIter) {
			(**drawingIter).draw(&window);
			(**drawingIter).move();
		}
		if (mainPlayer.getIsPathExists()){
			mainPlayer.move(window, view, mapHandl, clock.getElapsedTime().asSeconds());
		}

		for (unsigned int i = 0; i < mapHandl.getVertexArray().size(); i++ ) {
			mapHandl.allVertex[i].draw(&window, view);
		}
		window.display();
		Time += clock.getElapsedTime().asSeconds();
		Time2 += clock.getElapsedTime().asSeconds();
		Time3 += clock.getElapsedTime().asSeconds();
		/* if (Time2 > 0.3)
			Time2 = 0; */
		clock.restart();
	}
}

/* void GameState::drawScene(sf::RenderWindow& window) {


} */