class button {
		public:
		int ButtonX;
		int ButtonY;
		int SizeXTexture;
		int SizeYTexture;
		int SizeX;
		int SizeY;
		int WindowWidth;
		int WindowHeight;
		int MousePosX;
		int MousePosY;
		std::string File;
		sf::Texture buttonTexture;
		sf::Sprite sprite;
		button(std::string F, int W, int H, int X, int Y)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			SizeX = W;
			SizeY = H;
			ButtonX = X;
			ButtonY = Y;
			buttonTexture.loadFromFile("content/interface/" + File);
			sprite.setTexture(buttonTexture);
		}
		void draw()
		{
			sprite.setPosition(sf::Vector2f(ButtonX, ButtonY));
		}
		void buttonPosition(int ButtonNumberDown)
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
		bool isPressed(int MousePosX, int MousePosY)
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
		void setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

};