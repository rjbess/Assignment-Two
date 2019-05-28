//IOHelpers.h

//---------------------------------------------------------------------------------
#ifndef IOHelpers_H
#define IOHelpers_H

#include "OperatorOverloads.H"
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
    //void ConvertSpeed(float &inFloat)
    //{
      //  inFloat*=3.6;
    //}
    /**
		 * @brief  Converts the input Solar Radiation from W/m^2 to kWh/m^2.
		 *
		 * @param inFloat- A radiation value reference to convert
		 * @return Void
		 */
    //void ConvertRadiation(float &inFloat)
    //{
      //  inFloat*=0.00016666667;
    //}
    /**
		 * @brief  Takes in a speed value reference and adds
		 *         the windlog index speed it to itself.
		 *
		 * @param inFloat- A speed reference value
		 * @param inFloat- A index reference value
		 * @return Void
		 */
    /*void AddSpeed(float &elementIn, const BST<WindLogType> &W)
    {
        elementIn+=W.node->data.s;
    }*/
    /**
		 * @brief  Takes in a temp value reference and adds
		 *         the windlog index temp it to itself.
		 *
		 * @param inFloat- A temp reference value
		 * @param inFloat- A index reference value
		 * @return Void
		 */
    /**
		 * @brief  Takes in a radiation value reference and adds
		 *         the windlog index radiation it to itself.
		 *
		 * @param inFloat- A radiation reference value
		 * @param inFloat- A index reference value
		 * @return Void
		 */

    /**
		 * @brief  Takes in a float value reference and a
		 *         count refence to find the average of the float.
		 *
		 * @param ElementIn- A float reference value
		 * @param InSize- A int count reference value
		 * @return Void
		 */

    /**
		 * @brief  Takes in a Year value reference and boolean reference.
		 *         Checks to see if year and between or equal to windlog
		 * first and last indexes year. If so sets boolean to true.
		 *
		 * @param inYear- A unsigned year reference value
		 * @param inFound- A boolean reference value
		 * @return Void
		 */
    //void CheckYearInArrayHelper(unsigned& inYear, bool &inFound, const BST<WindLogType> &W)
    //{
      //  if(W->node)
        //{
          //  inFound=true;
        //}
    //}
    //void CheckYearInArray(unsigned& inYear, bool &inFound, const BST<WindLogType> &W)
    //{
      //  W.InOrderTrav(CheckYearInArrayHelper(inYear, inFound, W));
    //}
    /**
		 * @brief  Takes in a speed, count, month + year reference values and then loops
		 *       around the windlog vector. When a windlog indexs month+ year match the
		 * inputted values it uses the addspeed method and adds the count.
		 *
		 * @param inValue- A speed float reference value
		 * @param inCount- A count int reference value
		 * @param inMonth- A month unsigned reference value
		 * @param inYear- A year unsigned reference value
		 * @return Void
		 */
    void totalSpeedMonth(float &inValue, int &inCount, std::string &inDate, const BST<std::pair<std::string,std::string>> &B, const std::map<std::string, WindLogType> &M)
    {
        std::map<std::string, WindLogType>::iterator itr;
        std::string tempString= " ";
        std::pair <std::string, std::string> tempPair;


    }
        /**
		 * @brief  Takes in a temp, count, month + year reference values and then loops
		 *       around the windlog vector. When a windlog indexs month+ year match the
		 * inputted values it uses the addtemp method and adds the count.
		 *
		 * @param inValue- A temp float reference value
		 * @param inCount- A count int reference value
		 * @param inMonth- A month unsigned reference value
		 * @param inYear- A year unsigned reference value
		 * @return Void
		 */
    //void totalTempMonth(float &inValue, int &inCount, unsigned &inMonth, unsigned &inYear,const std::map<int, WindLogType> &W)
    //{
      //  for(unsigned index=0; index<W.GetSize();index++)
        //{
          //  if(W[index].d.GetMonth()==inMonth && W[index].d.GetYear()==inYear)
            //{
              //  AddTemp(inValue, index, W);
                //inCount++;
            //}
        //}
    //}
    /**
		 * @brief  Takes in a radiation, count, month + year reference values and then loops
		 *       around the windlog vector. When a windlog indexs month+ year match and solar
		 * radiation is above 100W/m2 the inputted values it uses the addradiation method and adds the count.
		 *
		 * @param radiation- A temp float reference value
		 * @param inCount- A count int reference value
		 * @param inMonth- A month unsigned reference value
		 * @param inYear- A year unsigned reference value
		 * @return Void
		 */
    //void totalRadiationMonth(float &inValue, int &inCount, unsigned &inMonth, unsigned &inYear,const std::map<int, WindLogType> &W)
    //{
      //  for(unsigned index=0; index<W.GetSize();index++)
        //{
          //  if(W[index].d.GetMonth()==inMonth && W[index].d.GetYear()==inYear)
            //{
              //  if(W[index].solarRadiation>=100)
                //{
                  //  AddRadiation(inValue, index, W);
                    //inCount++;
                //}
            //}
        //}
    //}
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
        while(input<1||input>5)
        {
            std::cout<<"Please enter a option number between 1 and 5: ";
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
    void ConvertMonth(std::string & monthString, unsigned & monthUnsigned)
    {
        std::string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        monthString=month[monthUnsigned-1];
    }
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
    void StoreMapToTree(BST<std::pair<std::string, std::map<std::string, WindLogType>::iterator>> &inBST, std::map<std::string, WindLogType> &inMap)
    {
        std::vector<std::pair<std::string, std::map<std::string, WindLogType>::iterator>> shuffleVector;
        std::map<std::string, WindLogType>::iterator itr;
        std::map<std::string, WindLogType>::iterator itr2;
        std::string tempMonth=" ";
        std::string tempString=" ";
        std::pair<std::string, std::map<std::string, WindLogType>::iterator>tempPair;

        for(itr=inMap.begin(); itr!=inMap.end(); ++itr)
        {
            tempString=itr->first;
            if(tempMonth.substr(0, 6)!=tempString.substr(0, 6))
            {
                tempMonth=tempString;
                tempPair.first=tempMonth.substr(0,6);
                tempPair.second=itr;
                shuffleVector.push_back(tempPair);
            }
            tempMonth=tempString;
        }
        unsigned seed= std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(shuffleVector.begin(), shuffleVector.end(), std::default_random_engine(seed));

        for(std::vector<std::pair<std::string, std::map<std::string, WindLogType>::iterator>>::iterator vItr=shuffleVector.begin(); vItr!=shuffleVector.end(); ++vItr)
        {
            tempPair=*vItr;
            inBST.Insert(tempPair);
        }
    }
}
#endif
