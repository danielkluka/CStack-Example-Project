#ifndef CBLOCK_UNIT_TESTS_H
#define CBLOCK_UNIT_TESTS_H
/** \file CBlockUnitTests.h
 *  \brief Unit tests parameters and headers include for class CBlock
 *  \details Simple functionality header and parameters for unit tests of class CBlock
 *  \warning Don't modify this file (except of KCBlock_allocate initialization)
 *  \authors Petyovsky, Richter
 *  \version 2021
 *  $Id: CBlockUnitTests.h 1 2022-10-26 16:54:35Z petyovsky $
 */

#include <iostream>
#include <sstream>
#include "CppUnitTest.h"

#define CBLOCK_TEST_API
#include "../CBlock/CBlock.h"
#include "../CBlock/check.h"

constexpr bool KCBlock_allocate = false;		///< Set to \c true for CBlock variant that allocate dynamic memory for instance data

#endif /* CBLOCK_UNIT_TESTS_H */
