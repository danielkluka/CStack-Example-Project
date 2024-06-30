#ifndef CBLOCK_H
#define CBLOCK_H
/** \file CBlock.h
 *  \brief General header for CBlock
 *  \details Header file for switching CBlock variant.
 *  \authors Petyovsky, Richter
 *  $Id: CBlock.h 2922 2022-12-19 13:21:50Z xpesek13 $
 */

// Always include all available (4 variants) header files here (never include just one file)!!!
#include "CBlock_bool.h"
#include "CBlock_long.h"
#include "CBlock_TWeekDay.h"
#include "CBlock_TInterval.h"

/** \brief CBlock variant selector
 *  \note Only one variant of `using` can be selected at once. Project must work for all 4 variants of `CBlock`.
 */
using CBlock =
//		CBlock_bool::CBlock;
//		CBlock_long::CBlock;
//		CBlock_TWeekDay::CBlock;
		CBlock_TInterval::CBlock;


constexpr bool KTWeekDaySupplementTests = false;	///< Enable TWeekDay Additional (Suplemental) Tests

#endif /* CBLOCK_H */
