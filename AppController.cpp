#include "AppController.h"

AppController::AppController()
{
#if defined(_WIN32)

    // 设置 Windows 终端代码页为 UTF-8
    // system("chcp 65001");
    
#endif
}

AppController::~AppController()
{
}

int AppController::run()
{
    int opt = 0; // 用户按键
    int focus = 0; // 当前焦点项

    // 主循环
    while (opt != -1 && opt != 3)
    {
        // 显示菜单
        clear_screen();
        // std::cout << focus << "\n";
        auto commands = menu.show("TewiBook", "mainmenu", focus);

        // 获取用户操作
        opt = getkey();
        std::cout << opt << "\n";

        // 处理焦点移动
        if (opt == KEY_W || opt == KEY_w)
        {
            focus = (focus == 0)? focus = static_cast<int>(commands.size()) - 1: focus - 1;
        }
        else if (opt == KEY_S || opt == KEY_s)
        {
            focus = (focus == static_cast<int>(commands.size()) - 1)? focus = 0: focus + 1;
        }

        // 处理项目选择
        if (opt == KEY_ENTER)
        {
            // std::cout << commands[focus] << "\n";
            std::string &cmd = commands[static_cast<unsigned long>(focus)];

            // 获取操作名称
            if (cmd == "exit")
            {
                stop();
            }
            else if (cmd == "about")
            {
                clear_screen();
                menu.show("About", "about", -1);
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
                export_dialog();
            }
        }        
    }
    return 0;
}

void AppController::add_new()
{
    ItemModel item; // 临时项目

    // 获取当前系统时间并转换
    time_t nowsec;
    time(&nowsec);
    auto now = localtime(&nowsec);
    item.time.year = now->tm_year + 1900;
    item.time.month = now->tm_mon + 1;
    item.time.day = now->tm_mday;
    item.time.hour = now->tm_hour;
    item.time.min = now->tm_min;

    // 获取数值
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

    // 获取时间
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

    // 获取类型
    clear_screen();
    item.show();
    puts("\n类型(输入0表示空):");
    std::string typ;
    std::cin >> typ;
    if (!typ.empty() && typ != "0")
    {
        item.type = typ;
    }

    // 获取备注
    clear_screen();
    item.show();
    puts("\n备注(输入0表示空):");
    std::string note;
    std::cin >> note;
    if (!note.empty() && note != "0")
    {
        item.note = note;
    }

    // 最终确认
    clear_screen();
    item.show();
        std::cout << "This is note: " << note;
    puts("\n确认请输入 y, 其他任意指令取消:");
    char opt;
    std::cin >> opt;
    if (opt == 'y' || opt == 'Y')
    {
        // 录入数据
        database.add(item);
        puts("添加完成, 任意键返回");
    }
    else
    {
        puts("操作取消, 任意键返回");
    }
    // 缓存当前页
    getkey();
    getkey();
}

void AppController::view_from(int max_count, std::string sort_by)
{
    // 列出数据
    clear_screen();
    auto items = database.list(sort_by);
    for (int i = 0; i < std::min(max_count, static_cast<int>(items.size())); i++)
    {
        std::cout << std::string(25, '-') << "\n";
        items[static_cast<unsigned long>(i)].show();
    }
    // 显示末尾分割线
    std::cout << std::string(25, '-') << "\n";
    puts("显示完毕, 任意键返回");
}

void AppController::export_dialog()
{
    clear_screen();
    std::string filename;

    puts("请输入要导出到的文件名(默认为EXPORT.csv, 输入0表示使用默认设置):");
    std::cin >> filename;
    if (filename.size() && filename != "0")
    {
        exporter.export_to(database.list(), filename + ".csv");
    }
    else
    {
        exporter.export_to(database.list());
    }
    puts("导出结束, 任意键返回");

    getkey();
    getkey();
}

void AppController::main()
{
    menu.show("TewiBook");
}

void AppController::stop()
{
    exit(0);
}
