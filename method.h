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

int getkey();

#endif // METHOD_H
