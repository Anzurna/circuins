//Алгоритм редактирования карты
// 1.Нажать backspace
// 2. Выбрать точку и нажать по ней левой кнопкой мыши
// 3. Перемещать выбранную точку стрелками
// 4. После всех перемещений нажать T
// 5. Можно переходить к следующей точке
// 6. Чтобы сохранить в файл - нажать Z

// Чтобы задать новую вершину, нажать Q и щелкнуть мышкой в месте размещения
// после размещения нажать Q
MapRedactor::MapRedactor()
{
	redactcount=0;
	concount=0;
	setconn=false;
	index=0;
}

void MapRedactor::SetRedact(sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view) {
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)) {
					MapHndl.allVertex[i].setIsMovable(true);
					redactcount+=1;
				}
	}
}

void MapRedactor::Reset (MapHandler& MapHndl) {
	redactcount=0;
	concount=0;
	setconn=false;
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
		MapHndl.allVertex[i].setIsMovable(false);
		MapHndl.allVertex[i].setIsConnectable(false);
	}
}



void MapRedactor::SetConnectBasis (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view) {

	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)&&(concount<1)) {
					concount+=1;
					MapHndl.allVertex[i].setIsConnectable(true);
					MapHndl.allVertex[i].Colorise();
					index=i;
					break;

				}
	}
}

void MapRedactor::DrawConnection(MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view) {
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)&&(i!=index)) {
	MapHndl.allVertex[index].addConnection(i+1);
	MapHndl.allVertex[i].addConnection(index+1);
}
	}
}










void MapRedactor::MoveRedact(MapHandler& MapHndl,float speedx,float speedy) {
		for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsMovable()==true && redactcount<2) {
	MapHndl.allVertex[i].MoveCircle(speedx,speedy);
			}
			}

}

void MapRedactor::SetVertex(sf::RenderWindow& window,MapHandler& MapHndl,int ID, sf::Vector2i mousePos,
std::vector<unsigned int> connectionVector,sf::View view)
{	ID=MapHndl.allVertex.size();
	TransformedmousePos=window.mapPixelToCoords({mousePos.x,mousePos.y} ,view);
	int xcord=TransformedmousePos.x;
	int ycord=TransformedmousePos.y;
	Vertex *Vertexobj = new Vertex;
	Vertexobj->init(ID,{},{});
	MapHndl.allVertex.push_back(*Vertexobj);
	MapHndl.allVertex[MapHndl.allVertex.size()-1].init(ID,{xcord,ycord},connectionVector);
	MapHndl.allVertex[MapHndl.allVertex.size()-1].toggleVisibility();
	delete Vertexobj;
}

void MapRedactor::WriteFile(MapHandler& MapHndl,std::string filename) {
	std::string connection = "";
	/*std::ofstream out;*/
	out.open(filename);
	if (out.is_open()) {
		/*for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
			for (unsigned int j=0; j<MapHndl.allVertex[i].getConnectionCodesVectorSize();j++) {
				connection.insert(j,1,MapHndl.allVertex[i].getConnectionCode(j));

			}
		{out<<i<<" "<<MapHndl.allVertex[i].getPosX()<<" "<<MapHndl.allVertex[i].getPosY()<<connection<<std::endl;}
	} */
	for (unsigned int i=0; i<MapHndl.allVertex.size();i++) {
		out<<i+1<<" "<<MapHndl.allVertex[i].getPosX()<<" "<<MapHndl.allVertex[i].getPosY()<<"|";
		for (unsigned int j=0; j<MapHndl.allVertex[i].getConnectionCodesVectorSize();j++) {
			out<<MapHndl.allVertex[i].getConnectionCode(j)<<" ";
		}
		out<<std::endl;
	}

}
}

void MapRedactor::ReadFile(MapHandler& MapHndl,std::string filename) {
/* std::string initStr; //считываемая строка из файла
std::string connStr;//часть строки, хранящаая коды соединений
std::string init2;
std::vector<unsigned int> connectionCodes;
int firstSpace;//позиция вхождения символа "|"
int secondSpace;
float number;
int code;
float xcord;
float ycord; */

std::ifstream file (filename);

 if (!file)
 {
 std::cout << "Файл не открыт\n\n";
 }

 else {
	 /*file>>number>>xcord>>ycord;*/
	 while(getline(file, initStr)){ // пока не достигнут конец файла класть очередную строку в переменную  initStr
	   std::stringstream(initStr)>>number>>xcord>>ycord;//запись первых трех параметров вертекса
	   firstSpace=initStr.find_first_of("|")+1;
	   secondSpace=initStr.length();
	   connStr=initStr.substr(firstSpace,secondSpace-firstSpace);//образание первой части строки
	   std::istringstream is( connStr );
      std::vector<std::string> tokens;
	   std::copy( std::istream_iterator<std::string>( is ),
               std::istream_iterator<std::string>(),
               std::back_inserter( tokens ) ); //парсинг строки с пробелами
			    for ( const auto &s : tokens ) {
					std::stringstream(s)>>code;//перевод из строки в int
					connectionCodes.push_back(code);//запись в массив соединений
				}

	   Vertex *Vertexobj = new Vertex; //cсздание вершины без параметров для инициализации
	Vertexobj->init(number,{(int)xcord,(int)ycord},connectionCodes);
	MapHndl.allVertex.push_back(*Vertexobj);
	MapHndl.allVertex[MapHndl.allVertex.size()-1].init(number,{(int)xcord,(int)ycord},connectionCodes);
		connectionCodes.clear();//очистка массива соединений
		delete Vertexobj;//удаление указателя на вектор(вершину)


    }

 }

}
