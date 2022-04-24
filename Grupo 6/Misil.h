#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Misil
{
private:
	int x, y;
	int dx;
	int height;
	int width;
	int rgb;
	bool visible;

public:
	Misil(){
		x = 100 + rand() % 10;
		y = 4 + rand() % 24;
		dx = 1;
		height = 1;
		width = 4;
		rgb = rand() % 5;
		visible = true;
	}
	~Misil(){}

	//getters
	int getX() { return x; }
	bool getVisible() { return visible; }
	//setter
	void setVisible(bool value) { visible = value; }

	//erase - move - draw

	void Erase() {
		Console::SetCursorPosition(x, y); cout << "   " << " ";
	}

	void Move() {
		if (x > 4) x -= dx;
		//Agregar codigo para borrar cuando llegue al limite, tal vez usar misiles.delete en vector inicializado en el controlador
	}

	void Draw() {

		switch (rgb)
		{
		case 0:
			Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 1:
			Console::ForegroundColor = ConsoleColor::Green; break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Blue; break;
		}

		Console::SetCursorPosition(x, y); cout << "<--" << char(254);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};
