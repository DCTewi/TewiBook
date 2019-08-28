#ifndef METHOD_H
#define METHOD_H

const int KEY_ENTER = 13;

const int KEY_w = 119;
const int KEY_s = 115;
const int KEY_a = 97;
const int KEY_d = 100;

const int KEY_W = 87;
const int KEY_S = 83;
const int KEY_A = 65;
const int KEY_D = 68;

#include <string>
const std::string LINE_HOR = "─";
const std::string LINE_VER = "│";
const std::string CORNER_LT = "┌";
const std::string CORNER_LB = "└";
const std::string CORNER_RT = "┐";
const std::string CORNER_RB = "┘";
const std::string BORDER_L = "├";
const std::string BORDER_R = "┤";

int getkey();
void clear_screen();

template<typename T> T read()
{
    T x = 0; int w = 0; char ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

#endif // METHOD_H
