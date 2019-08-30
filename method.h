#ifndef METHOD_H
#define METHOD_H

#include <bits/stdc++.h>

// 键位常量

const int KEY_ENTER = 13; // Enter 键

const int KEY_w = 119; // w 键
const int KEY_s = 115; // s 键
const int KEY_a = 97; // a 键
const int KEY_d = 100; // d 键

const int KEY_W = 87; // W 键
const int KEY_S = 83; // S 键
const int KEY_A = 65; // A 键
const int KEY_D = 68; // D 键

const char DEFAULT_SEPERATOR = '-';
const int DEFAULT_SEP_LENGTH = 25;

/**
 * 封装的跨平台安全读取键盘时间函数
 * 
 * Windows 使用 conio.h 中 _getch() 实现
 * Linux 使用临时切换终端输入模式切换实现
 * 读取 ASCII 值以保证结果相同
 */
int getkey();

/**
 * 封装的跨平台清屏函数
 * 
 * Windows 使用 cls
 * Linux 使用 clear
 */
void clear_screen();

/**
 * 模板类快速读入函数
 * 只支持数字的读入
 */
template<typename T> inline T read();

/**
 * 绘制一条分割线
 */
void print_line();

#endif // METHOD_H
