#include "MenuController.h"

MenuController::MenuController()
{
}

MenuController::~MenuController()
{
}

std::vector<std::string> MenuController::show(std::string header, std::string name, int focus)
{
    // 临时文件流
    name = "menu/" + name;
    std::fstream file(name);

    std::vector<std::string> menu_items, opts; // 依次的显示内容和指令内容
    std::string s, opt; // 临时变量
    
    // 获取菜单
    while (file >> s >> opt)
    {
        menu_items.emplace_back(s);
        opts.emplace_back(opt);
    }
    file.close();

    // 输出
    print_line();

    // 标题
    if (header.size())
    {
        std::cout << "\t" + header + "\n";
        print_line();
    }

    // 处理每项
    for (int i = 0; i < static_cast<int>(menu_items.size()); i++)
    {
        std::string &s = menu_items[static_cast<size_t>(i)];
        // 检查焦点项
        if (focus == i)
        {
            printf(">\t%s\t<\n", s.c_str());
        }
        else if (!~focus)
        {
            printf("%s\n", s.c_str());
        }
        else
        {
            printf("\t%s\n", s.c_str());
        }
    }
    print_line();
    
    // 返回指令集
    return opts;
}
