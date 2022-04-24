#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Bonus
{
private:
	int x, y;
	int height, width;
	bool visible;

public:
	Bonus() {

		visible = true;
		height = 1;
		width = 1;
		x = 50 + rand() % 50;
		y = 4 + rand() % 25;

	}

	~Bonus(){}

	//getter
	bool getVisible() { return visible; }
	//setter
	void setVisible(bool value) { visible = value; }

	//erase - draw

	//EraseBonus no tiene uso, observacion
	void Erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void Draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << char(254);
	}

	Rectangle getRectangle() { 
		return Rectangle(x, y, height, width); 
	}
};