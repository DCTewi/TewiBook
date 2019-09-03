#ifndef OPTIONCONTROLLER_H
#define OPTIONCONTROLLER_H

#include "HashtableModel.h"
#include "method.h"
#include <exception>
#include <stdexcept>

/**
 * @brief 选项控制器
 */
class OptionController
{
private:
    /**
     * @brief 选项内容哈希表
     */
    HashTable<int> config;

    /**
     * @brief 单例模式实例
     */
    static OptionController *_instance; // Singletond

public:
    /**
     * @brief 默认构造函数
     */
    OptionController();
    /**
     * @brief 默认析构函数
     */
    ~OptionController();

    /**
     * @brief 单例模式调用单例
     * 
     * @return 实例
     */
    static OptionController &instance();

    /**
     * @brief 获取指定配置
     * 
     * @param opt 配置键
     * 
     * @return 配置值
     */
    int get_config(std::string opt);

    /**
     * @brief 设置配置
     * 
     * @param opt 配置键
     * @param value 配置值
     * 
     * @return 新值
     */
    int set_config(std::string opt, int value);

    /**
     * @brief 重置所有配置
     */
    void reset();
};


#endif // OPTIONCONTROLLER_H
