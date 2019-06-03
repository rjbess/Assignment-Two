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
    /**
	 * @class OperatorOverloads.H
	 * @brief  Global Overloaded Operator functions + helper functions use by the program
	 *
	 * File holds all the overload operator methods (<, ==, >) etc.
	 * for the program. It also contains some helper methods used by the operators
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 16/05/2019 Robert Bessell
	 *
	 * @version 02
	 * @date 3/06/2019 Robert Bessell
	 **/

//---------------------------------------------------------------------------------
    /**
     * @brief  Convert the string key to be insterted into the map
     *
     * Takes in and converts the key value for the map. It gets its values
     * off the struct passed in. ie Month, Day, Hours, minutes.
     *
     * @param inStringKey- String that represents the maps key
     * @param tempStruct- The struct that contains the data needed to create the key
     * @return void
     */
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
    /**
     * @brief  Helps read a Date Object from stream
     *
     * Takes in a in file stream and a Date object and
     * reads the values off the stream and sets the
     * date objects attributes.
     *
     * @param input- the in file stream
     * @param D - a date object
     * @return input- The in file stream
     */
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
    /**
     * @brief  Helps read a Time object off a stream
     *
     * Takes in a in file stream and a Time objects. Reads
     * off the stream and sets the Time object
     *
     * @param input- the in file stream
     * @param T- a time object
     * @return input- The in file stream
     */
std::istream & operator >>( std::istream & input, Time & T )
{
  std::string inString;
  getline(input, inString, ':');
  T.SetHours(stoul(inString));

  getline(input, inString, ',');
  T.SetMinutes(stoul(inString));

  return input;
}
    /**
     * @brief  Reads from the an in file stream and sets a map value
     *
     * Reads a in file stream and creates a temp WindLogType object
     * and temp string object. Sets the string object and searches the map
     * for a duplicate if so does nothing. Else sets the WindLogType object
     * and string key to the map
     *
     * @param input- the in file stream
     * @param W- map<string,WindLogType> object
     * @return input- The in file stream
     */
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
    /**
     * @brief  Writes the Date object to stream
     *
     * @param output- the out file stream
     * @param D- a date object
     * @return output- The out file stream
     */
std::ostream & operator <<( std::ostream & output,const Date & outDate)
{
    output<<outDate.GetDay()<<'/'<<outDate.GetMonth()<<'/'<<outDate.GetYear();
    return output;
}
    /**
     * @brief  Writes the Time object to stream
     *
     * @param output- the out file stream
     * @param T- a Time object
     * @return output- The out file stream
     */
std::ostream & operator <<(  std::ostream & output, const Time & outTime)
{
    output<<outTime.GetHours()<<':'<<outTime.GetMinutes();
    return output;
}
    /**
     * @brief  Compares the monthTotalStructs key to less then return a bool
     *
     * @param lhs- Const reference to a monthTotalStruct
     * @param rhs- Const reference to a monthTotalStruct,
     * @return bool
     */
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
    /**
     * @brief  Compares the monthTotalStructs key to greater then return a bool
     *
     * @param lhs- Const reference to a monthTotalStruct
     * @param rhs- Const reference to a monthTotalStruct,
     * @return bool
     */
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
    /**
     * @brief  Compares the monthTotalStructs key to equal to return a bool
     *
     * @param lhs- Const reference to a monthTotalStruct
     * @param rhs- Const reference to a monthTotalStruct,
     * @return bool
     */
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
    /**
     * @brief  Compares the WindLogType key to less then return a bool
     *
     * Returns a bool after comparing the date and time values of two
     * WindLogType structs
     *
     * @param lhs- Const reference to a WindLogType
     * @param rhs- Const reference to a WindLogType,
     * @return bool
     */
/*bool operator<(const WindLogType& lhs, const WindLogType& rhs)
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
}*/
    /**
     * @brief  Compares the WindLogType key to greater then return a bool
     *
     * Returns a bool after comparing the date and time values of two
     * WindLogType structs
     *
     * @param lhs- Const reference to a WindLogType
     * @param rhs- Const reference to a WindLogType,
     * @return bool
     */
/*bool operator>(const WindLogType& lhs, const WindLogType& rhs)
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
}*/
    /**
     * @brief  Compares the WindLogType key to equal to return a bool
     *
     * Returns a bool after comparing the date and time values of two
     * WindLogType structs
     *
     * @param lhs- Const reference to a WindLogType
     * @param rhs- Const reference to a WindLogType,
     * @return bool
     */
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
    /**
     * @brief  Compares the pair<string, WindLogType> key to less then return a bool
     *
     * Returns a bool after comparing the date and time values of two key values of the
     * WindLogType pair
     *
     * @param lhs- Const reference to a pair<string, WindLogType>
     * @param rhs- Const reference to a pair<string, WindLogType>,
     * @return bool
     */
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
    /**
     * @brief  Compares the pair<string, WindLogType> key to greater then ,returns a bool
     *
     * Returns a bool after comparing the date and time values of two key values of the
     * WindLogType pair
     *
     * @param lhs- Const reference to a pair<string, WindLogType>
     * @param rhs- Const reference to a pair<string, WindLogType>
     * @return bool
     */
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
    /**
     * @brief  Compares the pair<string, WindLogType> key to equal to, returns a bool
     *
     * Returns a bool after comparing the date and time values of two key values of the
     * WindLogType pair
     *
     * @param lhs- Const reference to a pair<string, WindLogType>
     * @param rhs- Const reference to a pair<string, WindLogType>,
     * @return bool
     */
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
