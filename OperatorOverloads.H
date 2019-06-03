//OperatorOverloads.H

//---------------------------------------------------------------------------------

#ifndef OperatorOverloads_H
#define OperatorOverloads_H

//---------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <iomanip>
#include "DATE.H"
#include "TIME.H"
#include "WINDLOGTYPE.H"
#include "BinarySearchTree.h"
#include "monthTotalStruct.h"
#include <map>

//---------------------------------------------------------------------------------

void ConvertKey( std::string &inStringKey,const WindLogType &tempStruct)
{
    inStringKey= std::to_string(tempStruct.d.GetYear());

    if(tempStruct.d.GetMonth()<10)
    {
        inStringKey+= "0"+std::to_string(tempStruct.d.GetMonth());
    }
    else
    {
         inStringKey+=std::to_string(tempStruct.d.GetMonth());
    }
    if(tempStruct.d.GetDay()<10)
    {
        inStringKey+= "0"+std::to_string(tempStruct.d.GetDay());
    }
    else
    {
         inStringKey+=std::to_string(tempStruct.d.GetDay());
    }
    if(tempStruct.t.GetHours()<10)
    {
        inStringKey+= "0"+std::to_string(tempStruct.t.GetHours());
    }
    else
    {
         inStringKey+=std::to_string(tempStruct.t.GetHours());
    }
    if(tempStruct.t.GetMinutes()<10)
    {
        inStringKey+= "0"+std::to_string(tempStruct.t.GetMinutes());
    }
    else
    {
         inStringKey+=std::to_string(tempStruct.t.GetMinutes());
    }
}
std::istream & operator >>(  std::istream & input, Date & D )
{
  std::string inString;

  getline(input, inString, '/');
  D.SetDay(stoul(inString));

  getline(input, inString, '/');
  D.SetMonth(stoul(inString));

  getline(input, inString, ' ');
  D.SetYear(stoul(inString));

  return input;
}
std::istream & operator >>( std::istream & input, Time & T )
{
  std::string inString;
  getline(input, inString, ':');
  T.SetHours(stoul(inString));

  getline(input, inString, ',');
  T.SetMinutes(stoul(inString));

  return input;
}
std::istream & operator >>(std::istream & input, std::map<std::string, WindLogType> & W)
{
    std::string inString=" ";
    input.ignore(1000, '\n');
    std::string stringKey=" " ;
    std::map<std::string, WindLogType>::iterator itr;

    WindLogType tempStruct;

    while(input.peek()!=EOF)
        {
            try
            {
                Date tempDate;
                input>>tempDate;
                tempStruct.d=tempDate;

                Time tempTime;
                input>>tempTime;
                tempStruct.t=tempTime;

                if(input.peek()!='N')
                {
                    for(unsigned index=0;index<9;index++)
                    {
                        input.ignore(100, ',');
                    }
                    getline(input, inString, ',');
                    tempStruct.speed=(stof(inString));

                    getline(input, inString, ',');
                    tempStruct.solarRadiation=(stof(inString));

                    for(unsigned index=0;index<5;index++)
                    {
                        input.ignore(100, ',');
                    }
                    getline(input, inString);
                    tempStruct.airTemp=(stof(inString));

                    ConvertKey(stringKey, tempStruct);

                    itr=W.find(stringKey);
                    if(itr==W.end())
                    {
                        W.insert({stringKey,tempStruct});
                    }
                }
                else
                {
                    input.ignore(1000, '\n');
                }
            }
            catch( std::invalid_argument& e)
            {
                std::cout<<"crash";
            }
        }
    return input;
}
std::ostream & operator <<( std::ostream & output,const Date & outDate)
{
    output<<outDate.GetDay()<<'/'<<outDate.GetMonth()<<'/'<<outDate.GetYear();
    return output;
}
std::ostream & operator <<(  std::ostream & output, const Time & outTime)
{
    output<<outTime.GetHours()<<':'<<outTime.GetMinutes();
    return output;
}
bool operator<(const monthTotalStruct& lhs, const monthTotalStruct& rhs)
{
    if(lhs.key<rhs.key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(const monthTotalStruct& lhs, const monthTotalStruct& rhs)
{
    if(lhs.key>rhs.key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator==( monthTotalStruct &lhs, monthTotalStruct &rhs)
{
    if(lhs.key==rhs.key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<(const WindLogType& lhs, const WindLogType& rhs)
{
    if(lhs.d.GetYear()<rhs.d.GetYear())
    {
        return true;
    }
    else if(lhs.d.GetYear()>rhs.d.GetYear())
    {
        return false;
    }
    else if(lhs.d.GetMonth()<rhs.d.GetMonth())
    {
        return true;
    }
    else if(lhs.d.GetMonth()>rhs.d.GetMonth())
    {
        return false;
    }
    else if(lhs.d.GetDay()<rhs.d.GetDay())
    {
        return true;
    }
    else if(lhs.d.GetDay()>rhs.d.GetDay())
    {
        return false;
    }
    else if(lhs.t.GetHours()<rhs.t.GetHours())
    {
        return true;
    }
    else if(lhs.t.GetHours()>rhs.t.GetHours())
    {
        return false;
    }
    else if(lhs.t.GetMinutes()<rhs.t.GetMinutes())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(const WindLogType& lhs, const WindLogType& rhs)
{
   if(lhs.d.GetYear()>rhs.d.GetYear())
    {
        return true;
    }
    else if(lhs.d.GetYear()<rhs.d.GetYear())
    {
        return false;
    }
    else if(lhs.d.GetMonth()>rhs.d.GetMonth())
    {
        return true;
    }
    else if(lhs.d.GetMonth()<rhs.d.GetMonth())
    {
        return false;
    }
    else if(lhs.d.GetDay()>rhs.d.GetDay())
    {
        return true;
    }
    else if(lhs.d.GetDay()<rhs.d.GetDay())
    {
        return false;
    }
    else if(lhs.t.GetHours()>rhs.t.GetHours())
    {
        return true;
    }
    else if(lhs.t.GetHours()<rhs.t.GetHours())
    {
        return false;
    }
    else if(lhs.t.GetMinutes()>rhs.t.GetMinutes())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator==( WindLogType &lhs, WindLogType &rhs)
{
    if(lhs.d.GetYear()==rhs.d.GetYear() &&lhs.d.GetMonth()==rhs.d.GetMonth()&&lhs.d.GetDay()==rhs.d.GetDay()
       && lhs.t.GetHours()==rhs.t.GetHours()&&lhs.t.GetMinutes()==rhs.t.GetMinutes())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator <(std::pair<std::string, WindLogType>&lhs, std::pair<std::string, WindLogType>&rhs)
{
    if(lhs.first<rhs.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator >(std::pair<std::string, WindLogType>&lhs, std::pair<std::string, WindLogType>&rhs)
{
    if(lhs.first>rhs.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator ==(std::pair<std::string, WindLogType>&lhs, std::pair<std::string, WindLogType>&rhs)
{
    if(lhs.first==rhs.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif
