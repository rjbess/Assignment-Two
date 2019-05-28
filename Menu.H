//Menu.h

//---------------------------------------------------------------------------------

#ifndef Menu_H
#define Menu_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "string"
#include "IOHelpers.H"
#include "BinarySearchTree.h"

//---------------------------------------------------------------------------------

/**
	 * @Namespace Menu
	 * @brief A namespace which holds the methods use to create the
	 *          programs command line menu. The main menu() calls
	 * the other menu functions and will loop around until the user exits.
	 * Methods in this namespace will call the helper functions of the
	 * IOhelpers namespace.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 17/04/2019
	 *
	 */


namespace menu
{
    /**
		 * @brief  Displays the menus starting page.
		 *
		 * @return Void
		 */

    void WelcomeMenu()
    {
        std::cout<<"---------------------------------------------------------\n\n"
                 <<"                   Weather Station Details               \n\n"
                 <<"---------------------------------------------------------\n\n";
    }
    /**
		 * @brief  Displays the choices of the menu.
		 *
		 * @return Void
		 */

    void DisplayChoices()
    {
        std::cout<<"Enter (1) to view the average wind speed and average"
                 <<" air temperature for a certain month of a certain year"<<'\n'<<'\n';
        std::cout<<"Enter (2) to view the average wind speed and average"
                 <<" air temperature for each month of a certain year"<<'\n'<<'\n';
        std::cout<<"Enter (3) to view total solar radiation for each month"
                 <<" of a certain year"<<'\n'<<'\n';
        std::cout<<"Enter (4) to write the average wind speed, average air temperature"
                 <<" and total solar radiation for each month of a certain year to a file."<<'\n'<<'\n';
        std::cout<<"Enter (5) to exit"<<'\n'<<'\n';
    }
    /**
		 * @brief  Option One- Asks the user to enter a month and year.
         *          Using IOhelpers it will modify the local variables
         * and print out the months Average Wind Speed and Average Temp on screen.
		 *
		 * @return Void
		 */

    void Option1(const BST<std::pair<std::string, std::string>> &B, const std::map<std::string, WindLogType> &M)
    {
        std::string stringMonth=" ";
        std::string stringDate=" ";
        unsigned month=0;
        unsigned year=0;
        float averageWindSpeed=0;
        float averageTemp=0;
        int windCount=0;
        int tempCount=0;

        std::cout<<"To view the average wind speed and average ambient air temperature of a certain month."
                 <<" Enter a month and year in the format of '03 2016': ";
        std::cin>>month>>year;

        IOHelpers::ConvertDateToString(month, year, stringDate);

        IOHelpers::totalSpeedMonth(averageWindSpeed, windCount, stringDate, B, M);
        //IOHelpers::totalTempMonth(averageTemp, tempCount, month, year, B);
        IOHelpers::ConvertMonth(stringMonth, month);
        if(windCount==0)
        {
            std::cout<<stringMonth<<" "<<year<<": No Data"<<'\n';
        }
        else
        {
            //IOHelpers::GetAverage(averageWindSpeed, windCount);
            //IOHelpers::ConvertSpeed(averageWindSpeed);
            //IOHelpers::GetAverage(averageTemp, tempCount);
            std::cout<<std::setprecision(1)<<std::fixed<<stringMonth<<" "<<year<<": "<<averageWindSpeed<< "km/h, "<<averageTemp<<" degrees C"<<'\n';
        }
    }
    /**
		 * @brief  Option 2- Asks the user for a year.
         *         Will loop around for each month and
         * using the IOHelpers will modify the local variables
         * to print Average Wind Speed and Average Temp on screen.
		 *
		 * @return Void
		 */

