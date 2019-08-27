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

int wait_for_command()
{
    struct termios tm, tm_old;

    int fd = 0, ch;
    if (tcgetattr(fd, &tm) < 0) return -1;

    tm_old = tm;
    cfmakeraw(&tm);
    if (tcsetattr(fd, TCSANOW, &tm) < 0) return -1;

    ch = getchar();
    return ch;
}

#elif defined(_WIN32)

#include <conio.h>

int getkey()
{
    return _getch();
}

#endif
