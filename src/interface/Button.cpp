
		Button::Button(std::string F, int W, int H, int X, int Y)
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
		void Button::draw()
		{
			sprite.setPosition(sf::Vector2f(ButtonX, ButtonY));
		}
		void Button::buttonPosition(int ButtonNumberDown)
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
		bool Button::isPressed(int MousePosX, int MousePosY)
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
		void Button::setPosition(int buttonXAdd, int buttonYAdd)
		{
			ButtonX = buttonXAdd;
			ButtonY = buttonYAdd;
		}
		void Button::setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

