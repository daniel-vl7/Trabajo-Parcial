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
    //Console::SetCursorPosition(1, 29); cout << " vidas";
    //Console::SetCursorPosition(1, 1); cout << " vidas";
    //Console::SetCursorPosition(114, 1); cout << " vidas";
    //Console::SetCursorPosition(114, 29); cout << " vidas";//114 por que le size de vidas es 5 por lo tanto sobrepasa el limite de la consola y se sobre escribe en la sgte linea

    while (1)
    {
        Console::CursorVisible = false;

        c->EraseAll();

       
        if (_kbhit()) {
            key = _getch();
            key = toupper(key);
            a->Move(key);
        }

        h->MoveHombre();
      
        m->Move();
        
        c->DrawAll();

        c->RecolectaBonus(a,b);
        c->BonusRecolectado(b);
      


        _sleep(100);

    }

    _getch();
    return 0;
}
