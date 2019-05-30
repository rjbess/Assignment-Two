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
        std::cout<<"Enter (5) to view the highest solar radiation of a certain day"<<'\n'<<'\n';
        std::cout<<"Enter (6) to exit"<<'\n'<<'\n';
    }
        /**
		 * @brief  Option One- Asks the user to enter a month and year.
         *          Using IOhelpers it will modify the local variables
         * and print out the months Average Wind Speed and Average Temp on screen.
		 *
		 * @return Void
		 */

    void Option1(BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const &M)
    {
        std::string stringDate=" ";
        unsigned month=0;
        unsigned year=0;

        std::cout<<"To view the average wind speed and average ambient air temperature of a certain month."
                 <<" Enter a month and year in the format of '03 2016': ";
        std::cin>>month>>year;

        IOHelpers::ConvertDateToString(month, year, stringDate);

        IOHelpers::displayMonthTotals(stringDate, B, M);
    }
        /**
		 * @brief  Option 2- Asks the user for a year.
         *         Will loop around for each month and
         * using the IOHelpers will modify the local variables
         * to print Average Wind Speed and Average Temp on screen.
		 *
		 * @return Void
		 */

    void Option2(BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const&M)
    {
        std::string stringMonth=" ";
        unsigned year=0;

        std::cout<<"To view the average wind speed and average air temp for every month of a certain year."
                 <<" Please enter the year in the format of '2016':";
        std::cin>>year;

        std::cout<<"Year: "<<year<<'\n';

        stringMonth= std::to_string(year);
        IOHelpers::DisplayYearTotals(stringMonth, B, M);
    }
        /**
		 * @brief  Option 3- Asks the user for a year.
         *         Will loop around for each month and
         * using the IOHelpers will modify the local variables
         * to print Total Solar Radiation on screen.
		 *
		 * @return Void
		 */
    void Option3(BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const&M)
    {
        std::string stringMonth=" ";
        unsigned year=0;


        std::cout<<"To view the total solar radiation for every month of a certain year."
                 <<" Please enter the year in the format '2015':";
        std::cin>>year;

        stringMonth= std::to_string(year);

        std::cout<<"Year: "<<year<<'\n';

        IOHelpers::DisplayYearTotalsRad(stringMonth, B, M);

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
    void Option4(BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const&M)
    {
        unsigned year=0;

        std::cout<<"To write average air temp, average wind speed and solar radiation"
                 <<". Enter year in the format of '2015': ";
        std::cin>>year;

        std::ofstream outFile("WindTempSolar.csv");
        if(!outFile.is_open())
        {
            return;
        }

        IOHelpers::writeAllValues(year, B, M, outFile);

        outFile.close();
    }
    /*void Option5(std::map<std::string, WindLogType>const &M)
    {
        std::string date="";
        std::string tempString="";

        std::cout<<"To view the highest solar radiation of a day"
                 <<". Enter the date in the format of '01/02/2019': ";
        std::cin>>date;

        date.erase(date.begin()+2);
        date.erase(date.begin()+4);

        date=date.substr(4,7)+date.substr(2,3)+date.substr(0,1);

        std::cout<<date;
    }*/
        /**
		 * @brief  Menu- The 'main' menu method.
		 *          Calls the other menu methods
		 * and asks the user for an input to use the option method
		 * until the user exits.
		 * @return Void
		 */
    void Menu(BST<monthTotalStruct> &B, std::map<std::string, WindLogType>const &M)
    {
        unsigned input;
        WelcomeMenu();
        DisplayChoices();
        IOHelpers::GetInput(input);
        while(input!=6)
        {
            switch(input)
            {
                case 1 : Option1(B, M);
                        break;
                case 2 : Option2(B, M);
                        break;
                case 3 : Option3(B, M);
                        break;
                case 4 : Option4(B,M);
                        break;
                //case 5 : Option5(M);
                        //break;
            }
            WelcomeMenu();
            DisplayChoices();
            IOHelpers::GetInput(input);
        }
    }
}
#endif
