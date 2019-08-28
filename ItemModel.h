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
};

class ItemModel
{
private:
    long long int ID = -1;
public:
    bool is_income = false;
    double value = 0.0;
    std::string type;
    std::string note;
    Date time;

    ItemModel() {}
    ItemModel(long long int id, bool isincome, double v, Date time, std::string type = "", std::string note = "");
    ~ItemModel() {}
};

ItemModel::ItemModel(long long int id, bool isincome, double v, Date tim, std::string typ = "", std::string exnote = "")
{
    ID = id;
    is_income = isincome;
    value = v;
    type = typ;
    note = exnote;
    time = tim;
}

#endif // ITEMMODEL_H
