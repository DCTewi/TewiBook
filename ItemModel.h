#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <bits/stdc++.h>

/**
 * @brief 整数日期&时间类
 */
struct Date
{
    // 年月日
    int year = 1940, month = 1, day = 1;
    // 日期
    int hour = 0, min = 0;

    /**
     * @brief 空构造函数
     */
    Date() {}

    /**
     * @brief 年月日构造函数
     */
    Date(int y, int m = 1, int d = 1)
    {
        year = y;
        month = m;
        day = d;
    }
    
    /**
     * @brief 小时分钟构造函数
     */
    Date(int h, int m = 0)
    {
        hour = h;
        min = m;
    }

    /**
     * @brief 完整构造函数
     */
    Date(int y, int mon = 1, int d = 1, int h = 0, int mi = 1)
    {
        year = y;
        month = mon;
        day = d;
        hour = h;
        min = mi;
    }

    /**
     * @brief 默认析构函数
     */
    ~Date() {}

    /**
     * @brief 大于号运算符
     */
    bool operator< (const Date &b) const;
    /**
     * @brief 小于号运算符
     */
    bool operator> (const Date &b) const;
};

/**
 * @brief 项目模板类
 * @note 用于处理流水数据
 */
class ItemModel
{
public:
    /**
     * @brief 运行时 ID
     */
    long long int ID = -1;
    /**
     * @brief 是否为收入
     */
    bool is_income = false;
    /**
     * @brief 值
     */
    double value = 0.0;
    /**
     * @brief 分类
     */
    std::string type = "-";
    /**
     * @brief 备注
     */
    std::string note = "-";
    /**
     * @brief 消费时间
     */
    Date time;

    /**
     * @brief 空构造函数
     */
    ItemModel() {}
    /**
     * @brief 完整参数构造函数
     */
    ItemModel(bool isincome, double v, Date time, std::string type = "-", std::string note = "-");
    /**
     * @brief 默认析构函数
     */
    ~ItemModel() {}

    /**
     * @brief 流输入运算符
     */
    friend std::istream &operator>> (std::istream &in, ItemModel &i);
    /**
     * @brief 流输出运算符
     */
    friend std::ostream &operator<< (std::ostream &out, ItemModel &i);

    /**
     * @brief 向控制台以固定格式输出
     */
    void show();
};

#endif // ITEMMODEL_H
