#include "DbController.h"

DbController::DbController()
{
    load();
}

DbController::~DbController()
{
    save();
}

void DbController::save()
{
    std::fstream db;
    db.open("notes.db", std::ios::out);

    for (auto i : data)
    {
        db << i << std::endl;
    }
    db.close();
}

void DbController::load()
{
    std::fstream db;
    ItemModel item;
    db.open("notes.db", std::ios::in);
    
    while (db >> item)
    {
        data.emplace_back(item);
    }
    db.close();
}

void DbController::reset()
{
    data.clear();
    save();
}

void DbController::add(ItemModel item)
{
    item.ID = data.size();
    data.emplace_back(item);
    save();
}

bool DbController::remove(long long int id)
{
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i].ID == id)
        {
            data.erase(data.begin() + i);
            save();
            return true;
        }
    }
    return false;
}

bool DbController::replace(long long int id, ItemModel item)
{
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i].ID == id)
        {
            data[i] = item;
            save();
            return true;
        }
    }
    return false;
}

std::vector<ItemModel> DbController::list(std::string sort_by)
{
    std::sort(data.begin(), data.end(), [&](ItemModel a, ItemModel b)->bool
    {
        if (sort_by == "id")
        {
            return a.ID < b.ID;
        }
        else if (sort_by == "time")
        {
            return a.time < b.time;
        }
        else if (sort_by == "value")
        {
            return a.value < b.value;
        }
        return a.ID < b.ID;
    });
    save();
    return data;
}
