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
            else if (cmd == "newitem")
            {
                clear_screen();
                add_new();
            }
            else if (cmd == "viewall")
            {
                view_from();
                getkey();
            }
            else if (cmd == "options")
            {
                clear_screen();
                printf("Options\n");
                getkey();
            }
            else if (cmd == "export")
            {
                clear_screen();
                printf("Export\n");
                getkey();
            }
            
        }        
    }
    return 0;
}

void AppController::add_new()
{
    ItemModel item;

    time_t nowsec;
    time(&nowsec);
    auto now = localtime(&nowsec);
    item.time.year = now->tm_year + 1900;
    item.time.month = now->tm_mon + 1;
    item.time.day = now->tm_mday;
    item.time.hour = now->tm_hour;
    item.time.min = now->tm_min;

    clear_screen();
    item.show();
    puts("\n输入0取消\n收入请输入正数, 支出请输入负数:");
    std::cin >> item.value;
    if (item.value < 0)
    {
        item.is_income = false; item.value *= -1;
    }
    else if (item.value > 0)
    {
        item.is_income = true;
    }
    else return;

    clear_screen();
    item.show();
    puts("\n请输入时间(格式 2019 1 10 12 02, 输入0表示使用当前时间):");
    Date temp_date;
    std::cin >> temp_date.year;
    if (temp_date.year)
    {
        std::cin >> temp_date.month >> temp_date.day >> temp_date.hour >> temp_date.min;
        item.time = temp_date;
    }

    clear_screen();
    item.show();
    puts("\n类型(输入0表示空):");
    std::string typ;
    std::cin >> typ;
    if (!typ.empty() && typ != "0")
    {
        item.type = typ;
    }

    clear_screen();
    item.show();
    puts("\n备注(输入0表示空):");
    std::string note;
    std::cin >> note;
    if (!note.empty() && note != "0")
    {
        item.note = note;
    }

    clear_screen();
    item.show();
    puts("\n确认请输入 y, 其他任意指令取消:");
    char opt;
    std::cin >> opt;
    if (opt == 'y')
    {
        database.add(item);
        puts("添加完成");
    }
    else
    {
        puts("操作取消");
    }
    getkey();
    getkey();
}

void AppController::view_from(int max_count, std::string sort_by)
{
    clear_screen();
    auto items = database.list();
    for (int i = 0; i < std::min(max_count, (int)items.size()); i++)
    {
        std::cout << std::string(25, '-') << "\n";
        items[i].show();
    }
    std::cout << std::string(25, '-') << "\n";
}

void AppController::main()
{
    menu.show("TewiBook");
}

void AppController::stop()
{
    exit(0);
}
