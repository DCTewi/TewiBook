#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "MenuController.h"
#include "DbController.h"

/**
 * 程序控制器
 * 控制程序主流程的运行
 */
class AppController
{
private:
    MenuController menu; // 主要菜单控制器
    DbController database; // 主要数据库控制器
    
public:
    /**
     *  默认构造函数
     */
    AppController();

    /**
     *  默认析构函数
     */
    ~AppController();

    /**
     * 运行主程序
     */
    int run();

    /**
     *  结束主程序
     */
    void stop();

    /**
     *  显示主菜单
     */
    void main();

    /**
     *  添加新项目
     */
    void add_new();
    
    /**
     * 以某种顺序显示前 max_count 项
     * @param max_count 最大项数
     * @param sort_by 排序依据
     */
    void view_from(int max_count = 20, std::string sort_by = "id");
};

#endif // APPCONTROLLER_H
