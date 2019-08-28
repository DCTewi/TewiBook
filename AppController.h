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

    void add_new();
    void view_from(int max_count = 20, std::string sort_by = "id");
};

#endif // APPCONTROLLER_H
