#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include "ItemModel.h"
#include "method.h"

class DbController
{
private:
    std::vector<ItemModel> data;
    void load();
    void save();

public:
    DbController();
    ~DbController();

    void reset();
    void add(ItemModel item);
    bool remove(long long int id);
    bool replace(long long int id, ItemModel item);
    std::vector<ItemModel> list(std::string sort_by = "id");
};

#endif // DBCONTROLLER_H
