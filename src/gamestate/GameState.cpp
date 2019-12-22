GameState::GameState(int width, int height)
{
	m_width = width;
	m_height = height;
	IsGameStateActive = true;

	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(m_width, m_height));

	parallaxView.setCenter(sf::Vector2f(1256.0f, 1256.0f));
	parallaxView.setSize(sf::Vector2f(500, 500));
	view.zoom(1.5f);
	parallaxView.zoom(0.3f);
}



void GameState::handle(sf::Event& evnt, sf::RenderWindow& window, /* sf::Vector2i& mousePos, */ GlobalContext& glob)
{
	sf::RectangleShape test(sf::Vector2f(40.0f, 40.0f));
	MapRedactor mp;
	mp.ReadFile(mapHandl, "C:\\SFMLprojects\\myproject\\content\\map.txt");
	m_pathfinder.init(mapHandl);
	std::list<Movable*> allMovingObjects;
	std::list<Movable*>::iterator iterToPlayer;
	std::list<Movable*>::iterator drawingIter;
	std::list<Movable*>::iterator collideIter1;
	std::list<Movable*>::iterator collideIter2;
	//const Movable* toPlayer;

	SoundProducer soundProd;
	sf::Clock clock;
	float Time = 0;
	float Time2 = 0;
	float Time3 = 0;

	std::vector<Enemy> enemies;
	for (int u = 0; u < 4; u++) {
		enemies.push_back(Enemy());
		enemies[u].setPosition(800.0+20*u, 800.0);
		enemies[u].setID(u);
		enemies[u].setHP(500);
		enemies[u].setTeam(2);
		enemies[u].setHasKey();
	}
	for (int u = 0; u < 4; u++) {
		allMovingObjects.push_back(&enemies[u]);
	}

	//Character mainCharacter1;


	Player mainPlayer;
  //	toPlayer = &mainPlayer;
	allMovingObjects.push_back(&mainPlayer);
	mainPlayer.setPosition(6000, 6000);
	mainPlayer.setHP(500);
	view.setCenter(6000, 6000);
/* 	Enemy en;
	en.setTeam(2);
	allMovingObjects.push_back(&en); */

	while (glob.getIsGameStateActive()) {
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt)) {

			//Place event listeners here

			mainPlayer.eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			//eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			// Заняты клавиши R, L и ПКМ (12.12.19)
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::R) {
				mainPlayer.setPosition(mapHandl.allVertex[0].getPosX(), mapHandl.allVertex[0].getPosY());
			}

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
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Space) {
				view.setCenter(mainPlayer.getPosition());
			}

					//Нажать backspace чтобы вызвать редактор карты
		 if (evnt.type==sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Backspace) {
			 if (mapRed==false) mapRed=true; else mapRed=false;
			 /*mapRedct.Reset(mapHandl);
			redact=true;*/

		}

		if (mapRed==true) {
			mapRedct.EventListener(evnt,window,mapHandl,mousePos1,view);
		}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Time3 > 0.1) {
				sf::Vector2i transformedMousePosition;
				transformedMousePosition.x  = (int)(window.mapPixelToCoords( mousePos1, view ).x);
				transformedMousePosition.y  = (int)(window.mapPixelToCoords( mousePos1, view ).y);
				mainPlayer.fire(allMovingObjects, transformedMousePosition);
				soundProd.soundShoot();
				Time3 = 0;
			}
		}




			if (mousePos1.x > m_width - 10) { // Перемещение видов, позже бует вынесено в отдельный объект
			view.move(18.0f, 0.0f);
			parallaxView.move(0.3f, 0.0f);

		} else if (mousePos1.x < 10) {
			view.move(-18.0f, 0.0f);
			parallaxView.move(-0.3f, 0.0f);

		} else if (mousePos1.y < 5) {
			view.move(0.0f, -18.0f);
			parallaxView.move(0.0f, -0.3f);

		} else if (mousePos1.y > m_height - 10) {
			view.move(0.0f, 18.0f);
			parallaxView.move(0.0f, 0.3f);
		}



		for (collideIter1 = allMovingObjects.begin(); collideIter1 != allMovingObjects.end(); ++collideIter1) {
			for (collideIter2 = allMovingObjects.begin(); collideIter2 != allMovingObjects.end(); ++collideIter2) {
				if ((abs((**collideIter1).getPosition().x - ((**collideIter2).getPosition().x)) < 50) &&
					abs((**collideIter1).getPosition().y - ((**collideIter2).getPosition().y)) < 50) {
					if ((**collideIter1).getTeam() != (**collideIter2).getTeam()) {
						if ((**collideIter2).getType() == 1 && ((**collideIter1).getType() != 1)) {
							(**collideIter1).changeHP(-50);
							(**collideIter2).Movable::~Movable();
							allMovingObjects.erase(collideIter2--);
						}
					}
					if ((**collideIter1).getType() == 0 && ((**collideIter2).getType() == 3 )) {
						mainPlayer.addKey();
						}
				if ((**collideIter2).getType() == 2 && ((**collideIter2).getHP() <= 0)) {
					(**collideIter2).Movable::~Movable();
					allMovingObjects.erase(collideIter2--);
				}
				if ((**collideIter1).getType() == 0 && ((**collideIter1).getHP() <= 0)) {
					mainPlayer.setPosition(6000, 6000);
					mainPlayer.setHP(500);
				}

			}
		}
		}


				//infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
							//	   Figure1.getPreviousX(), Figure1.getPreviousY());
		mainPlayer.realTimeListener();

		window.clear();
		//window.setView(parallaxView);

		if (ToggleParallax) { mapHandl.drawParallax(&window); }

		window.setView(view);
		mapHandl.drawMap(&window);
		//view.setCenter(mainPlayer.getPosition());
		parallaxView.setCenter({mainPlayer.getPosition().x + 1256, mainPlayer.getPosition().y + 1256});

		//std::cout << speedToNextPointX << " " << speedToNextPointY << std::endl;
		for (drawingIter = allMovingObjects.begin(); drawingIter != allMovingObjects.end(); ++drawingIter) {
			(**drawingIter).behave(allMovingObjects, mainPlayer.getPosition(), clock.getElapsedTime().asSeconds());
			(**drawingIter).handle(allMovingObjects, drawingIter, clock.getElapsedTime().asSeconds());
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