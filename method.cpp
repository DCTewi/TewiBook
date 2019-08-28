#include "method.h"

#if defined(__linux__)

#include <termio.h>
#include <cstdio>

int getkey()
{
    static termios old, cur;

    tcgetattr(0, &old); // Grab old io type
    cur = old;
    cfmakeraw(&cur); // Disable buffer
    tcsetattr(0, TCSANOW, &cur); // Set new type

    char ch = getchar();

    tcsetattr(0, TCSANOW, &old); // Reset io type
    
    return ch;
}

void clear_screen()
{
    system("clear");
}

#elif defined(_WIN32)

#include <conio.h>

int getkey()
{
    return _getch();
}

void clear_screen()
{
    system("cls");
}

#endif
