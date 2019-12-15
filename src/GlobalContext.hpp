class GlobalContext {
	public:
	GlobalContext();
	~GlobalContext(){};
	bool getIsGameStateActive() { return this -> IsGameStateActive;}
	void setGameStateActive(bool condition) { this -> IsGameStateActive = condition; }


	private:
	bool IsGameStateActive;


};