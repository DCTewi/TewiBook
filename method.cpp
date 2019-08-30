#include "method.h"

/**
 *  两个函数的 Linux 实现版本
 */
#if defined(__linux__)

#include <termio.h>
#include <cstdio>

int getkey()
{
    static termios old, cur;

    // 获取并备份终端输入模式
    tcgetattr(0, &old);
    cur = old;
    // 取消缓存区
    cfmakeraw(&cur);
    // 设置 raw 输入模式
    tcsetattr(0, TCSANOW, &cur);

    // 获取下一个按键
    int ch = getchar();

    // 还原原输入模式
    tcsetattr(0, TCSANOW, &old);
    // 返回获取的按键值
    return ch;
}

void clear_screen()
{
    system("clear");
}

/**
 *  两个函数的 Windows 实现版本
 */
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

template<typename T> inline T read()
{
    T x = 0;
    int w = 0, ch = getchar();
    while (!isdigit(ch))
    {
         w |= ch == '-'; ch = getchar();
    }
    while (isdigit(ch))
    {
         x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    return w? -x: x;
}

void print_line()
{
    std::cout << std::string(DEFAULT_SEP_LENGTH, DEFAULT_SEPERATOR) << "\n";
}
