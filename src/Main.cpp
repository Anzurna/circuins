#include "Main.hpp"


int main() {

	Button exit("Button.png", 500, 100, 390, 600);
	Button setting("Button.png", 500, 100, 390, 480);
	Button play("Button.png", 500, 100, 390, 360);
	Name name("Name.png", 860, 200, 210, 20);
	Background background("Background.png", 3000, 2000);

	int WINDOWS_HEIGHT = 720;
	int WINDOWS_WIDTH = 1280;
	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Circuins",
							sf::Style::Close | sf::Style::Resize);

	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::Event evnt;
	GlobalContext glob;
	exit.draw();
	setting.draw();
	play.draw();
	name.draw();
	background.setWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
	background.reSize();

	while (window.isOpen()) {



		while (window.pollEvent(evnt)) {
			exit.setWindowSize(evnt.size.width, evnt.size.height);
			setting.setWindowSize(evnt.size.width, evnt.size.height);
			play.setWindowSize(evnt.size.width, evnt.size.height);
			name.setWindowSize(evnt.size.width, evnt.size.height);
			background.setWindowSize(evnt.size.width, evnt.size.height);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (exit.isPressed(mousePos.x, mousePos.y))
				{
					std::cout << "It's Work 3!!! " << std::endl;
					return 1;
				}
				if (setting.isPressed(mousePos.x, mousePos.y))
				{
					std::cout << "It's Work 2!!! " << std::endl;
				}
				if (play.isPressed(mousePos.x, mousePos.y))
				{
					std::cout << "It's Work 1!!! " << std::endl;
					GameState newGameState(WINDOWS_WIDTH, WINDOWS_HEIGHT);
					glob.setGameStateActive(true);
					if (glob.getIsGameStateActive()){
					newGameState.handle(evnt, window, /* mousePos, */ glob);
					//newGameState.drawScene(window);
				}
			}
			}

		switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					window.setView(
					sf::View(
						sf::Vector2f(evnt.size.width / 2.0, evnt.size.height / 2.0),
						sf::Vector2f(evnt.size.width, evnt.size.height)
						)
					);

					exit.buttonPosition(1);
					setting.buttonPosition(2);
					play.buttonPosition(3);
					name.namePosition();
					background.reSize();
					break;
				default:
				break;
			}
		}

		if(!glob.getIsGameStateActive()) {
		window.clear();
		window.draw(background.sprite);
		window.draw(exit.sprite);
		window.draw(setting.sprite);
		window.draw(play.sprite);
		window.draw(name.sprite);
		window.display();
		}
	}
	return 0;
}
