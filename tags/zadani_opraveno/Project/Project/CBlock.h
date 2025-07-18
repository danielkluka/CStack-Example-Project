#ifndef CBLOCK_H
#define CBLOCK_H
/** \file CBlock.h
 *  \brief General header for CBlock
 *  \details Header file for switching CBlock variant.
 *  \authors Petyovsky, Richter
 *  $Id: CBlock.h 3 2022-10-26 17:03:14Z petyovsky $
 */

// Always include all available (4 variants) header files here (never include just one file)!!!
#include "CBlock_bool.h"
//#include "CBlock_char.h"
//#include "CBlock_int.h"
//#include "CBlock_float.h"
#include "CBlock_TWeekDay.h"

/** \brief CBlock variant selector
 *  \note Only one variant of `using` can be selected at once. Project must work for all 4 variants of `CBlock`.
 */
using CBlock =
		CBlock_bool::CBlock;
//		CBlock_char::CBlock;
//		CBlock_int::CBlock;
//		CBlock_float::CBlock;
//		CBlock_TWeekDay::CBlock;

constexpr bool KTWeekDaySupplementTests = false;	///< Enable TWeekDay Additional (Suplemental) Tests

#endif /* CBLOCK_H */
