 //IOHelpers.h

//---------------------------------------------------------------------------------
#ifndef IOHelpers_H
#define IOHelpers_H

#include "OperatorOverloads.H"
#include "monthTotalStruct.h"
#include <cmath>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "chrono"

    /**
	 * @Namespace IOHelpers
	 * @brief A namespace which holds the read and calaculate
	 * data off the Binary Trees and display them to the user.
	 * Does not modify the data on the trees in anyway.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 17/04/2019
	 *
	 * @version 02
	 * @date 03/06/2019
	 */
namespace IOHelpers
{
        /**
		 * @brief  Helper method checks to see if year is valid
		 *
		 * Takes in a bool value, sate string and monthTotalBST.
		 * Checks if the inputted dates year is in the tree.
		 * Changes the bool value if found.
		 *
		 * @param inFound -Bool value of whether the year is in the tree
		 * @param inDate- String value representing the year to be searched
         * @param B- BST to be searched
		 * @return Void
		 */
    void CheckYearInTree(bool &inFound, std::string &inDate,BST<monthTotalStruct>const &B)
    {
        monthTotalStruct tempStruct;
        monthTotalStruct tempStruct2;

        tempStruct.key=inDate.substr(0,4)+"01";
        tempStruct2.key=inDate.substr(0,4)+"12";

        inFound=B.Search(tempStruct);
        if(inFound==false)
        {
            inFound= B.Search(tempStruct2);
        }
    }
        /**
		 * @brief  Converts a unsigned month to its string counterpart
		 *
		 * @param monthString- String month value
		 * @param monthUnsigned- Unsigned month value
		 * @return Void
		 */
    void ConvertMonth(std::string & monthString, unsigned & monthUnsigned)
    {
        std::string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        monthString=month[monthUnsigned-1];
    }
        /**
		 * @brief  Converts a string to the correct key format
		 *
		 * @param inMonth -Int of the wanted month
		 * @param inYear- Int of the wanted year
         * @param inString- the string to be converted to the key value
		 * @return Void
		 */
    void ConvertDateToString(unsigned &inMonth, unsigned &inYear, std::string &inString)
    {
        inString=std::to_string(inYear);
        if(inMonth<10)
        {
            inString+="0"+ std::to_string(inMonth);
        }
        else
        {
            inString+=std::to_string(inMonth);
        }
    }
        /**
		 * @brief  Converts the input speed from m/s to km/h.
		 *
		 * @param inFloat- A speed value reference to convert
		 * @return Void
		 */
    void ConvertSpeed(float &inFloat)
    {
        inFloat*=3.6;
    }
        /**
		 * @brief  Converts the input Solar Radiation from W/m^2 to kWh/m^2.
		 *
		 * @param inFloat- A radiation value reference to convert
		 * @return Void
		 */
    void ConvertRadiation(float &inFloat)
    {
        inFloat*=0.00016666667;
    }
        /**
		 * @brief  Finds an average of a value and count
		 *
		 * @param inFloat- A float to be averaged
		 * @param inCount- The count
		 * @return Void
		 */
    void GetAverage(float &inFloat, unsigned &inCount)
    {
        inFloat/=inCount;
    }
        /**
		 * @brief  Prints out a months Speed and Wind values.
		 *
		 * Takes in a key value and converts it to the proper form.
		 * Searches the BST for the key and if valid will search the
		 * BST for the data and print it out. If not will print out a No Data
		 *
		 * @param inDate- String representing the month and year
		 * @param B- A monthTotalStruct BST
		 * @return Void
		 */
    void displayMonthTotals(std::string &inDate,  BST<monthTotalStruct>const &B)
    {
        bool found=false;

        monthTotalStruct tempStruct;
        std::string tempString= inDate;

        unsigned tempInt= stoul(tempString.substr(4,2));

        ConvertMonth(tempString, tempInt);
        tempStruct.key=inDate;
        found=B.Search(tempStruct);

        if(found==true)
        {
            tempStruct= B.GetData(tempStruct);
             std::cout<<std::setprecision(1)<<std::fixed<<tempString
                 <<" "<<tempStruct.key.substr(0,4)<<": "<<tempStruct.totalAirTemp<< " degrees C, "<<tempStruct.totalSpeed<<" km/h"<<'\n';
        }
        else
        {
            std::cout<<tempString<<" "<<inDate.substr(0,4)<<": "<<"No Data"<<'\n';
        }

    }
        /**
		 * @brief  Prints out a years worth of Speed and Wind values.
		 *
		 * Takes in a key value and converts it to the proper form. For every month it
		 * searches the BST for the key and if valid will search the
		 * BST for the data and print it out. If not will print out a No Data
		 *
		 * @param inDate- String representing the year
		 * @param B- A monthTotalStruct BST
		 * @return Void
		 */
    void DisplayYearTotals(std::string &inYear, BST<monthTotalStruct>const &B)
    {
        std::string tempString=inYear;
        std::string stringMonth=" ";
        monthTotalStruct tempStruct;

        for(unsigned i=1; i<13;i++)
        {
            bool found=false;

            if(i<10)
            {
                tempString+="0"+std::to_string(i);
            }
            else
            {
                tempString+=std::to_string(i);
            }

            ConvertMonth(stringMonth, i);
            tempStruct.key=tempString;

            found=B.Search(tempStruct);
            if(found==true)
            {
                tempStruct= B.GetData(tempStruct);

                std::cout<<std::setprecision(1)<<std::fixed<<stringMonth<<" "<< tempStruct.key.substr(0, 4)
                         <<": "<<tempStruct.totalSpeed<<"km/h, "<<tempStruct.totalAirTemp<<" degrees C"<<'\n';
            }
            else
            {
                std::cout<<stringMonth<<" "<<tempStruct.key.substr(0,4)<<": "<<"No Data"<<'\n';
            }
            tempString=tempStruct.key.substr(0,4);
        }
    }
    /**
		 * @brief  Prints out a years worth of Radiation values.
		 *
		 * Takes in a key value and converts it to the proper form. For every month it
		 * searches the BST for the key and if valid will search the
		 * BST for the data and print it out. If not will print out a No Data
		 *
		 * @param inDate- String representing the year
		 * @param B- A monthTotalStruct BST
		 * @return Void
		 */
    void DisplayYearTotalsRad(std::string &inYear, BST<monthTotalStruct>const &B)
    {
        std::string tempString=inYear;
        std::string stringMonth=" ";
        monthTotalStruct tempStruct;

        for(unsigned i=1; i<13;i++)
        {
            bool found=false;
            if(i<10)
            {
                tempString+="0"+std::to_string(i);
            }
            else
            {
                tempString+=std::to_string(i);
            }

            ConvertMonth(stringMonth, i);
            tempStruct.key=tempString;

            found=B.Search(tempStruct);

            if(found==true)
            {
                tempStruct= B.GetData(tempStruct);

                std::cout<<std::setprecision(1)<<std::fixed<<stringMonth<<" "<< tempStruct.key.substr(0, 4)<<": "
                          <<tempStruct.totalSolarRadiation<<" kWh/m^2"<<'\n';
            }
            else
            {
                std::cout<<stringMonth<<" "<<tempStruct.key.substr(0,4)<<": "<<"No Data"<<'\n';
            }
            tempString=tempStruct.key.substr(0,4);
        }
    }
        /**
		 * @brief  Writes out a years worth of Speed,Wind + Radiation values to a file.
		 *
		 * Takes in a year value, monthTotal BST and an outfile stream
		 * Converts the year and checks to see if its in the BST. If not
		 * writes out No Data. Else writes out the monthly values.
		 *
		 * @param inYear- Unsigned year value
		 * @param B- A monthTotalStruct BST
		 * @param Out- OUt file stream
		 * @return Void
		 */
    void writeAllValues(unsigned &inYear, BST<monthTotalStruct>const&B, std::ofstream &out)
    {
        bool inMap=false;
        std::string tempString=std::to_string(inYear);
        CheckYearInTree(inMap, tempString, B);
        if(inMap==false)
        {
            out<<inYear<<'\n'<<"No Data";
        }
        else
        {
            std::string stringMonth=" ";
            monthTotalStruct tempStruct;
            out<<inYear<<'\n';

            for(unsigned i=1; i<13;i++)
            {
                bool found=false;
                if(i<10)
                {
                    tempString+="0"+std::to_string(i);
                }
                else
                {
                    tempString+=std::to_string(i);
                }

                ConvertMonth(stringMonth, i);
                tempStruct.key=tempString;
                found=B.Search(tempStruct);
                if(found==true)
                {
                    tempStruct= B.GetData(tempStruct);

                    out<<std::setprecision(1)<<std::fixed<<stringMonth<<","<<tempStruct.totalSpeed
                       <<","<<tempStruct.totalAirTemp<<","<<tempStruct.totalSolarRadiation<<'\n';
                }
                else
                {
                    out<<stringMonth<<","<<"No Data"<<'\n';
                }
                tempString=tempStruct.key.substr(0,4);
            }
        }
    }
        /**
		 * @brief  Helper method used by highestRadDay
		 *
		 * @param lhs- WindLogType struct
		 * @param rhs- WindLogType struct
		 * @return Void
		 */
    bool radiationCompare(WindLogType &lhs, WindLogType &rhs)
    {
        return lhs.solarRadiation<rhs.solarRadiation;
    }
        /**
		 * @brief  Prints out the highest radiation value of a day
		 *
		 * Takes in a string date value and a pair<string, WindLogType> BST.
		 * Creates a temp vector that holds every WindLog of a certaan day.
		 * Finds the highest value and prints of it and any values that
		 * have the same radiation value
		 *
		 * @param inDate- String value representing the day/month/year
		 * @param inBST- pair<string, Windlog> BST holding all the Windlogs
		 * @return Void
		 */
    void GetHighestRadDay(std::string &inDate, BST<std::pair<std::string, WindLogType>>const &inBST)
    {
        std::vector<WindLogType>tempVector;
        std::string tempString="";

        bool found= false;
        std::pair<std::string, WindLogType>tempPair;

        for(unsigned index=1; index<150;index++)
        {
            tempString=inDate;
            tempString+=std::to_string(index);
            tempPair.first=tempString;
            found= inBST.Search(tempPair);
            if(found==true)
            {
                tempPair=inBST.GetData(tempPair);
                tempVector.push_back(tempPair.second);
            }
        }
        if(tempVector.empty())
        {
            std::cout<<"Day not found"<<'\n';
        }
        else
        {
            std::vector<WindLogType>::iterator itr;

            itr= std::max_element(tempVector.begin(), tempVector.end(), radiationCompare);
            std::cout<<"Date: "<<(*itr).d<<'\n';
            std::cout<<"Highest Solar Radiation for the day: "<<(*itr).solarRadiation<<" w/m^2"<<'\n';
            std::cout<<"Time"<<'\n';
            std::cout<<(*itr).t<<'\n';
            for(std::vector<WindLogType>::iterator itr2=tempVector.begin(); itr2!=tempVector.end(); ++itr2)
            {
                if((*itr2).solarRadiation==(*itr).solarRadiation && itr2!=itr)
                {
                    std::cout<<(*itr2).t<<'\n';
                }
            }
        }
    }

