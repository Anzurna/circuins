class MainMenu
{
	public:
	int WINDOWS_HEIGHT;
	int WINDOWS_WIDTH;
	int WindowSizeX;
	int WindowSizeY;
	int Volume;

	Setting settingWindow;
	Credits creditsWindow;
	Button setting;
	Button credits;
	Button play;
	Button exit;
	Name name;
	Background background;
	Slider slider;
	std::fstream VolumeFile;
	MainMenu(int WH, int WW)
	{
		WINDOWS_HEIGHT = WH;
		WINDOWS_WIDTH = WW;
		Setting settingWindow("dopWindow.png", "sound.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT, 50, 100);
		Credits creditsWindow("dopWindow.png", "autors.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT);
		Button exit("exit.png", 700, 100, 450, 790);
		Button setting("settings.png", 700, 100, 450, 570);
		Button credits("credits.png", 700, 100, 450, 680);
		Button play("start.png", 700, 100, 450, 460);
		Name name("logo.png", 700, 200, 450, 20);
		Background background("parallaxT1.bmp", 2000, 2000);
		Slider slider("Scale.png", 500, 30, "pointer.png", 40, 50, 500, 270);
		background.setWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
		background.reSize();

		VolumeFile.open("src/Volume.txt");
		VolumeFile >> Volume;
		slider.setPointerPosition(Volume);
		VolumeFile.close();
	}
	int getWindowsHeight()
	{
		return WINDOWS_HEIGHT;
	}
	int getWindowsWidth()
	{
		return WINDOWS_WIDTH;
	}

	void newWindowSize(int X, int Y)
	{
		exit.setWindowSize(X, Y);
		setting.setWindowSize(X, Y);
		play.setWindowSize(X, Y);
		credits.setWindowSize(X, Y);
		name.setWindowSize(X, Y);
		background.setWindowSize(X, Y);
	}
	void disableSettingAndCreditsWindow()
	{
		settingWindow.setSettingEnabled(false);
		creditsWindow.setCreditsEnabled(false);
	}
	void enableSetting()
	{
		settingWindow.setSettingEnabled(true);
		settingWindow.slider.setNewPosition(500,100);
	}
	void enableCredits()
	{
		creditsWindow.setCreditsEnabled(true);
	}
	void newValueVolume(int X)
	{
		VolumeFile.open("src/Volume.txt");
		VolumeFile <<slider.newValue(X) << std::endl;
		VolumeFile.close();
	}
	void newElementPosition(int X, int Y)
	{
		exit.newButtonPosition(1);
		setting.newButtonPosition(3);
		play.newButtonPosition(4);
		credits.newButtonPosition(2);
		name.newNamePosition();
		settingWindow.newSettingPosition(X, Y);
		background.reSize();
	}
	void menuDraw(sf::RenderWindow *window)
	{
		background.drawBackground(window);
		if (!settingWindow.getSettingEnabled() && !creditsWindow.getCreditsEnabled())
		{
		exit.drawButton(window);
		setting.drawButton(window);
		credits.drawButton(window);
		play.drawButton(window);
		name.drawName(window);
		}
		if (settingWindow.getSettingEnabled())
		{
			settingWindow.drawSetting(window);
			slider.drawSlider(window);
		}
		if (creditsWindow.getCreditsEnabled())
		{
			creditsWindow.drawCredits(window);
		}

	}
};




