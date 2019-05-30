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
	 * @brief A namespace which holds the methods use to help
	 *         other methods in reading or viewing the data
	 * for the windlog vector. Does not modify the vector in any
	 * way, will either read off it and convert non member values
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 17/04/2019
	 *
	 */
namespace IOHelpers
{
    void CheckDateInMap(bool &inFound, std::string &inDate,std::map<std::string, WindLogType>const &M)
    {
        std::map<std::string, WindLogType>::const_iterator itr;

        for(itr=M.begin();itr!=M.end();std::advance(itr, 100))
        {
            if(inDate==itr->first.substr(0, 6))
            {
                inFound=true;
                break;
            }
        }
    }
    void CheckYearInMap(bool &inFound, std::string &inDate,std::map<std::string, WindLogType>const &M)
    {
        std::map<std::string, WindLogType>::const_iterator itr=M.begin();
        std::map<std::string, WindLogType>::const_iterator itr2=--M.end();

        if(inDate>=itr->first.substr(0, 4) &&inDate<=itr2->first.substr(0, 4))
        {
            inFound=true;
        }
    }
    void ConvertMonth(std::string & monthString, unsigned & monthUnsigned)
    {
        std::string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        monthString=month[monthUnsigned-1];
    }
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
    void GetAverage(float &inFloat, unsigned &inCount)
    {
        inFloat/=inCount;
    }

    void displayMonthTotals(std::string &inDate,  BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const &M)
    {
        bool found=false;

        monthTotalStruct tempStruct;
        std::string tempString= " ";
        unsigned tempInt= stoul(inDate.substr(5,6));
        ConvertMonth(tempString, tempInt);
        tempStruct.key=inDate;

        CheckDateInMap(found, inDate, M);

        if(found==true)
        {
            tempStruct= B.Search(tempStruct);
             std::cout<<std::setprecision(1)<<std::fixed<<tempString
                 <<" "<<tempStruct.key.substr(0,4)<<": "<<tempStruct.totalAirTemp<< " degrees C, "<<tempStruct.totalSpeed<<" km/h"<<'\n';
        }
        else
        {
            std::cout<<tempString<<" "<<inDate.substr(0,4)<<": "<<"No Data"<<'\n';
        }

    }
    void DisplayYearTotals(std::string &inYear, BST<monthTotalStruct>&B, std::map<std::string, WindLogType>const&M)
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
            CheckDateInMap(found, tempString, M);
            ConvertMonth(stringMonth, i);
            tempStruct.key=tempString;

            if(found==true)
            {
                tempStruct= B.Search(tempStruct);

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
    void DisplayYearTotalsRad(std::string &inYear, BST<monthTotalStruct>&B, std::map<std::string, WindLogType>const&M)
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
            CheckDateInMap(found, tempString, M);
            ConvertMonth(stringMonth, i);
            tempStruct.key=tempString;

            if(found==true)
            {
                tempStruct= B.Search(tempStruct);

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
    void writeAllValues(unsigned &inYear, BST<monthTotalStruct>&B, std::map<std::string, WindLogType>const&M, std::ofstream &out)
    {
        bool inMap=false;
        std::string tempString=std::to_string(inYear);
        CheckYearInMap(inMap, tempString, M);
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
                CheckDateInMap(found, tempString, M);
                ConvertMonth(stringMonth, i);
                tempStruct.key=tempString;

                if(found==true)
                {
                    tempStruct= B.Search(tempStruct);

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
		 * @brief  Takes in a input value reference and checks the bounds
		 *      of 1 and 5 and will loop until the user enters a valid input
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
		 * @brief  Takes in a string month reference and unsigned moth reference.
		 *       Creates an array of months in string and uses the unsigned month
		 * to set the corresponding string value.
		 *
		 * @param monthString- A month string reference value
		 * @param monthUnsigned- A month unsigned reference value
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
    void StoreMapToTree(BST<monthTotalStruct> &inBST, std::map<std::string, WindLogType> &inMap)
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
}
#endif
