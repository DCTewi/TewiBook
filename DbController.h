#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include "ItemModel.h"
#include "method.h"

/**
 * @brief 数据库控制器
 * @note 用于控制数据I/O
 */
class DbController
{
private:
    std::vector<ItemModel> data; // 数据缓存区
    /**
     * @brief 从文件加载数据
     */
    void load();
    /**
     * @brief 将数据从缓存载入到文件
     */
    void save();

public:
    /**
     * @brief 默认构造函数
     */
    DbController();
    /**
     * @brief 默认析构函数
     */
    ~DbController();

    /**
     * @brief 初始化数据库
     * @brief 将清除所有保存数据
     */
    void reset();
    /**
     * @brief 添加项目
     * @param item 新项目副本
     */
    void add(ItemModel item);
    /**
     * @brief 删除指定 id 的项目
     * @return 删除结果
     */
    bool remove(long long int id);
    /**
     * @brief 将指定 id 的项目替换为新项目
     * @param id 目标项目 id
     * @param item 新项目副本
     * @return 删除结果
     */
    bool replace(long long int id, ItemModel item);
    /**
     * @brief 以某种顺序列出所有项目
     * @param sort_by 排序依据
     * @note sort_by的可能值: id, time, value
     */
    std::vector<ItemModel> list(std::string sort_by = "id");
};

#endif // DBCONTROLLER_H
