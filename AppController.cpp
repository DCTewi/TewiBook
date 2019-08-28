#include "AppController.h"

AppController::AppController()
{
}

AppController::~AppController()
{
}

int AppController::run()
{
    int opt = 0,
        focus = 0;
    while (opt != -1 && opt != 3)
    {
        clear_screen();
        std::cout << focus << "\n";
        auto commands = menu.show("TewiBook", "mainmenu", focus);
        opt = getkey();
        std::cout << opt << "\n";

        if (opt == KEY_W || opt == KEY_w)
        {
            focus = (focus == 0)? focus = commands.size() - 1: focus - 1;
        }
        else if (opt == KEY_S || opt == KEY_s)
        {
            focus = (focus == commands.size() - 1)? focus = 0: focus + 1;
        }

        if (opt == KEY_ENTER)
        {
            std::cout << commands[focus] << "\n";
            std::string &cmd = commands[focus];
            if (cmd == "exit")
            {
                stop();
            }
            else if (cmd == "about")
            {
                menu.show("About", "about");
                getkey();
            }
            
        }        
    }
    return 0;
}

void AppController::main()
{
    menu.show("TewiBook");
}

void AppController::stop()
{
    exit(0);
}