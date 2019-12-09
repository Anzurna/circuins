class background
{
		public:
		float WindowWidth;
		float WindowHeight;
		float SizeXTexture;
		float SizeYTexture;
		float multiplierX;
		float multiplierY;
		float multiplier;
		std::string File;
		sf::Texture backgroundTexture;
		sf::Sprite sprite;
		background(std::string F, int W, int H)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			backgroundTexture.loadFromFile("content/interface/" + File);
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