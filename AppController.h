#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "MenuController.h"

class AppController
{
private:
    MenuController menu;

public:
    AppController();
    ~AppController();
    int run();

    void main();

    void stop();
};

#endif // APPCONTROLLER_H
