class Name
{		public:
		int NameX;
		int NameY;
		int SizeXTexture;
		int SizeYTexture;
		int SizeX;
		int SizeY;
		int WindowWidth;
		int WindowHeight;
		std::string File;
		sf::Texture nameTexture;
		sf::Sprite sprite;
		Name(std::string F, int W, int H, int X, int Y);

		void draw();

		void namePosition();

		void setPosition(int nameXAdd, int nameYAdd);
		void setWindowSize(int sizeX, int sizeY);

};