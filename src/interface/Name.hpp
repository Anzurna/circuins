class Name
{
		int NameXPosition;
		int NameYPosition;
		int SizeXTexture;
		int SizeYTexture;
		int SizeXName;
		int SizeYName;
		int WindowWidth;
		int WindowHeight;
		public:
		std::string File;
		sf::Texture nameTexture;
		sf::Sprite sprite;
		Name(std::string F, int W, int H, int X, int Y);

		Name() {};

		~Name() {};


		void drawName(sf::RenderWindow *window);

		void newNamePosition();

		void setPosition(int nameXAdd, int nameYAdd);

		void setWindowSize(int sizeX, int sizeY);

};