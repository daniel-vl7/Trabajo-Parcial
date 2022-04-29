#include "pch.h"
#include <conio.h>

#include "Controlador.h"

int main()
{
    srand(time(NULL));
    Console::SetWindowSize(120, 30);

    char key;

    Avion* a;
    a = new Avion();

    Misil* m;
    m = new Misil();

    Bonus* b;
    b = new Bonus();

    Controlador* c;
    c = new Controlador();

    Hombre* h;
    h = new Hombre();
    //114 por que le size de vidas es 5 por lo tanto sobrepasa el limite de la consola y se sobre escribe en la sgte linea

    while (1)
    {
        Console::CursorVisible = false;

        //c->EraseAll();

        //c->AgregarAvion();
        
        //dentro de collision?
        //c->AgregarMisil(); //usar con sleep()?
        //c->AgregarBonus();
        c->MostrarVidas(1);

        a->Erase();
        //h->Erase();
        b->Erase();
        m->Erase();

        if (_kbhit()) {
            key = _getch();
            key = toupper(key);
            a->Move(key);
            //c->getAvion()->Move(key); error!
        }
        m->Move();
        //h->Move();
        b->Draw();
        //h->Draw();
        a->Draw();
        m->Draw();


        //c->MoveAll(); // auto movement (misil & hombre)
        
        //c->DrawAll();

        //c->RecolectaBonus(a,b);
        //c->BonusRecolectado(b);
      


        _sleep(100);

    }

    _getch();
    return 0;
}
