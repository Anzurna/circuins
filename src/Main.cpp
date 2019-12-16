#include "Main.hpp"



int main() {

	Button exit("exit.png", 700, 100, 450, 790);
	Button setting("settings.png", 700, 100, 450, 570);
	Button credits("credits.png", 700, 100, 450, 680);
	Button play("start.png", 700, 100, 450, 460);
	Name name("logo.png", 700, 200, 450, 20);
	Slider slider("Scale.png", 500, 30 , "pointer.png", 40, 50, 390, 300);
	Background background("parallaxT1.bmp", 2000, 2000);

	int WINDOWS_HEIGHT = 900;
	int WINDOWS_WIDTH = 1600;
	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Circuins",sf::Style::Close | sf::Style::Resize);

	window.setFramerateLimit(60);



#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::Event evnt;
	GlobalContext glob;

	background.setWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
	background.reSize();

	std::fstream VolumeFile;
	VolumeFile.open("src/Volume.txt");
	if (VolumeFile.is_open())
	{
		std::cout << "OK" << std::endl;
	}

	slider.setPointerPosition(50);

	while (window.isOpen()) {



		while (window.pollEvent(evnt)) {
			exit.setWindowSize(evnt.size.width, evnt.size.height);
			setting.setWindowSize(evnt.size.width, evnt.size.height);
			play.setWindowSize(evnt.size.width, evnt.size.height);
			credits.setWindowSize(evnt.size.width, evnt.size.height);
			name.setWindowSize(evnt.size.width, evnt.size.height);
			background.setWindowSize(evnt.size.width, evnt.size.height);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (exit.isPressed(mousePos.x, mousePos.y))
				{
					std::cout << "It's Work 4!!! " << std::endl;
					return 1;
				}
				if (credits.isPressed(mousePos.x, mousePos.y))
				{
					std::cout << "It's Work 3!!! " << std::endl;
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
						if (glob.getIsGameStateActive())
						{
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

					exit.newMenuPosition(1);
					setting.newMenuPosition(3);
					play.newMenuPosition(4);
					credits.newMenuPosition(2);
					name.newNamePosition();
					background.reSize();
					break;
				default:
				break;
			}
		}

		if(!glob.getIsGameStateActive()) {
		window.clear();
		background.drawBackground(&window);
		exit.drawButton(&window);
		setting.drawButton(&window);
		credits.drawButton(&window);
		play.drawButton(&window);
		name.drawName(&window);
		window.display();
		}
	}
	VolumeFile.close();
	return 0;
}
