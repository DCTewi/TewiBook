#include "ExportController.h"

ExportController::ExportController()
{
}

ExportController::~ExportController()
{
}

void ExportController::export_to(std::vector<ItemModel> items, std::string filename)
{
    // 开流
    std::fstream file; // 临时文件流
    file.open(filename, std::ios::out);

    // 标题
    file << "Value,Date,Time,Type,Note" << std::endl;
    // 输出
    for (auto it : items)
    {
        file << (it.is_income? "+": "-") << it.value << ",";
        file << it.time.year << "/" << it.time.month <<  "/" << it.time.day << ",";
        file << it.time.hour << ":" << std::setw(2) << it.time.min << ",";
        file << it.type << ",";
        file << it.note << std::endl;
    }
    // 关流
    file.close();
}
