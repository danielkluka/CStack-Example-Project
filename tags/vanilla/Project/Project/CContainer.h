#ifndef CCONTAINER_H
#define CCONTAINER_H
/** \file CContainer.h
 *  \brief CContainer class header
 *  \details File contain CContainer class container definition.
 *  \authors
 *  \version 0.0.1
 *  $Id: CContainer.h 3 2022-10-26 17:03:14Z petyovsky $
 */

#include "CBlock.h"
#include <initializer_list>		// Due to: std::initializer_list<CBlock>
#include "check.h"

/** \brief CContainer class
 *  \details Definition of CContainer class. There are defined all common methods and attributes.
 */
class CContainer
	{
public:
	/** \brief Conversion c'tor from CBlock array
	 *  \details Constructor from the array of \c CBlock items
	 *  \authors 
	 */
	CContainer(size_t aSize, const CBlock *aItems)
		{
		}
	/** \brief Conversion c'tor from initializer list
	 *  \details Constructor from an initializer list of \c CBlock use delegation to the c'tor from array of CBlock items
	 *  \authors 
	 */
	CContainer(std::initializer_list<CBlock> aInitList): CContainer(aInitList.size(), std::data(aInitList))
		{
		}
	}; /* class CContainer */

#endif /* CCONTAINER_H */
