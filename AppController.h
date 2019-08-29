#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "MenuController.h"
#include "DbController.h"

class AppController
{
private:
    MenuController menu;
    DbController database;
public:
    AppController();
    ~AppController();
    int run();
    void stop();

    void main();

    void add_new();
    void view_from(int max_count = 20, std::string sort_by = "id");
};

#endif // APPCONTROLLER_H
