#include "MenuController.h"

MenuController::MenuController()
{
}

MenuController::~MenuController()
{
}

void MenuController::print_top(int len)
{
    std::cout << CORNER_LT;
    for (int i = 0; i < len; i++)
    {
        std::cout << LINE_HOR;
    } 
    std::cout << CORNER_RT << "\n";
}
void MenuController::print_mid(int len)
{
    std::cout << BORDER_L;
    for (int i = 0; i < len; i++)
    {
        std::cout << LINE_HOR;
    } 
    std::cout << BORDER_R << "\n";
}
void MenuController::print_bot(int len)
{
    std::cout << CORNER_LB;
    for (int i = 0; i < len; i++)
    {
        std::cout << LINE_HOR;
    } 
    std::cout << CORNER_RB << "\n";
}

/**
 * 以指定文件为模板显示菜单。
 * 文件有若干行，第一行为首尾制表符长度，余下每行为菜单内容，补位空格长度。
 * @param name menu文件夹下的文件名
 * @param focus 焦点行数
 * @param header 标题
 */
std::vector<std::string> MenuController::show(std::string header, std::string name, int focus)
{
    // Redirection
    name = "menu/" + name;
    std::fstream file(name);

    // Variables
    std::vector<std::string> menu_items, opts;
    std::map<std::string, int> lens;
    std::string s, opt;
    int line_len,
        len,
        maxlen = 0;
    
    // Input
    file >> line_len;
    while (file >> s >> len >> opt)
    {
        menu_items.emplace_back(s);
        opts.emplace_back(opt);
        lens[s] = len;
        maxlen = std::max(maxlen, (int)s.size() + len);
    }
    file.close();

    // Blank
    print_line();

    if (header.size())
    {
        std::cout << "\t" + header + "\n";
        print_line();
    }

    for (int i = 0; i < (int)menu_items.size(); i++)
    {
        std::string &s = menu_items[i];
        if (focus == i)
        {
            printf(">\t%s\t<\n", s.c_str());
        }
        else
        {
            printf("\t%s\n", s.c_str());
        }
    }
    print_line();
    
    return opts;
}
