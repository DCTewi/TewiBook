#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <bits/stdc++.h>
#include "method.h"

class MenuController
{
private:
    void print_top(int len);
    void print_mid(int len);
    void print_bot(int len);
public:
    MenuController();
    ~MenuController();

    std::vector<std::string> show(std::string header = "", std::string name = "mainmenu", int focus = 0);
};

#endif // MENUCONTROLLER_H