    void Option2(const BST<std::pair<std::string, WindLogType>> &W)
    {
        std::string stringMonth=" ";
        unsigned year=0;
        float averageWindSpeed=0;
        float averageTemp=0;
        int windCount=0;
        int tempCount=0;

        std::cout<<"To view the average wind speed and average air temp for every month of a certain year."
                 <<" Please enter the year in the format of '2016':";
        std::cin>>year;

        std::cout<<"Year: "<<year<<'\n';
        for(unsigned month=1;month<13;month++)
        {
            averageWindSpeed=0;
            averageTemp=0;
            windCount=0;
            tempCount=0;

            //IOHelpers::totalSpeedMonth(averageWindSpeed, windCount, month, year, W);
            //IOHelpers::totalTempMonth(averageTemp, tempCount, month, year, W);
            IOHelpers::ConvertMonth(stringMonth, month);
            if(windCount==0)
            {
                std::cout<<stringMonth<<" "<<year<<": No Data"<<'\n';
            }
            else
            {
                //IOHelpers::GetAverage(averageWindSpeed, windCount);
                //IOHelpers::ConvertSpeed(averageWindSpeed);
                //IOHelpers::GetAverage(averageTemp, tempCount);
                std::cout<<std::setprecision(1)<<std::fixed<<stringMonth<<": "<<averageWindSpeed<< "km/h, "<<averageTemp<<" degrees C"<<'\n';
            }
        }
    }
    /**
		 * @brief  Option 3- Asks the user for a year.
         *         Will loop around for each month and
         * using the IOHelpers will modify the local variables
         * to print Total Solar Radiation on screen.
		 *
		 * @return Void
		 */
    void Option3(const BST<std::pair<std::string, WindLogType>> &W)
    {
        std::string stringMonth=" ";
        unsigned year=0;
        float totalSolarRadiation=0;
        int solarCount=0;

        std::cout<<"To view the total solar radiation for every month of a certain year."
                 <<" Please enter the year in the format '2015':";
        std::cin>>year;
        std::cout<<"Year: "<<year<<'\n';

        for(unsigned month=1;month<13;month++)
        {
            totalSolarRadiation=0;
            solarCount=0;
            //IOHelpers::totalRadiationMonth(totalSolarRadiation, solarCount, month, year, W);
            IOHelpers::ConvertMonth(stringMonth, month);
            if(solarCount==0)
            {
                std::cout<<stringMonth<<" "<<year<<": No Data"<<'\n';
            }
            else
            {
                //IOHelpers::ConvertRadiation(totalSolarRadiation);
                std::cout<<std::setprecision(1)<<std::fixed<<stringMonth<<": "<<totalSolarRadiation<<"kWh/m^2"<<'\n';
            }
        }
    }
    /**
		 * @brief  Option 4- Asks the user for a year.
         *         Will loop around for each month and
         * using the IOHelpers will modify the local variables
         * to print Average Wind Speed, Average Temp and Total
         * Solar Radiation to an csv file.
		 *
		 * @return Void
		 */
    void Option4(const BST<std::pair<std::string, WindLogType>> &W)
    {
        std::string stringMonth;
        unsigned year=0;
        bool found=false;
        float averageWindSpeed=0;
        float averageTemp=0;
        float totalSolarRadiation=0;
        int windCount=0;
        int tempCount=0;
        int solarCount=0;

        std::ofstream outFile("WindTempSolar.csv");
        if(!outFile.is_open())
        {
            std::cout<<"Couldnt find output file";
        }

        std::cout<<"To write average air temp, average wind speed and solar radiation"
                 <<". Enter year in the format of '2015': ";
        std::cin>>year;

        //IOHelpers::CheckYearInArray(year, found, W);
        if(found)
        {
            for(unsigned month=1;month<13;month++)
            {
                averageWindSpeed=0;
                averageTemp=0;
                totalSolarRadiation=0;
                windCount=0;
                tempCount=0;
                solarCount=0;

                //IOHelpers::totalSpeedMonth(averageWindSpeed, windCount, month, year, W);
                //IOHelpers::totalTempMonth(averageTemp, tempCount, month, year, W);
                //IOHelpers::totalRadiatW.insert({stringKey,tempStruct});ionMonth(totalSolarRadiation, solarCount, month, year, W);

                IOHelpers::ConvertMonth(stringMonth, month);

                if(averageTemp==0)
                {
                }
                else
                {
                    //IOHelpers::GetAverage(averageWindSpeed, windCount);
                    //IOHelpers::ConvertSpeed(averageWindSpeed);
                    //IOHelpers::GetAverage(averageTemp, tempCount);
                    //IOHelpers::ConvertRadiation(totalSolarRadiation);

                    outFile<<std::setprecision(1)<<std::fixed<<stringMonth<<","<<averageWindSpeed<<","<<averageTemp<<","<<totalSolarRadiation<<'\n';
                }
            }
        }
        else
        {
        outFile<<year<<'\n'<<"No Data";
        }
        outFile.close();
    }
    /**
		 * @brief  Menu- The 'main' menu method.
		 *          Calls the other menu methods
		 * and asks the user for an input to use the option method
		 * until the user exits.
		 * @return Void
		 */
    void Menu(const BST<std::pair<std::string, std::string>> &B, const std::map<std::string, WindLogType> &M)
    {
        unsigned input;
        WelcomeMenu();
        DisplayChoices();
        IOHelpers::GetInput(input);
        while(input!=5)
        {
            switch(input)
            {
                case 1 : Option1(B, M);
                        break;
                //case 2 : Option2(B);
                  //      break;
                //case 3 : Option3(B);
                  //      break;
                //case 4 : Option4(B);
                  //      break;
            }
            WelcomeMenu();
            DisplayChoices();
            IOHelpers::GetInput(input);
        }
    }
}
#endif
