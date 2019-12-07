


Player::Player() {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;

	PlayerTexture.loadFromFile("content/CharSprites/Golden/1small.png");
	playFig.setTexture(&PlayerTexture);
//	alignHelper.setFillColor(sf::Color::Green);
//  alignHelper.setSize(sf::Vector2f(40.0f, 5.0f));
}
float Player::getPreviousX()
{
	return (this->previousPointX);
}

float Player::getPreviousY()
{
	return (this->previousPointY);
}

float Player::getTargX()
{
	return (this->m_TargetX);
}

float Player::getTargY()
{
	return (this->m_TargetY);
}

float Player::getPosX()
{
	return (this->playFig.getPosition().x);
}

float Player::getPosY()
{
	return (this->playFig.getPosition().y);
}

sf::Vector2i Player::getTransformedPosition()
{
	return (this->transformedPlayerPosition);
}

void Player::setTargX(float X)
{
	this->m_TargetX = X;
}
void Player::setTargY(float Y)
{
	this->m_TargetY = Y;
}
void Player::setPosition(float x, float y)
{
	this -> playFig.setPosition(x, y);
}



void Player::DrawPlayer(sf::RenderWindow *window)
{

	playFig.setSize(sf::Vector2f(120,120));
	playFig.setOrigin(60.0f,60.0f);

	//playFig.setPosition(20.0f,20.0f);

	window->draw(playFig);

	// Вклчение помощника наведения - линия будет показывать поворот спрайта
	//alignHelper.setPosition(playFig.getPosition().x, playFig.getPosition().y);
	//window->draw(alignHelper);
}
// Дублирование кода в двух функциях, следует отрефакторить
void Player::moveClick(sf::RenderWindow& window, sf::View view, float targetX,float targetY)
{
			transformedPlayerPosition = window.mapCoordsToPixel( playFig.getPosition() , view );
			previousPointX = transformedPlayerPosition.x;
			previousPointY = transformedPlayerPosition.y;
			m_TargetX = targetX;
			m_TargetY = targetY;
			xLength = m_TargetX - previousPointX;
			yLength = m_TargetY - previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed * 3 * (xLength / Vector);
			speedToNextPointY = TotalSpeed * 3 * (yLength / Vector);

			float degrees = atan2(xLength, -yLength) *(180/M_PI) - 90; // Рабочая строчка НЕ ТРОГАТЬ
			playFig.setRotation(degrees);
			std::cout << degrees << std::endl;
			//alignHelper.setRotation(degrees);
/* 			if (abs(xLength) < 4 && abs(yLength) < 4) {
				speedToNextPointX = speedToNextPointY = 0;
			} */
			//playFig.move(speedToNextPointX,speedToNextPointY);
			/* while (true abs(transformedPlayerPosition.x - targetX) >= 15 && abs(transformedPlayerPosition.y - targetY)>=15 ){

			} */
}

void Player::move(sf::RenderWindow& window, sf::View view){
	transformedPlayerPosition = window.mapCoordsToPixel( playFig.getPosition() , view );
	previousPointX = transformedPlayerPosition.x;
	previousPointY = transformedPlayerPosition.y;
	xLength = m_TargetX - previousPointX;
	yLength = m_TargetY - previousPointY;

	if (abs(xLength) < 8 && abs(yLength) < 8) {
				speedToNextPointX = speedToNextPointY = 0;
			} else {
				playFig.move(speedToNextPointX,speedToNextPointY);
			}


}

// Этот большой цикл занимается тем, что двигает нашего игрока между вершинами
// Позже следует внести изменения и выделить его в отдельный независимый кусок кода, потому как идентичный алгоритм будет
// использован для всех прочих неигровых персонажей.
// Имеет место(24.11.19) нарушение инкапсуляции — вектор из вершин, который содержится в экземпляре класса MapHandler
// доступен всем. Это связано с тем, что при возвращении через геттер мне не удалось заставить все это работать.
// Предложения приветствуются.

