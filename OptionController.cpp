#include "OptionController.h"

OptionController *OptionController::_instance = nullptr;

void OptionController::reset()
{
    set_config("sepchar", static_cast<int>(DEFAULT_SEPERATOR));
    set_config("seplen", DEFAULT_SEP_LENGTH);
}

OptionController::OptionController()
{
    // 单例模式实现
    if (_instance == nullptr)
    {
        _instance = this;
    }
    else
    {
        // 不应出现两个实例，简单抛出异常
        throw std::logic_error("Only one instance can be constructed.");
    }
    // 初始化配置
    reset();
}

OptionController::~OptionController()
{
    // 销毁单例
    _instance = nullptr;
}

OptionController &OptionController::instance()
{
    // 返回当前实例
    return (*_instance);
}

int OptionController::get_config(std::string opt)
{
    // 如果不存在配置
    if (!~config[opt])
    {
        // 初始化配置
        reset();
    }
    // 返回配置值
    return config[opt];
}

int OptionController::set_config(std::string opt, int value)
{
    // 设置哈希键值对
    return config[opt] = value;
}
