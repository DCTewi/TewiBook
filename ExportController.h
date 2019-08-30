#ifndef EXPORTCONTROLLER_H
#define EXPORTCONTROLLER_H

#include <fstream>
#include <vector>

#include "ItemModel.h"

/**
 * 导出控制器
 * 用于按格式导出账单
 */
class ExportController
{
private:
    
public:
    /**
     * 默认构造函数
     */
    ExportController();
    /**
     * 默认析构函数
     */
    ~ExportController();

    /**
     * 将数据导出到当前目录下
     * @param items 要导出的项目
     * @param filename 文件名
     */
    void export_to(std::vector<ItemModel> items, std::string filename = "EXPORT.csv");
};

#endif // EXPORTCONTROLLER_H