// Принцип работы цикла:
// 1. Пробегает весь вектор с вершинами
// 2. Если игрок касается вершины (метод checkIsOn класса Vertex), то
// 3. Проверяет кликнута ли какая-либо вершина
// 4. Если кликнута — проверяет, содержится ли она в списке доступных для перемещения(связанных) вершин.
// Для 4 надо вызвать Дейкстру
// 5. Если так, то пасует данные вершины методу MoveClick
void Player::moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view )
{
	for (unsigned int i = 0; i < MapHndl.allVertex.size(); i++) {
		if (MapHndl.allVertex[i].checkIsOn(this -> getTransformedPosition())) {
			for (unsigned int a = 0; a < MapHndl.allVertex.size(); a++) {
				if (MapHndl.allVertex[a].checkIsClicked(window, mousePos, view)) {

					std::vector <int>v =algorithmDijkstra(MapHndl.allVertex[i].getID()-1,MapHndl.allVertex[a].getID()-1);
					//
					std::cout<<"Way: ";
					//вывод пути в виде индексов вершин
					// в этом цикле нужно будет по индексам обратиться к коорданатам вершин, ицициировать туда движение и
					// как-то получить позицию этой вершины, чтобы слудующая итерация цикла инициировала движения уже к следующей(из списка)
					//но я не знаю, как это сделать
					// поэтому пока что только индексы самих вершин
					for (unsigned int j = 1; j<v.size(); j++){
						std::cout<< v[j] << ' ';
						/*this -> moveClick(window, view,
											MapHndl.allVertex[v[i]].getTransformedVertexPosition().x,
											MapHndl.allVertex[v[i]].getTransformedVertexPosition().y);
						this -> getTransformedPosition();*/
					}

					/*for (unsigned int k = 0; k < MapHndl.allVertex[i].getConnectionCodesVectorSize(); k++) {

						if (MapHndl.allVertex[a].getID() == MapHndl.allVertex[i].getConnectionCode(k)) {
							this -> moveClick(window, view,
											MapHndl.allVertex[a].getTransformedVertexPosition().x,
											MapHndl.allVertex[a].getTransformedVertexPosition().y);

					}*/
				}
			}
		}
	}
}

std::vector<int> Player::algorithmDijkstra(int start, int finish)
{

	//попытка сделать расчёт мощности по координатам
	// надо будет пробовать конечно дальше, но в те моменты, когда это работало, жутки лаги были каждый раз все считать
	/*int n = finish;
	int** g = new int* [n];
	for (int i = 0; i < n; i++)
	{
		g[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (MapHndl.allVertex[i].getConnectionCode(j)!=0) {

			int katet1 = pow(((MapHndl.allVertex[j].getTransformedVertexPosition().x)/100) - (MapHndl.allVertex[i].getTransformedVertexPosition().x)/100,2);
			int katet2 = pow(((MapHndl.allVertex[j].getTransformedVertexPosition().y)/100) - (MapHndl.allVertex[i].getTransformedVertexPosition().y)/100,2);
			int sqrr=sqrt(katet1+katet2);
			g[i][j] = sqrr;

			}
			else g[i][j]=0;
		}

			for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << g[i][j] << " ";
		}
			std::cout << std::endl;
	}


	}*/
	//пока задам массив статичный и здес.
	// мощности лучше заранее посчитать в Maphandler.
	// если я х1-х0 (400) буду вовзводиь в квадрат - как катет, то не в один int это не влезет
	// так что лучше сделайте динамический массив или какую-нибудь структуры с мощностями
	const int n = 9;
	int g[n][n]=
	{
	{0, 1, 2, 3, 4, 5, 6, 7, 8},
	{1, 0, 3, 0, 0, 0, 0, 0, 10},
	{2, 3, 0, 5, 0, 0, 0, 0, 0},
	{3, 0, 5, 0, 6, 0, 0, 0, 0},
	{4, 0, 0, 6, 0, 1, 0, 0, 0},
	{5, 0, 0, 0, 1, 0, 3, 0, 0},
	{6, 0, 0, 0, 0, 3, 0, 2, 0},
	{7, 0, 0, 0, 0, 0, 2, 0, 10},
	{8, 10, 0, 0, 0, 0, 0, 10, 0}
	};

	std::list<int> way;
	int inf = 3000;
	std::vector <int> d(n, inf);
	std::vector p(n, -1);
	std::vector <bool> used(n);
	//int start = 0, finish = 4;
	int mn, u;
	d[start] = 0;
	for (int i = 0; i < n; ++i) {
		mn = inf, u = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && d[j] < mn)
				mn = d[j], u = j;
		used[u] = true;
		for (int j = 0; j < n; ++j)
			if (d[j] > d[u] + g[u][j] && g[u][j] > 0)
				d[j] = d[u] + g[u][j], p[j] = u;
	}
	std::vector <int> v;
	if (p[finish] == -1)
		std::cout << "No way\n";
	else {
		for (int u = finish; u != -1; u = p[u])
			v.push_back(u);
		reverse(v.begin(), v.end());
	}
return v;
}
/*
 void Player::moveSelf(float speedX,float speedY)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: Enter))
		{
			playFig.setPosition(10.0f, 10.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			playFig.move(-speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W))
		{
			playFig.move(0.0f , -speedY );
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D))
		{
			playFig.move(speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			playFig.move(0.0f, speedY);
		}
}
*/
