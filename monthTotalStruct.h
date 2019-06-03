// monthTotalSTruct.h

#ifndef MONTHTOTALSTRUCT_H
#define MONTHTOTALSTRUCT_H

//---------------------------------------------------------------------------------

#include <string>

//---------------------------------------------------------------------------------

    /**
	 * @Struct MonthTotalStruct
	 * @brief A struct which holds a key value representing the year, month
	 *        as well as wind speed, air temp and solar radiation month totals
	 * In this program the values are converted before entereing the struct
	 * @author Robert Bessell
	 * @version 01
	 * @date 03/06/2019
	 *
	 */

typedef struct
{
    std::string key; ///String key representing year+month
    float totalSpeed; ///Total Speed of the month
    float totalAirTemp; /// Total air temp of the month
    float totalSolarRadiation; ///Total Solar radiation of the month

}monthTotalStruct;

#endif // MONTHTOTALSTRUCT_H
