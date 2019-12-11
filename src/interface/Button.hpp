class Button {
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
		Button(std::string F, int W, int H, int X, int Y);

		void draw();

		void buttonPosition(int ButtonNumberDown);

		bool isPressed(int MousePosX, int MousePosY);

		void setPosition(int buttonXAdd, int buttonYAdd);

		void setWindowSize(int sizeX, int sizeY);


};