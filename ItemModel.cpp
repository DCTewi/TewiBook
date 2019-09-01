#include "ItemModel.h"

bool Date::operator< (const Date &b) const
{
    // 以年月日小时分钟的顺序比对两个时间
    return (year != b.year)? year < b.year:
        (month != b.month)? month < b.month:
        (day != b.day)? day < b.day:
        (hour != b.hour)? hour < b.hour:
        min < b.min;
}

bool Date::operator> (const Date &b) const
{
    return !(*this < b);
}

ItemModel::ItemModel(bool isincome, double v, Date tim, std::string typ, std::string exnote)
{
    is_income = isincome;
    value = v;
    if (typ.empty()) type = "-";
    else type = typ;
    if (exnote.empty()) note = "-";
    else note = exnote;
    time = tim;
}

void ItemModel::show()
{
    printf("Value:\t%s%.2lf\n", (is_income)?"+":"-", value);
    printf("Type:\t%s\nNote:\t%s\n", type.c_str(), note.c_str());
    printf("Time:\t%.4d/%.2d/%.2d %.2d:%.2d\n", time.year, time.month, time.day, time.hour, time.min);
}

std::istream &operator>> (std::istream &in, ItemModel &i)
{
    in >> i.is_income >> i.value
       >> i.time.year >> i.time.month >> i.time.day
       >> i.time.hour >> i.time.min
       >> i.type >> i.note;
    return in;
}

std::ostream &operator<< (std::ostream &out, ItemModel &i)
{
    out << i.is_income << " "
        << i.value << " "
        << i.time.year << " "
        << i.time.month << " "
        << i.time.day << " "
        << i.time.hour << " "
        << i.time.min << " "
        << i.type << " "
        << i.note;
    return out;
}
