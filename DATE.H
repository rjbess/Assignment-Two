//Date.h

//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

/**
	 * @class Date
	 * @brief Creates a Date object in the form of 3 unsigned ints.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 01/04/2019
	 *
	 */


class Date
{
    public:
        Date();

        Date(unsigned inDay, unsigned inMonth, unsigned inYear);

        /**
		 * @brief  Returns unsigned int for the day attribute.
		 *
		 * @return Day - Value of day
		 */

        unsigned GetDay()const;

        /**
		 * @brief Takes in an unsigned int and sets the Day attribute.
		 *
		 * @param Day- Value of day
		 * @return void
		 */

        void SetDay(unsigned inDay);

        /**
		 * @brief  Returns unsigned int for the month attribute.
		 *
		 * @return month - Value of month
		 */

        unsigned GetMonth()const;

        /**
		 * @brief Takes in an unsigned int and sets the Month attribute.
		 *
		 * @param Month- Value of month
		 * @return void
		 */

        void SetMonth(unsigned inMonth);

        /**
		 * @brief  Returns unsigned int for the year attribute.
		 *
		 * @return Year - Value of year
		 */

        unsigned GetYear()const;

        /**
		 * @brief Takes in an unsigned int and sets the year attribute.
		 *
		 * @param Year- Value of year
		 * @return void
		 */

        void SetYear(unsigned inYear);

    private:
        unsigned day;       /// Day attribute as unsigned int
        unsigned month;     /// Month attribute as unsigned int
        unsigned year;      /// Year attribute as unsigned int
};
#endif // DATE_H
