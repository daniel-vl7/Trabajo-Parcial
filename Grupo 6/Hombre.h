#pragma once
#include <iostream>

using namespace std;

class Hombre
{
private:
	int x, y;
	int dx;
	bool visible;
public:
	Hombre() {
		x = 2;
		y = 25;
		dx = 1;
		visible = true;
	}

	//erase-move-draw;
	void Erase() {
		Console::SetCursorPosition(x + 1, y);  cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << "  " << " ";
		Console::SetCursorPosition(x, y + 2); cout << "  " << " ";
	}
	void Move() {
		if (x < 115) x += dx;
		
	}

	void Draw() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(x + 1, y);  cout << "O";
		Console::SetCursorPosition(x, y + 1); cout << "/|" << char(92);
		Console::SetCursorPosition(x, y + 2); cout << "/ " << char(92);
	}

	~Hombre(){}

};
