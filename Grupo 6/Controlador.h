#pragma once

#include "Misil.h"
#include "Avion.h"
#include "Bonus.h"
#include "Hombre.h"

class Controlador
{
private:

	Hombre* h;
	Avion** ArrAvion;
	Avion* ObjAvion;
	Misil** ArrMisil;
	Misil* ObjMisil;
	Bonus** ArrBonus;
	Bonus* ObjBonus;
	int Almacen;
	bool Lleno;
	int lenAvion, lenMisil, lenBonus;
	
	
public:
	Controlador() {
		h = new Hombre();
		ArrAvion = new Avion * [4];
		ArrMisil = new Misil * [25];
		ArrBonus = new Bonus * [10]; 
		lenAvion = 4;
		lenMisil = 25;
		lenBonus = 10;
		Almacen = 0;
		Lleno = false;

		for (int i = 0; i < 4; i++)
		{
			ObjAvion = new Avion();
			ArrAvion[i] = ObjAvion;
		}
		
		for (int i = 0; i < 25; i++)
		{
			ObjMisil = new Misil();
			ArrMisil[i] = ObjMisil;
		}
		for (int i = 0; i < 10; i++)
		{
			ObjBonus = new Bonus();
			ArrBonus[i] = ObjBonus;
		}
	}
	
	~Controlador(){}

	void setAlmacen(int value) { Almacen += value; }

	void MostrarVidas(int indice) {

		Console::SetCursorPosition(1,1);
		Console::ForegroundColor = ConsoleColor::White;
		cout <<"Vidas de la nave:  ";
		for (int i = 0; i < ArrAvion[indice]->getVidas(); i++)
		{
			Console::ForegroundColor = ConsoleColor::Red;
			cout << char(3) << " ";
		}
	}
	void MostrarAlmacen() {
		Console::SetCursorPosition(105, 29);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "Almacen: " << Almacen;
	}

	void EraseMisiles() {

		for (int i = 0; i < lenMisil; i++)
		{
			ArrMisil[i]->Erase();
		}
	}

	void MoveMisiles() {

		for (int i = 0; i < lenMisil; i++)
		{
			ArrMisil[i]->Move();
		}
	}

	void DrawMisiles() {

		for (int i = 0; i < lenMisil; i++)
		{	
			ArrMisil[i]->Draw();
			_sleep(10);
		}
	}

	void DrawBonus() {

		for (int i = 0; i < lenBonus; i++)
		{
			ArrBonus[i]->Draw();
			_sleep(7);
		}
	}

	void EliminarBonusPosicion(int posicion) {

		Bonus** aux;
		aux = new Bonus * [lenBonus - 1];

		for (int i = 0; i < posicion; i++)
		{
			aux[i] = ArrBonus[i];
		}

		for (int i = posicion; i < lenBonus; i++)
		{
			aux[i] = ArrBonus[i + 1];
		}

		lenBonus--;
		ArrBonus = aux;

	}
	void ColisionBonus(int indice) {

		for (int i = 0; i < lenBonus; i++)
		{
			if (ArrAvion[indice]->getRectangle().IntersectsWith(ArrBonus[i]->getRectangle()))
			{
				ArrBonus[i]->setVisible(false);
				setAlmacen(1);
			}
		}

		for (int i = 0; i < lenBonus; i++)
		{
			if (ArrBonus[i]->getVisible()==false)
			{
				EliminarBonusPosicion(i);
			}
		}
	}

	void RecolectaHombre(int indice) {
		if (Almacen == 6)
		{
			Lleno = true;
		}
	}

	void EliminarMisilPosicion(int posicion) {

		Misil** aux;
		aux = new Misil * [lenMisil - 1];

		for (int i = 0; i < posicion; i++)
		{
			aux[i] = ArrMisil[i];
		}

		for (int i = posicion; i < lenMisil; i++)
		{
			aux[i] = ArrMisil[i + 1];
		}

		lenMisil--;
		ArrMisil = aux;

	}
	void ColisionMisil(int indice){

		for (int i = 0; i < lenMisil; i++)
		{
			if (ArrAvion[indice]->getRectangle().IntersectsWith(ArrMisil[i]->getRectangle()))
			{
				ArrMisil[i]->setVisible(false);
				setAlmacen(-1);
			}
		}

		for (int i = 0; i < lenMisil; i++)
		{
			if (ArrMisil[i]->getVisible() == false)
			{
				EliminarMisilPosicion(i);
				ArrAvion[indice]->setVida(-1);
			}
		}
	}

	void EliminarMisil() {

		for (int i = 0; i <lenMisil ; i++)
		{
			if (ArrMisil[i]->getX() <= 2)
			{
				ArrMisil[i]->setVisible(false);
			}
		}
		for (int i = 0; i < lenMisil; i++)
		{
			if (ArrMisil[i]->getVisible() == false)
			{
				EliminarMisilPosicion(i);
			}
		}
	}

	void EliminarAvion(int indice) {

		if (ArrAvion[indice]->getVidas()==0)
		{
			Avion** aux;
			aux = new Avion * [lenAvion - 1];

			for (int i = 1; i < lenAvion; i++)
			{
				aux[i] = ArrAvion[i];
			}

			lenAvion--;
			ArrAvion = aux;
		}
		//si se elimina avion del array el indice 0 pasa al siguiente avion
	}

	void inicio() {

		int indice = 0;
		char key;

		while (1)
		{
			
			//ORDENADO:
			Console::CursorVisible = false;

			MostrarVidas(indice); 
			MostrarAlmacen(); 

			ArrAvion[indice]->Erase();			
			EraseMisiles();

			if (_kbhit()) {
				key = _getch();
				key = toupper(key);
				ArrAvion[indice]->Move(key);
			}
			MoveMisiles();

			ArrAvion[indice]->Draw();

			DrawMisiles();
			DrawBonus();

			ColisionBonus(indice);
			RecolectaHombre(indice); 

			/*if (Lleno) {
				h->setX(ArrAvion[indice]->getX());
				//podria intentarse for de 10 pasos del hombre
				h->Erase();
				h->Move();
				h->Draw();
			}*/
			
						
			ColisionMisil(indice);
			EliminarAvion(indice);

			EliminarMisil(); 
			
			Almacen = 0;
			
			_sleep(100);
		}
		
	}
};
