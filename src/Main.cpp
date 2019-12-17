#include "Main.hpp"



int main() {

	int WINDOWS_HEIGHT = 900;
	int WINDOWS_WIDTH = 1600;
	int Volume;

	Setting settingWindow("dopWindow.png", "sound.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT, 50, 100);
	Credits creditsWindow("dopWindow.png", "autors.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	Button exit("exit.png", 700, 100, 450, 790);
	Button setting("settings.png", 700, 100, 450, 570);
	Button credits("credits.png", 700, 100, 450, 680);
	Button play("start.png", 700, 100, 450, 460);
	Name name("logo.png", 700, 200, 450, 20);
	Background background("parallaxT1.bmp", 2000, 2000);
	Slider slider("Scale.png", 500, 30, "pointer.png", 40, 50, 500, 270);


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
	VolumeFile >> Volume;
	slider.setPointerPosition(Volume);
	VolumeFile.close();

	while (window.isOpen()) {

		while (window.pollEvent(evnt)) {
			exit.setWindowSize(evnt.size.width, evnt.size.height);
			setting.setWindowSize(evnt.size.width, evnt.size.height);
			play.setWindowSize(evnt.size.width, evnt.size.height);
			credits.setWindowSize(evnt.size.width, evnt.size.height);
			name.setWindowSize(evnt.size.width, evnt.size.height);
			background.setWindowSize(evnt.size.width, evnt.size.height);

			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Escape)
			{
				std::cout << "1" << std::endl;
				settingWindow.setSettingEnabled(false);
				creditsWindow.setCreditsEnabled(false);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (!settingWindow.getSettingEnabled() && !creditsWindow.getCreditsEnabled())
				{
					if (exit.isPressed(mousePos.x, mousePos.y))
					{
						std::cout << "It's Work 4!!! " << std::endl;
						return 1;
					}
					if (credits.isPressed(mousePos.x, mousePos.y))
					{
						std::cout << "It's Work 3!!! " << std::endl;
						creditsWindow.setCreditsEnabled(true);
					}
					if (setting.isPressed(mousePos.x, mousePos.y))
					{
						std::cout << "It's Work 2!!! " << std::endl;
						settingWindow.setSettingEnabled(true);
						settingWindow.slider.setNewPosition(500,100);

					}
					if (play.isPressed(mousePos.x, mousePos.y))
					{
						std::cout << "It's Work 1!!! " << std::endl;
						GameState newGameState(WINDOWS_WIDTH, WINDOWS_HEIGHT);
						glob.setGameStateActive(true);
							if (glob.getIsGameStateActive())
							{
							newGameState.handle(evnt, window,  glob);
							}
					}
				}
				if (settingWindow.getSettingEnabled())
				{
					if (slider.isPressed(mousePos.x, mousePos.y))
					{

						VolumeFile.open("src/Volume.txt");
						VolumeFile <<slider.newValue(mousePos.x) << std::endl;
						VolumeFile.close();

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

					exit.newButtonPosition(1);
					setting.newButtonPosition(3);
					play.newButtonPosition(4);
					credits.newButtonPosition(2);
					name.newNamePosition();
					settingWindow.newSettingPosition(evnt.size.width, evnt.size.height);
					background.reSize();
					break;
				default:
				break;
			}
		}


		if(!glob.getIsGameStateActive()) {
		window.clear();
		background.drawBackground(&window);
		if (!settingWindow.getSettingEnabled() && !creditsWindow.getCreditsEnabled())
		{
		exit.drawButton(&window);
		setting.drawButton(&window);
		credits.drawButton(&window);
		play.drawButton(&window);
		name.drawName(&window);
		}
		if (settingWindow.getSettingEnabled())
		{
			settingWindow.drawSetting(&window);
			slider.drawSlider(&window);
		}
		if (creditsWindow.getCreditsEnabled())
		{
			creditsWindow.drawCredits(&window);
		}
		window.display();
		}
	}
	VolumeFile.close();
	return 0;
}


