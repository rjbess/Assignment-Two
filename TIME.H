//Time.h

//---------------------------------------------------------------------------------

#ifndef TIME_H
#define TIME_H

//---------------------------------------------------------------------------------

    /**
	 * @class Time
	 * @brief Creates a Time object in the form of 2 unsigned ints.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 08/04/2019
	 *
	 */

class Time
{
    public:
        Time();
        Time(unsigned inHours, unsigned inMinutes);
        /**
		 * @brief  Returns unsigned int for the hours attribute.
		 *
		 * @return Hour - Value of hours
		 */
        unsigned GetHours()const;
        /**
		 * @brief Takes in an unsigned int and sets the Hour attribute.
		 *
		 * @param Hour- Value of Hour
		 * @return void
		 */
        void SetHours(unsigned inHours);
       /**
		 * @brief  Returns unsigned int for the minutes attribute.
		 *
		 * @return Minutes - Value of minutes
		 */
        unsigned GetMinutes()const;
        /**
		 * @brief Takes in an unsigned int and sets the minutes attribute.
		 *
		 * @param Minutes- Value of minutes
		 * @return void
		 */
        void SetMinutes(unsigned inMinutes);
    private:
        unsigned hours;     ///Hour attribute as unsigned int
        unsigned minutes;   ///Minutes attribute as unsigned int
};
#endif // TIME_H
