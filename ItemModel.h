#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <bits/stdc++.h>

struct Date
{
    int year = 1940, month = 1, day = 1;
    int hour = 0, min = 0;

    Date() {}

    Date(int y,int m = 1, int d = 1): 
        year(y), month(m), day(d) {}
    
    Date(int h, int m = 0): 
        hour(h), min(m) {}

    Date(int y, int mon = 1, int d = 1, int h = 0, int min = 1):
        year(y), month(mon), day(d), hour(h), min(min) {}

    ~Date() {}

    bool operator< (const Date &b) const;
    bool operator> (const Date &b) const;
};

class ItemModel
{
public:
    long long int ID = -1;
    bool is_income = false;
    double value = 0.0;
    std::string type = "-";
    std::string note = "-";
    Date time;

    ItemModel() {}
    ItemModel(bool isincome, double v, Date time, std::string type = "-", std::string note = "-");
    ~ItemModel() {}

    friend std::istream &operator>> (std::istream &in, ItemModel &i);
    friend std::ostream &operator<< (std::ostream &out, ItemModel &i);

    void show();
};

#endif // ITEMMODEL_H
