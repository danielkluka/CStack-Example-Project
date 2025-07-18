#ifndef CBLOCK_BOOL_H
#define CBLOCK_BOOL_H
/** \file CBlock_bool.h
 *  \brief CBlock_bool class header
 *  \details File contain CBlock_bool::CBlock definition.
 *  \warning Don't modify this file
 *  \authors Petyovsky, Richter
 *  \version 2022
 *  $Id: CBlock_bool.h 1 2022-10-26 16:54:35Z petyovsky $
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <utility>		// Due to: std::declval<CBlockBase>

#include "ClassInfo.h"
#include "CBlockBase.h"
#include "check.h"

/** \brief Namespace for encapsulating of \c bool variant of CBlock class
 *  \details For selecting this variant of CBlock class uncomment \c using \c namespace section in the CBlock.h
 */
namespace CBlock_bool
	{
	/** \brief CBlock class (\c bool variant)
	 *  \details Definition of CBlock class (\c bool variant). There are defined all common methods and attributes.
	 */
	class CBlock: public CBlockBase
		{
		ClassInfo<CBlock> iInstanceInfo;	///< Instance of the class info for usage statistics
		bool iValue; ///< Encapsulated \c bool value

	public:
		// c'tors:
		/** \brief Default c'tor
		 *  \details Value attribute is set to \c false.
		 *  \authors Petyovsky, Richter
		 */
		CBlock(): CBlockBase(), iValue(false)
			{
			}

		/** \brief Conversion c'tor
		 *  \details Value is set. Pointer attributes are initialised by given values or by default to the \c this value (CBlockBase definition).
		 *  \param[in]	aValue	New encapsulated \c bool Value
		 *  \param[in]	aPrev	Connection with previous node (when needed)
		 *  \param[in]	aNext	Connection with next node (when needed)
		 *  \param[in]	aExtraInt	Special value used for some container types
		 *  \authors Petyovsky, Richter
		 */
		explicit CBlock(const bool aValue, CBlock* aPrev = nullptr, CBlock *aNext = nullptr, int aExtraInt = 0): CBlockBase(aPrev, aNext, aExtraInt), iValue(aValue)
			{
			}

		/** \brief Copy c'tor
		 *  \details Create new instance by copying only \p iValue parameter. Pointer attributes are initialised to the \c this value (CBlockBase definition).
		 *  \param[in]	aValue	Original instance for copying
		 *  \authors Petyovsky, Richter
		 */
		CBlock(const CBlock& aValue): CBlockBase(), iValue(aValue.Value())
			{
			}

		/** \brief Conversion c'tor from plain C string (striped string)
		 *  \details Create new instance from Value in the string. Pointer attributes are initialised by given values or by default to the \c this value (CBlockBase definition).
		 *  \param[in]	aStr	Plain C string with value "0" or "1"
		 *  \param[in]	aPrev	Connection with previous node (when needed)
		 *  \param[in]	aNext	Connection with next node (when needed)
		 *  \param[in]	aExtraInt	Special value used for some container types
		 *  \authors Petyovsky, Richter
		 */
		explicit CBlock(const char* aStr, CBlock* aPrev = nullptr, CBlock *aNext = nullptr, int aExtraInt = 0): CBlockBase(aPrev, aNext, aExtraInt), iValue(false)
			{
			std::istringstream iss(aStr, std::istringstream::in); iss >> std::boolalpha >> iValue;
			}

		/** \brief Conversion c'tor from std::string 
		 *  \details Create new instance from Value in the string. Pointer attributes are initialised by given values or by default to the \c this value (CBlockBase definition).
		 *  \param[in]	aString	std::string with value "0" or "1"
		 *  \param[in]	aPrev	Connection with previous node (when needed)
		 *  \param[in]	aNext	Connection with next node (when needed)
		 *  \param[in]	aExtraInt	Special value used for some container types
		 *  \authors Petyovsky, Richter
		 */
		explicit CBlock(const std::string& aString, CBlock* aPrev = nullptr, CBlock* aNext = nullptr, int aExtraInt = 0): CBlock(aString.c_str(), aPrev, aNext, aExtraInt)
			{
			}

		// d'tor
		/** \brief Virtual d'tor
		 *  \authors Petyovsky, Richter
		 */
		virtual ~CBlock() noexcept( noexcept(std::declval<CBlockBase>().~CBlockBase()) )
			{
			iValue = false;
			}

		// InstanceInfo getter:
		/** \brief ID getter
		 *  \return Unique instance ID
		 *  \author Petyovsky
		 */
		size_t ID() const
			{
			return iInstanceInfo.ID();
			}

		// setters/getters:
		/** \brief Value setter
		 *  \param[in]	aValue	New Value
		 *  \author Petyovsky
		 */
		void SetValue(const bool aValue)
			{
			iValue = aValue;
			}

		/** \brief Value getter
		 *  \return Actual \c bool \p Value
		 *  \author Petyovsky
		 */
		bool Value() const
			{
			return iValue;
			}

		// operators:
		/** \brief Complement operator
		 *  \return CBlock instance with complemented attribute Value.
		 *  \author Petyovsky
		 */
		CBlock operator-() const
			{
			return CBlock(!iValue);
			}

		/** \brief Assigment operator
		 *  \return CBlock instance with copied attribute Value.
		 *  \author Petyovsky
		 */
		CBlock& operator=(const CBlock& aValue)
			{
			SetValue(aValue.Value()); 
			return *this;
			}

		/** \brief Comparing by Value operator
		 *  \return Return \c bool result of comparation
		 *  \author Petyovsky
		 */
		bool operator==(const CBlock& aValue) const
			{
			return iValue == aValue.Value();
			}

#ifdef CBLOCK_THREE_WAY_COMPARISON
		/** \brief Threeway comparison by Value operator
		 *  \return Return \c std::strong_ordering result of comparation
		 *  \author Petyovsky
		 */
		std::strong_ordering operator<=>(const CBlock& aValue) const
			{
			return iValue <=> aValue.Value();
			}

#else
		/** \brief Comparing by Value operator
		 *  \return Return \c bool result of comparation
		 *  \author Petyovsky
		 */
		bool operator!=(const CBlock& aValue) const
			{
			return iValue != aValue.Value();
			}

		/** \brief Comparing by Value operator
		 *  \return Return \c bool result of comparation
		 *  \author Petyovsky
		 */
		bool operator<(const CBlock& aValue) const
			{
			return iValue < aValue.Value();
			}

		/** \brief Comparing by Value operator
		 *  \return Return \c bool result of comparation
		 *  \author Petyovsky
		 */
		bool operator>(const CBlock& aValue) const
			{
			return iValue > aValue.Value();
			}
#endif /* CBLOCK_THREE_WAY_COMPARISON */

		/** \brief Output to the stream operator. (\em serialization)
		 *  \param[in]	aOStream	Output stream
		 *  \param[in]	aValue	Serialized instantion of CBlock
		 *  \return Return \c std::ostream with serialized Value
		 *  \author Petyovsky
		 */
		friend std::ostream& operator<<(std::ostream& aOStream, const CBlock& aValue)
			{
			std::ios_base::fmtflags fmtflags = aOStream.setf(std::ios_base::boolalpha); // Save the state of the boolalpha flag & set it
			aOStream << aValue.Value();
			aOStream.flags(fmtflags); 	// restore previous flags
			return aOStream;
			}

		/** \brief Input from the stream operator. (\em deserialization)
		 *  \param[in]	aIStream	Input stream
		 *  \param[out]	aValue	Place for deserialized instantion of CBlock
		 *  \return Return rest of \c std::istream
		 *  \author Petyovsky
		 */
		friend std::istream& operator>>(std::istream& aIStream, CBlock& aValue)
			{
			std::ios_base::fmtflags fmtflags = aIStream.setf(std::ios_base::boolalpha); // Save the state of the boolalpha flag & set it
			aIStream >> aValue.iValue;
			aIStream.flags(fmtflags); 	// restore previous flags
			return aIStream;
			}

#ifdef CBLOCK_TEST_API

		// constants for testing CBlock functionalities:
		/** \brief First test value
		 *  \return Return \c bool value (\c false)
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static bool TestValue0()
			{
			return false;
			}

		/** \brief First test string value
		 *  \return Return string with \c bool value (\c false)
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static std::string TestStringValue0()
			{
			return std::string("false");
			}

		/** \brief Second test value
		 *  \return Return \c bool value (\c true)
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static bool TestValue1()
			{
			return true;
			}

		/** \brief Second test string value
		 *  \return Return string with \c bool value (\c true)
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static std::string TestStringValue1()
			{
			return std::string("true");
			}

		/** \brief Random test value
		 *  \return Return random \c bool value
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static bool TestValueRandom()
			{
			return bool(std::rand() % 2) ? TestValue1() : TestValue0();
			}

		/** \brief Random test string value
		 *  \return Return string with random \c bool value
		 *  \authors Petyovsky, Richter
		 *  \note Useful for automated testing of CBlock functionality
		 */
		static std::string TestStringValueRandom()
			{
			return bool(std::rand() % 2) ? TestStringValue1() : TestStringValue0();
			}
#endif /* CBLOCK_TEST_API */

		}; /* class CBlock */
	} /* namespace CBlock_bool */
#endif /* CBLOCK_BOOL_H */
