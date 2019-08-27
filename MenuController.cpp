#include "MenuController.h"

MenuController::MenuController()
{

}

MenuController::~MenuController()
{
}

int MenuController::show(std::string name)
{
    std::ifstream file;
    file.open("menu/" + name, std::ios::in);

    std::vector<std::string> menu_items;
    int maxlen = 0;
    if (file.good())
    {
        while(!file.eof())
        {
            std::string s;
            getline(file, s);
            maxlen = std::max(maxlen, (int)s.size());
            menu_items.emplace_back(s);
        }
    }
    file.close();

    std::cout << CORNER_LT;
    for (int i = 0; i < maxlen; i++)
    {
        std::cout << LINE_HOR;
    } 
    std::cout << CORNER_RT << "\n";

    for (auto s : menu_items)
    {
        std::cout << s << "'s size: " << s.size() << "\n";
        std::cout << LINE_VER << s << std::setw(maxlen - s.size()) << LINE_VER << "\n";
    }

    return 0;
}
