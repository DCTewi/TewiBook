#include "AppController.h"

AppController::AppController()
{
#if defined(_WIN32)

    // 设置 Windows 终端代码页为 UTF-8
    system("chcp 65001");
    
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
        puts("[ W & S 键上下移动 ]\n[ Enter 键选中项目 ]");

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
            // 歹出程序
            if (cmd == "exit")
            {
                clear_screen();
                stop();
            }
            // 关于程序
            else if (cmd == "about")
            {
                clear_screen();
                menu.show("About", "about", -1);
                getkey();
            }
            // 新建流水
            else if (cmd == "newitem")
            {
                add_new();
            }
            // 查看账单
            else if (cmd == "viewall")
            {
                view_from();
            }
            // 选项设置
            else if (cmd == "options")
            {
                config_dialog();
            }
            // 到处流水
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
    std::string input; // 临时输入
    int legal = 1; // 合法标记

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
    do
    {
        clear_screen();
        item.show();
        puts("\n输入0取消\n收入请输入正数, 支出请输入负数:");

        // 输入检查
        std::cin >> input;
        try
        {
            item.value = std::stod(input);
            legal = 1;
        }
        // 输入非法
        catch (std::exception e)
        {
            puts("输入非法, 请重新输入");
            // 打非法标记
            legal = 0;
            getkey();
            getkey();
            // 重试输入
            continue;
        }

        if (item.value < 0)
        {
            item.is_income = false; item.value *= -1;
        }
        else if (item.value > 0)
        {
            item.is_income = true;
        }
        else return;
    }
    // 若非法则重试
    while (!legal);
    
    // 获取时间
    do
    {
        clear_screen();
        item.show();
        puts("\n请输入时间(格式 2019 1 10 12 02, 输入0表示使用当前时间):");
        Date temp_date;

        // 输入检查
        std::cin >> input;
        try
        {
            temp_date.year = std::stoi(input);
            legal = 1;
        }
        // 输入非法
        catch (std::exception e)
        {
            puts("输入非法, 请重新输入");
            // 打标记
            legal = 0;
            getkey();
            getkey();
            continue;
        }

        if (temp_date.year)
        {
            // 输入检查
            try
            {
                std::cin >> input; temp_date.month = std::stoi(input);
                std::cin >> input; temp_date.day = std::stoi(input);
                std::cin >> input; temp_date.hour = std::stoi(input);
                std::cin >> input; temp_date.min = std::stoi(input);
                legal = 1;
            }
            catch (std::exception e)
            {
                puts("输入非法, 请重新输入");
                legal = 0;
                getkey();
                getkey();
                continue;
            }
            
            item.time = temp_date;
        }
    }
    // 若非法则重试
    while (!legal);

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
    while (1)
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
        puts("显示完毕, ESC键返回");
        puts("A 键按 ID 排序, S 键按大小排序, D 按时间排序");
        
        // 获取进一步操作
        int opt = getkey();
        if (opt == KEY_ESC)
        {
            return;
        }
        else if (opt == KEY_a || opt == KEY_A)
        {
            sort_by = "id";
        }
        else if (opt == KEY_s || opt == KEY_S)
        {
            sort_by = "value";
        }
        else if (opt == KEY_d || opt == KEY_D)
        {
            sort_by = "time";
        }
    }
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

void AppController::config_dialog()
{
    while (1)
    {
        clear_screen();
        menu.show("Config", "options", -1);
        puts("请输入你要更改的配置序号:");

        // 临时变量
        std::string key, value;
        int opt = -1, flag = 1;

        // 输入检查
        std::cin >> key;
        try
        {
            opt = std::stoi(key);
        }
        catch (std::exception e)
        {
            puts("非法键, 请重试");
            getkey(); getkey();
            continue;
        }

        switch (opt)
        {
        // 分割线符号
        case 1:
            puts("请输入新值");
            std::cin >> value;
            if (value.size() == 1)
            {
                config.set_config("sepchar", static_cast<int>(value[0]));
                puts("设置已更新");
            }
            else
            {
                puts("非法输入, 请重试");
            }
            break;
        // 分割线长度
        case 2:
            puts("请输入新值");
            std::cin >> value;
            for (char c : value)
            {
                if (!isdigit(c))
                {
                    puts("非法输入, 请重试");
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                int len = -1;
                try
                {
                    len = std::stoi(value);
                }
                catch (std::exception e)
                {
                    puts("输入非法, 请重试");
                    break;
                }

                if (len > 0 && len <= 50)
                {
                    config.set_config("seplen", len);
                    puts("设置已更新");
                }
                else
                {
                    puts("长度只能设置在 (0, 50] 之内.");
                }
            }
            break;
        // 初始化
        case 3:
            config.reset();
            puts("设置已经初始化");
            break;
        // 跳出函数
        case 4:
            return;
        // 异常情况
        default:
            puts("非法键, 请重试");
            break;
        }

        getkey();
        getkey();
    }
}

void AppController::main()
{
    menu.show("TewiBook");
}

void AppController::stop()
{
    exit(0);
}
