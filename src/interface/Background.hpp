class Background
{
		public:
		float WindowWidth;
		float WindowHeight;
		float SizeXTexture;
		float SizeYTexture;
		float multiplierX;
		float multiplierY;
		float multiplier;
		public:
		std::string File;
		sf::Texture backgroundTexture;
		sf::Sprite sprite;
		Background(std::string F, int W, int H);

		Background() {};

		~Background() {};

		void reSize();

		void setWindowSize(int sizeX, int sizeY);

		void drawBackground(sf::RenderWindow *window);
};