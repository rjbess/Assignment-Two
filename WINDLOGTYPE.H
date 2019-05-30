// WindLogType.h

#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H

//---------------------------------------------------------------------------------

#include "DATE.H"
#include "TIME.H"

//---------------------------------------------------------------------------------

    /**
	 * @Struct WindLogType
	 * @brief A struct which holds a date + time object
	 *        as well as wind speed, air temp and solar radiation values as floats
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 07/04/2019
	 *
	 */


typedef struct
{
    Date d; /// Date attribute
    Time t; /// Time attribute
    float speed; /// Speed attribute as float
    float airTemp; /// Air Temp attribute as float
    float solarRadiation; /// Solar Radiation attribute as float
}WindLogType;

#endif // WINDLOGTYPE_H
