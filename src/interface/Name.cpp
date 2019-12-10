
		Name::Name(std::string F, int W, int H, int X, int Y)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			NameX = X;
			NameY = Y;
			nameTexture.loadFromFile("content/interface/" + File);
			sprite.setTexture(nameTexture);
		}

		void Name::draw()
		{
			sprite.setPosition(sf::Vector2f(NameX, NameY));
		}

		void Name::namePosition()
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

		void Name::setPosition(int nameXAdd, int nameYAdd)
		{
			NameX = nameXAdd;
			NameY = nameYAdd;
		}
		void Name::setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

