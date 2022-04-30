#include "pch.h"
#include <conio.h>
#include "Controlador.h"

int main()
{
    srand(time(NULL));
    Console::SetWindowSize(120, 30);

    Controlador* c;
    c = new Controlador();

    c->inicio();

    _getch();
    return 0;
}
