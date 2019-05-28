#include "TIME.H"

Time::Time()
{
    hours=00;
    minutes=00;
}
Time::Time(unsigned inHours, unsigned inMinutes)
{
    hours=inHours;
    minutes=inMinutes;
}
unsigned Time::GetHours()const
{
    return hours;
}
void Time::SetHours(unsigned inHours)
{
    hours=inHours;
}
unsigned Time::GetMinutes()const
{
    return minutes;
}
void Time::SetMinutes(unsigned inMinutes)
{
    minutes=inMinutes;
}
