#pragma once

#include <vector>
#include "Misil.h"
#include "Avion.h"
#include "Bonus.h"
#include "Hombre.h"

class Controlador
{
private:

	Hombre* h;
	
	vector<Avion*> aviones;
	//vector avion con 4 objts 
	vector<Misil*> misiles;
	vector<Bonus*> almacen;
	
	//int almacen;

public:
	Controlador() {
		h = new Hombre();
		
		// buscar solucion para agregar objetos de las clases avion misil (cada cierto tiempo) almacen 
		// que no sobrepase un tamaño de arreglo establecido
		//misiles.assign(20, new Misil());
		//almacen.assign(10, new Bonus());
		//almacen = 0; //agregar en parte inferior derecha
	}
	~Controlador(){}


	//agregar misiles
	void AgregarMisil() {
		//for i in range 20
		for (int i = 0; i < 20; i++)
		{
			misiles.push_back(new Misil());
		}
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
		for (int i = 0; i < 10; i++)
		{
			almacen.push_back(new Bonus());
		}
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
		h->Erase();

	}
	//Move - automatic movement
	void MoveAll() {
		for (int i = 0; i < misiles.size(); i++)
		{
			misiles[i]->Move();
		}
		h->Move();
	}


	//Draw
	void DrawAll() {//  a = argumento aviones[i] 

		for (int i = 0; i < misiles.size(); i++)
		{
			_sleep(400);
			misiles[i]->Draw();
		}
		for (int i = 0; i < aviones.size(); i++)
		{
			aviones[i]->Draw();
		}
		h->Draw();
		//Console::ForegroundColor = ConsoleColor::Red;
		//Console::SetCursorPosition(1, 1);
		//for (int i = 0; i < a->getVidas(); i++) {
		//	cout << char(3) << " ";
		//}

		Console::SetCursorPosition(100, 19);
		for (int i = 0; i < almacen.size(); i++)
		{
			_sleep(600);
			cout << char(254) << endl;
		}
	}	

	

};
