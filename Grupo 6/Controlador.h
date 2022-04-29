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
	int lenAvion, lenMisil, lenBonus;
	
public:
	Controlador() {
		h = new Hombre();
		ArrAvion = new Avion * [4];
		ArrMisil = new Misil * [25];
		ArrBonus = new Bonus * [10];
		// buscar solucion para agregar objetos de las clases avion misil (cada cierto tiempo) almacen 
		// que no sobrepase un tamaño de arreglo establecido
		
		//almacen = 0; //agregar en parte inferior derecha 
		lenAvion = 4;
		lenMisil = 25;
		lenBonus = 10;

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

	void InterseccionBonus(){}


	void ColisionMisil(int indice){

		for (int i = 0; i < lenMisil; i++)
		{
			if (ArrAvion[indice]->getRectangle().IntersectsWith(ArrMisil[i]->getRectangle()))
			{
				ArrMisil[i]->setVisible(false);
			}
		}

		for (int i = 0; i < lenMisil; i++)
		{
			if (ArrMisil[i]->getVisible() == false)
			{
				//delete  misil in position i EliminarMisil();
				ArrAvion[indice]->ReducirVida();
			}
		}
		
	}

	void inicio() {

		short indice = 0;
		short current = 0;

		while (1)
		{
			/*
			MostrarVidas();  //INTERMEDIO (INTE)
			MostrarBonus(); //INTE

			BorrarTodo(); //INTE

			if (_kbhit()) {
				key = _getch();
				key = toupper(key);
				ArrAvion[i + current]->Move(key);// current sirve? //ADVA
			}

			MoveMisil();//array for con sleep? //ADVA
			DrawMisil();//array //ADVA

			IntersecaMisil(); pimerO for para arr misiles  //INTE

			EliminarMisil();//borrar del array if intersecta misil true;  //INTE

			EliminarVidas(); //ArrAvio[i].reducir vida(); //INTE
			IntersecaBonus(); //INTE
			BorraBonus();//if intersecta true; //INTE
			EliminaAvion(); //if ArrAvion[i]. vidas == 0 
			AgregarAvion();//if ArrAvion[i]. vidas == 0 {i++;} ? //INTE
		*/
		}
		
	}
	//CODIGO A PARIR DE AQUI: IGNORAR IGNORAR IGNORAR IGNORAR
	/*
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

	//adecuar funciones para trabajarlas con arreglos ||  lineas 28 al 00
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

	
	*/
};
