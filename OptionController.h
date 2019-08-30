#ifndef OPTIONCONTROLLER_H
#define OPTIONCONTROLLER_H

#include "HashtableModel.h"

class OptionController
{
private:
    HashTable<int> config;

public:
    OptionController();
    ~OptionController();

    int get_config(std::string opt)
    {
        return config[opt];
    }


};


#endif // OPTIONCONTROLLER_H
