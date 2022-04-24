#pragma once
#include <vector>
#include "Misil.h"
#include "Avion.h"
#include "Bonus.h"
#include "Hombre.h"

class Controlador
{
private:

	vector<Avion*> aviones;
	vector<Misil*> misiles;
	vector<Bonus*> almacen;
	Hombre* h;
	//int almacen;

public:
	Controlador() {
		h = new Hombre();
		//aviones.assign(4, new Avion()); buscar solucion para agregar objetos de las clases avion misil (cada cierto tiempo) almacen 
		// que no sobrepase un tamaño de arreglo establecido
		//misiles.assign(20, new Misil());
		//almacen.assign(10, new Bonus());
		//almacen = 0; //agregar en parte inferior derecha
	}
	~Controlador(){}


	//agregar misiles
	void AgregarMisil() {
		//for i in range 20
		misiles.push_back(new Misil());
		//_sleep() agregación aleatoria
	}

	//agregar aviones
	void AgregarAvion() {
		//for i in range 4
		aviones.push_back(new Avion());
		// when live is 0;
	}

	//agregar bonus
	void AgregarBonus() {
		almacen.push_back(new Bonus());
		//_sleep() agregación aleatoria

	}

	//adecuar funciones para trabajarlas con arreglos ||  lineas 28 al 55 

	void RecolectaBonus(Avion* newa, Bonus* newb) {
		if (newa->getRectangle().IntersectsWith(newb->getRectangle())) {
			almacen.push_back(new Bonus());
			newb->setVisible(false);
		}
	}
	void BonusRecolectado(Bonus* newb) {
		if (newb->getVisible() == false) {
			//for testing:
			//almacen *= 1; no sirve
		}
	}

	void HombreRecolecta(){}//hombre aparece y recolecta almacen de 6 items
	void ReduceAlmacen(){}//choque con misil quita 1 item de almacen; cambio visible
	void EliminaMisil(){}//pasado y = 2 el misil se borra;

	void ReduceVida(){}// choque de avion con misil;
	void EliminaAvion(){}//vidas = 0, debe aparecer otro avion;

	//Erase 
	void EraseAll() {

		for (int i = 0; i < misiles.size(); i++)
		{
			misiles[i]->Erase();
		}
		for (int i = 0; i < aviones.size(); i++)
		{
			aviones[i]->Erase();
		}
		//for (int i = 0; i < arrBonus.size(); i++)
		//{
			//arrBonus[i]->Erase(); EVALUAR SI ES NECESARIA ESTE FOR
		//}
		h->EraseHombre();

	}
	//Draw
	void DrawAll() {//  a = argumento aviones[i] 

		for (int i = 0; i < misiles.size(); i++)
		{
			misiles[i]->Draw();
		}
		for (int i = 0; i < aviones.size(); i++)
		{
			aviones[i]->Draw();
		}
		h->DrawHombre();
		//Console::ForegroundColor = ConsoleColor::Red;
		//Console::SetCursorPosition(1, 1);
		//for (int i = 0; i < a->getVidas(); i++) {
		//	cout << char(3) << " ";
		//}

		Console::SetCursorPosition(108, 19);
		for (int i = 0; i < almacen.size(); i++)
		{
			cout << char(254) << endl;
		}
	}	
};
