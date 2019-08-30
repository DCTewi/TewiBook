#include "DbController.h"

DbController::DbController()
{
    // 构造时尝试从文件载入数据
    load();
}

DbController::~DbController()
{
    // 被析构时保存数据
    save();
}

void DbController::save()
{
    std::fstream db; // 临时文件流
    db.open("notes.db", std::ios::out);

    for (auto i : data)
    {
        db << i << std::endl;
    }
    db.close();
}

void DbController::load()
{
    std::fstream db; // 临时文件流
    ItemModel item; // 临时项目
    int id = 0;
    db.open("notes.db", std::ios::in);
    
    while (db >> item)
    {
        item.ID = id++;
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
    // 分配 ID
    item.ID = static_cast<long long>(data.size());
    // 增加项目
    data.emplace_back(item);
    save();
}

bool DbController::remove(long long int id)
{
    for (int i = 0; i < static_cast<int>(data.size()); i++)
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
    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        if (data[static_cast<unsigned long>(i)].ID == id)
        {
            data[static_cast<unsigned long>(i)] = item;
            save();
            return true;
        }
    }
    return false;
}

std::vector<ItemModel> DbController::list(std::string sort_by)
{
    // 根据排序依据排序
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
    // 返回数据库副本
    return data;
}
