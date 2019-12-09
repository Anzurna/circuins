#include "Main.hpp"

using namespace sf;
using namespace std;

class background
{
		float WindowWidth;
		float WindowHeight;
		float SizeXTexture = 3000.0;//размер текстуры ставим вручную
		float SizeYTexture = 2000.0;//размер текстуры ставим вручную
		float multiplierX;
		float multiplierY;
		float multiplier;

	public:

		Texture backgroundTexture;
		Sprite sprite;
		background()
		{
			backgroundTexture.loadFromFile("content/interface/background.png");
			sprite.setTexture(backgroundTexture);
		}

		void reSize()
		{
			multiplierX = WindowWidth / SizeXTexture;
			multiplierY = WindowHeight / SizeYTexture;
			if (multiplierX > multiplierY)
			{
				multiplier = multiplierX;
			}
			else
			{
				multiplier = multiplierY;
			}
			sprite.setScale(multiplier, multiplier);
		}

		void setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}
};

class button {

		int ButtonX;
		int ButtonY;
		int SizeXTexture = 500;//размер текстуры ставим вручную
		int SizeYTexture = 100;//размер текстуры ставим вручную
		int SizeX = SizeXTexture;
		int SizeY = SizeYTexture;
		int WindowWidth;
		int WindowHeight;
		int ButtonNumberDown;
		int MousePosX;
		int MousePosY;

	public:

		Texture buttonTexture;
		Sprite sprite;
		button()
		{
			buttonTexture.loadFromFile("content/interface/Button.png");
			sprite.setTexture(buttonTexture);
		}

		void draw()
		{
			sprite.setPosition(Vector2f(ButtonX, ButtonY));
		}

		void buttonPosition()
		{
			if ((WindowWidth >= 900) && (WindowHeight >= 630))// размер минимального окна ставим вручную
			{
				SizeX = SizeXTexture;
				SizeY = SizeYTexture;
				sprite.setScale(1.0f, 1.0f);
			}
			else
			{
				SizeX = (SizeXTexture / 2);
				SizeY = (SizeYTexture / 2);
				sprite.setScale(0.5f, 0.5f);
			}

			ButtonX = ((WindowWidth - SizeX) / 2);
			ButtonY = WindowHeight - ((SizeY + 20) * ButtonNumberDown);
			draw();
		}

		bool buttonPressed(int MousePosX, int MousePosY)
		{

			if (((MousePosX > ButtonX) && (MousePosX < (ButtonX + SizeX))) && ((MousePosY > ButtonY) && (MousePosY < (ButtonY + SizeY))))
			{
				return true;
			}
			else
			{
				return false;
			}

		}

		void setPosition(int buttonXAdd, int buttonYAdd)
		{
			ButtonX = buttonXAdd;
			ButtonY = buttonYAdd;
		}

		void setNumber(int number)
		{
			ButtonNumberDown = number;
		}

		void setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

};

class name
{

		int NameX;
		int NameY;
		int SizeXTexture = 860;//размер текстуры ставим вручную
		int SizeYTexture = 200;//размер текстуры ставим вручную
		int SizeX;
		int SizeY;
		int WindowWidth;
		int WindowHeight;

	public:

		Texture nameTexture;
		Sprite sprite;
		name()
		{
			nameTexture.loadFromFile("content/interface/Name.png");
			sprite.setTexture(nameTexture);
		}

		void draw()
		{
			sprite.setPosition(Vector2f(NameX, NameY));
		}

		void namePosition()
		{
			if ((WindowWidth >= 900) && (WindowHeight >= 630))// размер минимального окна ставим вручную
			{
				SizeX = SizeXTexture;
				SizeY = SizeYTexture;
				sprite.setScale(1.0f, 1.0f);
			}
			else
			{
				SizeX = (SizeXTexture / 2);
				SizeY = (SizeYTexture / 2);
				sprite.setScale(0.5f, 0.5f);
			}

			NameX = ((WindowWidth - SizeX) / 2);
			NameY = 20;
			draw();
		}

		void setPosition(int nameXAdd, int nameYAdd)
		{
			NameX = nameXAdd;
			NameY = nameYAdd;
		}
		void setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

};

int main() {

	button exit;
	button setting;
	button play;
	name name;
	background background;

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

	exit.setPosition(390, 600);
	exit.setNumber(1);
	exit.draw();
	setting.setPosition(390, 480);
	setting.setNumber(2);
	setting.draw();
	play.setPosition(390, 360);
	play.setNumber(3);
	play.draw();
	name.setPosition(210, 20);
	name.draw();
	background.setWindowSize(1280, 720);
	background.reSize();

	//Заглушка для меню
	sf::RectangleShape startButton(sf::Vector2f(500.0f, 100.0f));
	sf::RectangleShape exitButton(sf::Vector2f(500.0f, 100.0f));
	sf::Texture sb;
	sf::Texture eb;
	sb.loadFromFile("content/interface/startbutn.bmp");
	eb.loadFromFile("content/interface/exitbutn.bmp");
	startButton.setTexture(&sb);
	exitButton.setTexture(&eb);

	startButton.setPosition(400.0f, 300.0f);
	exitButton.setPosition(400.0f, 450.0f);

	while (window.isOpen()) {
		//sf::Vector2i mousePos = sf::Mouse::getPosition(window);

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

		exit.setWindowSize(evnt.size.width, evnt.size.height);
		setting.setWindowSize(evnt.size.width, evnt.size.height);
		play.setWindowSize(evnt.size.width, evnt.size.height);
		name.setWindowSize(evnt.size.width, evnt.size.height);
		background.setWindowSize(evnt.size.width, evnt.size.height);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
				Vector2i mousePos = Mouse::getPosition(window);

				if (exit.buttonPressed(mousePos.x, mousePos.y))
				{
					cout << "It's Work 3!!! " << endl;
					return 1;
				}
				if (setting.buttonPressed(mousePos.x, mousePos.y))
				{
					cout << "It's Work 2!!! " << endl;
				}
				if (play.buttonPressed(mousePos.x, mousePos.y))
				{
					cout << "It's Work 1!!! " << endl;
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
					//std::cout << "New window width: " << evnt.size.width << "New window height: " << evnt.size.height;

					window.setView(
					sf::View(
						sf::Vector2f(evnt.size.width / 2.0, evnt.size.height / 2.0),
						sf::Vector2f(evnt.size.width, evnt.size.height)
						)
					);

					exit.buttonPosition();
					setting.buttonPosition();
					play.buttonPosition();
					name.namePosition();
					background.reSize();
					break;
				default:
				break;
			}
		}

		if(!glob.getIsGameStateActive()) {
		window.clear();
		// Отрисовка меню
		window.draw(startButton);
		window.draw(exitButton);
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
