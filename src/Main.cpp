#include "Main.hpp"




int main() {
	int WINDOWS_HEIGHT = 720;
	int WINDOWS_WIDTH = 1280;
	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOWS_WIDTH, WINDOWS_HEIGHT));
	sf::View parallaxView(sf::Vector2f(1256.0f, 1256.0f), sf::Vector2f(WINDOWS_WIDTH, WINDOWS_HEIGHT));
	parallaxView.zoom(0.3f);


	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	player.setFillColor(sf::Color::Red);
	player.setOrigin(10.0f, 10.0f);

	sf::Event evnt;
	MapHandler mapHandl; //Создание карты
	GridInfo infotable;
	Player Figure1;
	bool ToggleParallax = true;

/*
 	const unsigned int Colums = 4;
	const unsigned int Rows = 4;
   	int splineArray[Rows][Colums] = {
		{200,200},
		{400,200},
		{400,400},
		{200,400},

	};
	const unsigned int Colums1 = 4;
	const unsigned int Rows1 = 4;
   	int vertexArray[Rows1][Colums1] = {
		{2, 1, 0, 1},
		{1, 2, 1, 0},
		{0, 1, 2, 1},
		{1, 0, 1, 2},
	}; */


	//view.setCenter(player.getPosition());
	//sf::Vector2f parPos(256.0f, 256.0f);
	//parallaxView.setCenter(parPos);
	 //bool kostyl = 1;
	/* int mouseTarX;
	int mouseTarY; */
			//int i = 0;




	while (window.isOpen()) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		while (window.pollEvent(evnt)) {

		/* 	if (evnt.type==sf::Event::MouseButtonPressed) {
			float pos_x, pos_y;
			Figure1.setTargX(dote[i].getPosition().x);
			Figure1.setTargY(dote[i].getPosition().y);
			Figure1.moveClick(&window, view, Figure1.getTargX(),Figure1.getTargY());
			pos_x=Figure1.getPosX();
			pos_y=Figure1.getPosY();
			if (((abs(pos_x-Figure1.getTargX()))<=5)&&((abs(pos_y-Figure1.getTargY()))<=5)) {
				i++;
			} */

			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Enter) {
				Figure1.setPosition(585.0f, 282.0f);
			}
		/* 	if (evnt.type == sf::Event::MouseButtonReleased && (evnt.mouseButton.button ==  sf::Mouse::Right)) {
				for (unsigned int i = 0; i < allVertex.size(); i++) {
					if (allVertex[i].checkIsOn(Figure1.getTransformedPosition())) {
						for (unsigned int a = 0; a < allVertex.size(); a++) {
							if (allVertex[a].checkIsClicked(&window, mousePos, view)) {
								for (unsigned int k = 0; k < allVertex[i].getConnectionCodesVectorSize(); k++) {
									if (allVertex[a].getID() == allVertex[i].getConnectionCode(k)) {
										Figure1.moveClick(&window, view,
														  allVertex[a].getTransformedVertexPosition().x,
														  allVertex[a].getTransformedVertexPosition().y);
									}
								}
							}
						}
					}
				}
			} */


	/* 	if (evnt.type == sf::Event::MouseButtonPressed && (evnt.mouseButton.button ==  sf::Mouse::Left)
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: M)) {
			for ( unsigned int i = 0; i < allVertex.size(); i++ ) {
				if (allVertex[i].checkIsClicked(&window, mousePos, view)) {
					allVertex[i].setPosition(mousePos);
				}

			}
		} */
		if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Tilde) {
			for (unsigned int i = 0; i < mapHandl.allVertex.size(); i++) {
				mapHandl.allVertex[i].toggleVisibility();
			}
		}
		if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::P) {

			ToggleParallax = (ToggleParallax ? false : true);
		}

		if (evnt.type == sf::Event::MouseButtonReleased && (evnt.mouseButton.button ==  sf::Mouse::Right)) {

			Figure1.moveToVertex( window, mapHandl, mousePos, view);

		}
		switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "New window width: " << evnt.size.width << "New window height: " << evnt.size.height;
					break;
				default:
				break;
			}
		}

		if (mousePos.x > WINDOWS_WIDTH - 10) { // Перемещение видов, позже бует вынесено в отдельный объект
			view.move(5.0f, 0.0f);
			parallaxView.move(0.3f, 0.0f);

		} else if (mousePos.x < 10) {
			view.move(-5.0f, 0.0f);
			parallaxView.move(-0.3f, 0.0f);

		} else if (mousePos.y < 5) {
			view.move(0.0f, -5.0f);
			parallaxView.move(0.0f, -0.3f);

		} else if (mousePos.y > WINDOWS_HEIGHT - 10) {
			view.move(0.0f, 5.0f);
			parallaxView.move(0.0f, 0.3f);

		}




		window.clear();

		window.setView(parallaxView);
		if (ToggleParallax) {mapHandl.drawParallax(&window);}


		window.setView(view);
		mapHandl.drawMap(&window);

		Figure1.DrawPlayer(&window, 30.0f, 30.0f);
		Figure1.move(window, view);
		infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
						   Figure1.getPreviousX(), Figure1.getPreviousY());

 			for (unsigned int i = 0; i < mapHandl.getVertexArray().size(); i++ ) {
				mapHandl.allVertex[i].draw(&window, view);

			}
			//allVertex[i].checkIsClicked(&window, mousePos, view);




		window.display();
	}

	return 0;
}
