#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "ExportController.h"
#include "MenuController.h"
#include "DbController.h"
#include "OptionController.h"

/**
 * @brief 程序控制器
 * @note 控制程序主流程的运行
 */
class AppController
{
private:
    /**
     * @brief 主要菜单控制器
     */
    MenuController menu;
    /**
     * @brief 主要数据库控制器
     */
    DbController database;
    /**
     * @brief 导出器
     */
    ExportController exporter;
    /**
     * @brief 配置控制器
     */
    OptionController config;
    
public:
    /**
     *  @brief 默认构造函数
     */
    AppController();

    /**
     *  @brief 默认析构函数
     */
    ~AppController();

    /**
     * @brief 运行主程序
     */
    int run();

    /**
     *  @brief 结束主程序
     */
    [[noreturn]] void stop();

    /**
     *  @brief 显示主菜单
     */
    void main();

    /**
     *  @brief 添加新项目
     */
    void add_new();
    
    /**
     * @brief 以某种顺序显示前 max_count 项
     * 
     * @param max_count 最大项数
     * @param sort_by 排序依据
     */
    void view_from(int max_count = 20, std::string sort_by = "id");

    /**
     * @brief 导出对话
     */
    void export_dialog();

    /**
     * @brief config_dialog
     */
    void config_dialog();
};

#endif // APPCONTROLLER_H