        /**
		 * @brief  Takes in a input value reference and checks the bounds
		 *      of 1 and 6 and will loop until the user enters a valid input
		 *
		 * @param input- A input unsigned reference value
		 * @return Void
		 */
   void GetInput(unsigned &input)
   {
        std::cout<<"Enter: ";
        std::cin>>input;
        while(input<1||input>6)
        {
            std::cout<<"Please enter a option number between 1 and 6: ";
            std::cin>>input;
        }
    }
        /**
		 * @brief  Takes in a map<string, WindLogType> and a in File to set
		 *
		 * Takes in a map object and a file name. Opens a file stream and
		 * reads everline which represents a file and sets its values to the map
		 * object
		 *
		 * @param W- A map<string, WindLogType> refernce object
		 * @param fileName-String file name of the file to be read
		 * @return Void
		 */
     void ReadFileMap(std::map<std::string, WindLogType> &W, std::string &fileName)
    {
        std::string inString;

        std::ifstream inFile(fileName);
        while(std::getline(inFile, inString))
        {
            std::ifstream newFile(inString);
            if(!newFile.is_open())
            {
                return;
            }
            newFile>>W;
            newFile.close();
            newFile.clear();
        }
        inFile.close();
    }
        /**
		 * @brief  Takes in a map<string, WindLogType> and sets it to a monthTotalStruct BST
		 *
		 * Reads every object in the map and for every month, totals the values and converts
		 * them to be stored in a monthTotal Struct. It stores theses strcuts in a temp vector,
		 * which is then shuffled and read into a BST.
		 *
		 * @param inMap- A map<string, WindLogType> reference object
		 * @param inBST- BST object holding monthTotalStructs
		 * @return Void
		 */
    void StoreMapToMonthTree(BST<monthTotalStruct> &inBST, std::map<std::string, WindLogType> &inMap)
    {
        std::vector<monthTotalStruct> shuffleVector;
        std::map<std::string, WindLogType>::iterator itr;
        std::string month1=" ";
        std::string month2=" ";
        unsigned countD=0;

        monthTotalStruct tempMonthWindLog;

        for(itr=inMap.begin(); itr!=inMap.end(); ++itr)
        {
            month1=(*itr).first;
            if((month1.substr(0,6)!=month2.substr(0,6) && month2!=" ")||itr==(--inMap.end()))
            {
                tempMonthWindLog.key=month2.substr(0, 6);
                GetAverage(tempMonthWindLog.totalSpeed, countD);
                GetAverage(tempMonthWindLog.totalAirTemp, countD);
                ConvertSpeed(tempMonthWindLog.totalSpeed);
                ConvertRadiation(tempMonthWindLog.totalSolarRadiation);
                shuffleVector.push_back(tempMonthWindLog);

                countD=0;

                tempMonthWindLog.totalAirTemp=0;
                tempMonthWindLog.totalSolarRadiation=0;
                tempMonthWindLog.totalSpeed=0;

                month2=month1;
            }
            tempMonthWindLog.totalAirTemp+=(*itr).second.airTemp;

            if(itr->second.solarRadiation>=100)
            {
                tempMonthWindLog.totalSolarRadiation+=(*itr).second.solarRadiation;
            }
            tempMonthWindLog.totalSpeed+=(*itr).second.speed;

            countD++;
            month2=month1;
        }
        unsigned seed= std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(shuffleVector.begin(), shuffleVector.end(), std::default_random_engine(seed));

        for(std::vector<monthTotalStruct>::iterator vItr=shuffleVector.begin(); vItr!=shuffleVector.end(); ++vItr)
        {
            tempMonthWindLog=*vItr;
            inBST.Insert(tempMonthWindLog);
        }
    }
        /**
		 * @brief  Takes in a map<string, WindLogType> and sets it to a monthTotalStruct BST
		 *
		 * Reads every object in the map and for everyday changes the key value for the BST pair
		 * to be the year, month, day and a unique counter value which resets every day, the WindlogType
		 * values are read over as the second value.
		 * These pairs are then sotred an a temp vector, shuffled and read into the pair<string, Windlog> BST
		 *
		 * @param inMap- A map<string, WindLogType> reference object
		 * @param inBST- BST object holding pair<string, WindLogType>
		 * @return Void
		 */
    void StoreMapToDayTree(BST<std::pair<std::string, WindLogType>> &inBST, std::map<std::string, WindLogType> &inMap)
    {
        std::vector<std::pair<std::string, WindLogType>> shuffleVector;
        std::map<std::string, WindLogType>::iterator itr;

        std::pair<std::string, WindLogType> tempPair;

        unsigned countD=1;

        for(itr=inMap.begin(); itr!=inMap.end(); ++itr)
        {
            if((*itr).first.substr(0, 8)==tempPair.first.substr(0,8))
            {
                tempPair.first=(*itr).first.substr(0, 8)+std::to_string(countD);
                countD++;
            }
            else
            {
                countD=1;
                tempPair.first=(*itr).first.substr(0, 8)+std::to_string(countD);
            }
            tempPair.second=(*itr).second;
            shuffleVector.push_back(tempPair);
        }
        unsigned seed= std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(shuffleVector.begin(), shuffleVector.end(), std::default_random_engine(seed));

         for(std::vector<std::pair<std::string,WindLogType>>::iterator vItr=shuffleVector.begin(); vItr!=shuffleVector.end(); ++vItr)
        {
            inBST.Insert(*vItr);
        }
    }
}
#endif
