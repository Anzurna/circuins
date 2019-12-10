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
		std::string File;
		sf::Texture backgroundTexture;
		sf::Sprite sprite;
		Background(std::string F, int W, int H);

		void reSize();

		void setWindowSize(int sizeX, int sizeY);
};