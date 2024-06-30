#ifndef CSTACK_H
#define CSTACK_H
/** \file CStack.h
 *  \brief CStack class header
 *  \details File contain CStack class container definition.
 *  \authors
 *  \version 0.0.1
 *  $Id: CStack.h 324 2022-11-03 09:13:56Z xprase08 $
 */

#include "CBlock.h"
#include <initializer_list>		// Due to: std::initializer_list<CBlock>
#include "check.h"

/** \brief CStack class
 *  \details Definition of CStack class. There are defined all common methods and attributes.
 */
class CStack
	{
public:
	/** \brief Conversion c'tor from CBlock array
	 *  \details Constructor from the array of \c CBlock items
	 *  \authors 
	 */
	CStack(size_t aSize, const CBlock *aItems)
		{
		}
	/** \brief Conversion c'tor from initializer list
	 *  \details Constructor from an initializer list of \c CBlock use delegation to the c'tor from array of CBlock items
	 *  \authors 
	 */
	CStack(std::initializer_list<CBlock> aInitList): CStack(aInitList.size(), std::data(aInitList))
		{
		}
	}; /* class CStack */

#endif /* CSTACK_H */
