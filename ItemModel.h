#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <bits/stdc++.h>

/**
 * 整数日期&时间类
 */
struct Date
{
    int year = 1940, month = 1, day = 1;
    int hour = 0, min = 0;

    /**
     * 空构造函数
     */
    Date() {}

    /**
     * 年月日构造函数
     */
    Date(int y,int m = 1, int d = 1): 
        year(y), month(m), day(d) {}
    
    /**
     * 小时分钟构造函数
     */
    Date(int h, int m = 0): 
        hour(h), min(m) {}

    /**
     * 完整构造函数
     */
    Date(int y, int mon = 1, int d = 1, int h = 0, int min = 1):
        year(y), month(mon), day(d), hour(h), min(min) {}

    /**
     * 默认析构函数
     */
    ~Date() {}

    /**
     * 大于号运算符
     */
    bool operator< (const Date &b) const;
    /**
     * 小于号运算符
     */
    bool operator> (const Date &b) const;
};

/**
 * 项目模板类
 * 用于处理流水数据
 */
class ItemModel
{
public:
    long long int ID = -1; // 运行时 ID
    bool is_income = false; // 是否为收入
    double value = 0.0; // 值
    std::string type = "-"; // 分类
    std::string note = "-"; // 备注
    Date time; // 消费时间

    /**
     * 空构造函数
     */
    ItemModel() {}
    /**
     * 完整参数构造函数
     */
    ItemModel(bool isincome, double v, Date time, std::string type = "-", std::string note = "-");
    /**
     * 默认析构函数
     */
    ~ItemModel() {}

    /**
     * 流输入运算符
     */
    friend std::istream &operator>> (std::istream &in, ItemModel &i);
    /**
     * 流输出运算符
     */
    friend std::ostream &operator<< (std::ostream &out, ItemModel &i);

    /**
     * 向控制台以固定格式输出
     */
    void show();
};

#endif // ITEMMODEL_H
