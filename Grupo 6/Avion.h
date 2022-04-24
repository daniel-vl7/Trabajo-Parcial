#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Avion
{
private:
	int x, y;
	int dx, dy;
	int height;
	int width;
	int vidas;
	bool visible;

public:
	Avion() {
		x = 2;
		y = 2 + rand() % 25;
		dx = 2;
		dy = 2;
		height = 3;
		width = 7;
		vidas = 4; // if vidas = 0 - visible = false// new avion en pantalla
		visible = true;
	}
	~Avion(){}

	//getter
	bool getVisible() { return visible; }
	int getVidas() { return vidas; }
	int getX() { return x; }
	int getY() { return y; }

	//setter
	void setVisible(bool value) { visible = value; }

	//erase - draw - move

	void Erase() {
		Console::SetCursorPosition(x, y); cout << " " << "     ";
		Console::SetCursorPosition(x, y + 1); cout << " " << " " << " " << " " << " " << " " << "  ";
		Console::SetCursorPosition(x, y + 2); cout << " " << "     ";
	}

	void Move(char key) {

		switch (key)
		{
		case 'A':
			if (x > 7) x -= dx;
			break;
		case 'W':
			if (y > 3 ) y -= dy;
			break;
		case 'D':
			if (x + width < 118) x += dx;
			break;
		case 'S':
			if (y + height < 28) y += dy;
			break;
		default:
			break;
		}
	}

	void Draw() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(x, y); cout << char(254) << "-----";
		Console::SetCursorPosition(x, y + 1); cout << " " << char(254) << " " << char(254) << " " << char(254) << " )";
		Console::SetCursorPosition(x, y + 2); cout << char(254) << "-----";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
};