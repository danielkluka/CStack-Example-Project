/** \file CBlock_TWeekDay.cpp
 *  \brief CBlock_TWeekDay class source
 *  \details File contains implementation of CBlock_TWeekDay support functions and global operators also for \c enum TWeekDay
 *  \warning Don't modify this file
 *  \authors Petyovsky, Richter
 *  \version 2022
 *  $Id: CBlock_TWeekDay.cpp 3 2022-10-26 17:03:14Z petyovsky $
 */

#include <cstring>
#include "CBlock_TWeekDay.h"

namespace CBlock_TWeekDay
	{
	// Definition of the TWeekDay support constants
	static const char* const KTWeekDaysName[KTWeekDaysCount] =
		{ 
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" ///< Day name definition
		};

	TWeekDay CheckRangeWithException(const size_t aDayNum)
		{
		if(aDayNum > static_cast<size_t>(TWeekDay::ESunday))
			{
			std::ostringstream oss; oss << "Value: " << aDayNum << " is out of range for type enum class TWeekDay!";
			throw std::range_error(oss.str());
			}
		return TWeekDay(aDayNum);
		} /* CheckingRangeWithException() */

	const char* TWeekStringName(TWeekDay aWeekDay)
		{
		return KTWeekDaysName[static_cast<size_t>(aWeekDay)];
		} /* TWeekStringName() */

	std::ostream& operator<<(std::ostream& aOStream, const TWeekDay& aWeekDay)
		{
		aOStream << KTWeekDaysName[static_cast<size_t>(aWeekDay)];
		return aOStream;
		} /* operator<<() */

	std::istream& operator>>(std::istream& aIStream, TWeekDay& aWeekDay)
		{
		size_t daynum = 0;

		for(size_t i = 0; KTWeekDaysName[daynum][i] != '\0'; ++i)
			{
			char ch = '\0';
			aIStream >> ch;
			if(!aIStream.good())
				throw std::runtime_error("Input stream data integrity error!");

			while(KTWeekDaysName[daynum][i] != ch)
				{				
				for(const size_t orig_daynum = daynum++; (daynum < KTWeekDaysCount); ++daynum)
					if(std::strncmp(KTWeekDaysName[orig_daynum], KTWeekDaysName[daynum], i) == 0)
						break;

				if(daynum >= KTWeekDaysCount)
					throw std::runtime_error("Input stream data integrity error!");
				}
			}

		aWeekDay = CheckRangeWithException(daynum);
		return aIStream;
		} /* operator>>() */

	} /* namespace CBlock_TWeekDay */
