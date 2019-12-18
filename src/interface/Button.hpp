class Button {
		int ButtonPositionX;
		int ButtonPositionY;
		int SizeXTexture;
		int SizeYTexture;
		int SizeXButton;
		int SizeYButton;
		int WindowWidth;
		int WindowHeight;
		public:
		std::string File;
		sf::Texture buttonTexture;
		sf::Sprite sprite;

		Button(std::string F, int W, int H, int X, int Y);

		Button() {};

		~Button() {};

		void drawButton(sf::RenderWindow *window);

		void newButtonPosition(int ButtonNumberDown);

		bool isPressed(int MousePosX, int MousePosY);

		void setPosition(int buttonXAdd, int buttonYAdd);

		void setWindowSize(int sizeX, int sizeY);


};