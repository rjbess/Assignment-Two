// DATE.CPP - date class implementation

//---------------------------------------------------------------------------------

#include "DATE.H"

//---------------------------------------------------------------------------------

Date::Date()
{
    day=1;
    month=1;
    year=1900;
}
Date::Date(unsigned inDay, unsigned inMonth, unsigned inYear)
{
    day=inDay;
    month=inMonth;
    year=inYear;
}
unsigned Date::GetDay()const
{
    return day;
}
void Date::SetDay(unsigned inDay)
{
    day=inDay;
}
unsigned Date::GetMonth()const
{
    return month;
}
void Date::SetMonth(unsigned inMonth)
{
    month=inMonth;
}
unsigned Date::GetYear()const
{
    return year;
}
void Date::SetYear(unsigned inYear)
{
    year=inYear;
}
