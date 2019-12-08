//Алгоритм редактирования карты
// 1.Нажать backspace
// 2. Выбрать точку и нажать по ней левой кнопкой мыши
// 3. Перемещать выбранную точку стрелками
// 4. После всех перемещений нажать T
// 5. Можно переходить к следующей точке
// 6. Чтобы сохранить в файл - нажать Z
MapRedactor::MapRedactor()
{
	redactcount=0;
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
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
		MapHndl.allVertex[i].setIsMovable(false);
	}
}

void MapRedactor::MoveRedact(MapHandler& MapHndl,float speedx,float speedy) {
		for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsMovable()==true && redactcount<2) {
	MapHndl.allVertex[i].MoveCircle(speedx,speedy);
			}
			}

}

void MapRedactor::WriteFile(MapHandler& MapHndl) {
	std::string connection = "";
	std::ofstream out;
	out.open("D:\\game\\map.txt");
	if (out.is_open()) {
		/*for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
			for (unsigned int j=0; j<MapHndl.allVertex[i].getConnectionCodesVectorSize();j++) {
				connection.insert(j,1,MapHndl.allVertex[i].getConnectionCode(j));

			}
		{out<<i<<" "<<MapHndl.allVertex[i].getPosX()<<" "<<MapHndl.allVertex[i].getPosY()<<connection<<std::endl;}
	} */
	for (unsigned int i=0; i<MapHndl.allVertex.size();i++) {
		out<<i<<" "<<MapHndl.allVertex[i].getPosX()<<" "<<MapHndl.allVertex[i].getPosY()<<" ";
		for (unsigned int j=0; j<MapHndl.allVertex[i].getConnectionCodesVectorSize();j++) {
			out<<MapHndl.allVertex[i].getConnectionCode(j)<<" ";
		}
		out<<std::endl;
	}

}
}

