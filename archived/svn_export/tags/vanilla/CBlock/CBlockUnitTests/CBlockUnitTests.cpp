/** \file CBlockUnitTests.cpp
 *  \brief Functionality unit tests for class CBlock
 *  \details Simple functionality unit tests for class CBlock.
 *  \warning Don't modify this file
 *  \authors Petyovsky, Richter
 *  \version 2021
 *  $Id: CBlockUnitTests.cpp 1 2022-10-26 16:54:35Z petyovsky $
 */

#include "CBlockUnitTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CBlockUnitTests
	{
	TEST_CLASS(CBlockFunctionalTests)
		{
	public:

		/**
		 \test **Test of validity of `CBlock::TestValues` and `CBlock::TestStringValues`**. **Author:** `Petyovsky`.
		 - Test `CBlock::TestValue0` and `CBlock::TestValue1` is not same
		 - Test `CBlock::TestStringValue0` and `CBlock::TestStringValue1` is not same
		 - Call TestValue API: `CBlock::TestValueRandom` and `CBlock::TestStringValueRandom`
		 */
		TEST_METHOD(CBlock_TestValues)
			{
			Assert::IsFalse(CBlock::TestValue0() == CBlock::TestValue1(), L"Test values cannot be same", LINE_INFO());
			std::string stringval0(CBlock::TestStringValue0());
			std::string stringval1(CBlock::TestStringValue1());
			Assert::IsFalse(stringval0 == stringval1, L"Test string values cannot be same", LINE_INFO());
			CBlock::TestValueRandom();	// just call randomized Test value factory
			CBlock::TestStringValueRandom();	// just call randomized Test string value factory
			}

		/**
		 \test **Test of CBlock default c'tor**. **Author:** `Petyovsky`.
		 - Instance inicialized to the default value `CBlock::TestValue0`
		 - Counter `ClassInfo::Living` was incremented
		 - C'tor don't allocate, reallocate od deallocate any dynamic memory
		 - New CBlock instance have unique `ClassInfo::ID`
		 */
		TEST_METHOD(CBlock_ctor_default)
			{
			size_t alloc_count_before = get_alloc_count();
			size_t dealloc_count_before = get_dealloc_count();
			size_t realloc_count_before = get_realloc_count();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			CBlock val0;
			ptrdiff_t living_after = ClassInfo<CBlock>::Living();
			size_t alloc_count_after = get_alloc_count();
			size_t dealloc_count_after = get_dealloc_count();
			size_t realloc_count_after = get_realloc_count();
			Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Wrong init value", LINE_INFO());
			Assert::IsTrue(living_before + 1 == living_after, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(alloc_count_before, alloc_count_after, L"Default c'tor allocate", LINE_INFO());
			Assert::AreEqual(dealloc_count_before, dealloc_count_after, L"Default c'tor deallocate", LINE_INFO());
			Assert::AreEqual(realloc_count_before, realloc_count_after, L"Default c'tor reallocate", LINE_INFO());
			CBlock val1;
			Assert::IsTrue(val1.ID() > val0.ID(), L"Wrong ClassInfo ID initialization", LINE_INFO());
			}

		/**
		 \test **Test of CBlock conversion c'tor**. **Author:** `Petyovsky`.
		 - Instance can be correctly inicialized with `CBlock::TestValue0` and `CBlock::TestValue0`
		 - Counter `ClassInfo::Living` was incremented
		 - Each new CBlock instance have unique `ClassInfo::ID`
		 - C'tor allocate, reallocate od deallocate dynamic memory if it was defined by `KCBlock_allocate` predicate
		 - Destruction of constructed instance deallocate memory if it was defined by `KCBlock_allocate` predicate
		 - Destruction of constructed instance decrement counter `ClassInfo::Living`
		 */
		TEST_METHOD(CBlock_ctor_conv)
			{
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
				{
				const CBlock val0(CBlock::TestValue0());
				const CBlock val1(CBlock::TestValue1());

				living_after = ClassInfo<CBlock>::Living();
				allocsize_after = get_alloc_actual_size();
				Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Wrong value", LINE_INFO());
				Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Wrong value", LINE_INFO());
				Assert::IsFalse(val0.Value() == val1.Value(), L"Wrong value", LINE_INFO());
				Assert::IsTrue(living_before + 2 == living_after, L"Wrong number of instances", LINE_INFO());
				Assert::IsTrue(val1.ID() > val0.ID(), L"Wrong ClassInfo ID initialization", LINE_INFO());
				if constexpr(KCBlock_allocate)
					Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
				else
					Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());
				}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		/**
		 \test **Test of CBlock copy c'tor**. **Author:** `Petyovsky`.
		 - Instance can be correctly inicialized with `CBlock::TestValue0` and `CBlock::TestValue0`
		 - Test `CBlock::TestValue0` and `CBlock::TestValue1` is not same
		 - Counter `ClassInfo::Living` was incremented after copy c'tor call
		 - Each new CBlock instance have unique `ClassInfo::ID`
		 - C'tor allocate, reallocate od deallocate dynamic memory if it was defined by `KCBlock_allocate` predicate
		 - Destruction of constructed instance deallocate memory if it was defined by `KCBlock_allocate` predicate
		 - Destruction of constructed instance decrement counter `ClassInfo::Living`
		 */
		TEST_METHOD(CBlock_ctor_copy)
			{
			const CBlock val0(CBlock::TestValue0());
			const CBlock val1(CBlock::TestValue1());
			Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Value isn't same", LINE_INFO());

			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
				{
				CBlock val0_t(val0);
				CBlock val1_t(val1);

				living_after = ClassInfo<CBlock>::Living();
				allocsize_after = get_alloc_actual_size();
				Assert::IsTrue(living_before + 2 == living_after, L"Wrong number of instances", LINE_INFO());

				if constexpr(KCBlock_allocate)
					Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
				else
					Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());

				Assert::AreNotEqual(val0_t.ID(), val0.ID(), L"IDs cannot be same", LINE_INFO());
				Assert::AreNotEqual(val1_t.ID(), val1.ID(), L"IDs cannot be same", LINE_INFO());

				Assert::IsTrue(val0_t.Value() == val0.Value(), L"Wrong value", LINE_INFO());
				Assert::IsTrue(val1_t.Value() == val1.Value(), L"Wrong value", LINE_INFO());
				Assert::IsFalse(val0_t.Value() == val1_t.Value(), L"Wrong value", LINE_INFO());
				}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		TEST_METHOD(CBlock_ctor_conv_cstring)
			{
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
				{
				const CBlock val0(CBlock::TestStringValue0().c_str());
				const CBlock val1(CBlock::TestStringValue1().c_str());

				living_after = ClassInfo<CBlock>::Living();
				allocsize_after = get_alloc_actual_size();
				Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Value isn't same", LINE_INFO());
				Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Value isn't same", LINE_INFO());
				Assert::IsFalse(val0.Value() == val1.Value(), L"Wrong value", LINE_INFO());
				Assert::IsTrue(living_before + 2 == living_after, L"Wrong number of instances", LINE_INFO());
				Assert::IsTrue(val1.ID() > val0.ID(), L"Wrong ClassInfo ID initialization", LINE_INFO());

				if constexpr(KCBlock_allocate)
					Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
				else
					Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());
			}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		TEST_METHOD(CBlock_ctor_conv_std_string)
			{
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
			{
			const CBlock val0(CBlock::TestStringValue0());
			const CBlock val1(CBlock::TestStringValue1());

			living_after = ClassInfo<CBlock>::Living();
			allocsize_after = get_alloc_actual_size();
			Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsFalse(val0.Value() == val1.Value(), L"Wrong value", LINE_INFO());
			Assert::IsTrue(living_before + 2 == living_after, L"Wrong number of instances", LINE_INFO());
			Assert::IsTrue(val1.ID() > val0.ID(), L"Wrong ClassInfo ID initialization", LINE_INFO());

			if constexpr(KCBlock_allocate)
				Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
			else
				Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());
			}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		TEST_METHOD(CBlock_dtor)
			{
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			CBlock val(CBlock::TestValue0());
			val.~CBlock();
			ptrdiff_t living_after = ClassInfo<CBlock>::Living();
			size_t allocsize_after = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after, L"Memory leaking", LINE_INFO());
			}

		TEST_METHOD(CBlock_ctor_conv_cstring_format_compatibility)
			{
			const CBlock val0(CBlock::TestStringValue0());
			const CBlock val1(CBlock::TestStringValue1());
			Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Value isn't same", LINE_INFO());

			std::stringstream ss0;
			ss0 << val0;
			std::stringstream ss1;
			ss1 << val1;

			size_t allocsize_before = get_alloc_actual_size();
			const CBlock val1_t(ss1.str().c_str());
			size_t allocsize_after1 = get_alloc_actual_size();
			const CBlock val0_t(ss0.str().c_str());
			size_t allocsize_after2 = get_alloc_actual_size();

			Assert::AreNotEqual(val0_t.ID(), val0.ID(), L"IDs cannot be same", LINE_INFO());
			Assert::AreNotEqual(val1_t.ID(), val1.ID(), L"IDs cannot be same", LINE_INFO());
			Assert::IsTrue(val0_t.Value() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(val1_t.Value() == val1.Value(), L"Value isn't same", LINE_INFO());
			if constexpr(KCBlock_allocate)
				{
				Assert::IsTrue(allocsize_before < allocsize_after1, L"No memory allocation", LINE_INFO());
				Assert::IsTrue(allocsize_after1 < allocsize_after2, L"No memory allocation", LINE_INFO());
				}
			else
				{
				Assert::IsTrue(allocsize_before == allocsize_after1, L"Memory allocated", LINE_INFO());
				Assert::IsTrue(allocsize_after1 == allocsize_after2, L"Memory allocated", LINE_INFO());
				}
			}

		TEST_METHOD(CBlock_operators_stream_format_compatibility)
			{
			const CBlock val0(CBlock::TestStringValue0());
			const CBlock val1(CBlock::TestStringValue1());
			Assert::IsTrue(CBlock::TestValue0() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(CBlock::TestValue1() == val1.Value(), L"Value isn't same", LINE_INFO());

			std::stringstream ss;
			ss << val0;
			ss << val1;
			CBlock val0_t, val1_t;
			size_t allocsize_before = get_alloc_actual_size();
			ss >> val0_t;
			size_t allocsize_after1 = get_alloc_actual_size();
			ss >> val1_t;
			size_t allocsize_after2 = get_alloc_actual_size();

			Assert::AreNotEqual(val0_t.ID(), val0.ID(), L"IDs cannot be same", LINE_INFO());
			Assert::AreNotEqual(val1_t.ID(), val1.ID(), L"IDs cannot be same", LINE_INFO());
			Assert::IsTrue(val0_t.Value() == val0.Value(), L"Value isn't same", LINE_INFO());
			Assert::IsTrue(val1_t.Value() == val1.Value(), L"Value isn't same", LINE_INFO());

			if constexpr(KCBlock_allocate)
				{
				Assert::IsTrue(allocsize_before < allocsize_after1, L"No memory allocation", LINE_INFO());
				Assert::IsTrue(allocsize_after1 < allocsize_after2, L"No memory allocation", LINE_INFO());
				}
			else
				{
				Assert::IsTrue(allocsize_before == allocsize_after1, L"Memory allocated", LINE_INFO());
				Assert::IsTrue(allocsize_after1 == allocsize_after2, L"Memory allocated", LINE_INFO());
				}
			}

		TEST_METHOD(CBlock_setter)
			{
			CBlock val;
			size_t allocsize_before = get_alloc_actual_size();
			val.SetValue(CBlock::TestValue1());
			size_t allocsize_after1 = get_alloc_actual_size();
			Assert::IsTrue(val.Value() == CBlock::TestValue1(), L"Value isn't same", LINE_INFO());

			if constexpr(KCBlock_allocate)
				Assert::IsTrue(allocsize_before < allocsize_after1, L"No memory allocation", LINE_INFO());
			else
				Assert::IsTrue(allocsize_before == allocsize_after1, L"Memory allocated", LINE_INFO());

			val.SetValue(CBlock::TestValue0());
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(val.Value() == CBlock::TestValue0(), L"Value isn't same", LINE_INFO());

			if constexpr(KCBlock_allocate)
				Assert::IsTrue(allocsize_before < allocsize_after2, L"No memory allocation", LINE_INFO());
			else
				Assert::IsTrue(allocsize_before == allocsize_after2, L"Memory allocated", LINE_INFO());
			}

		TEST_METHOD(CBlock_operator_unary_minus)
			{
			const CBlock val0(CBlock::TestValue1());
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			CBlock val1(-val0);
			CBlock val2(-val1);
			size_t allocsize_after1 = get_alloc_actual_size();
			ptrdiff_t living_after = ClassInfo<CBlock>::Living();

			if constexpr(KCBlock_allocate)
				Assert::IsTrue(allocsize_before < allocsize_after1, L"No memory allocation", LINE_INFO());
			else
				Assert::IsTrue(allocsize_before == allocsize_after1, L"Memory allocated", LINE_INFO());

			Assert::IsTrue(living_before + 2 == living_after, L"Wrong number of instances", LINE_INFO());
			Assert::IsTrue(val0.Value() != val1.Value(), L"Value is same", LINE_INFO());
			Assert::IsTrue(val1.Value() != val2.Value(), L"Value is same", LINE_INFO());
			Assert::IsTrue(val0.Value() == val2.Value(), L"Value isn't same", LINE_INFO());
			}

		TEST_METHOD(CBlock_operator_equal)
			{
			const CBlock val1_0(CBlock::TestValue0()), val2_0(CBlock::TestValue0());
			const CBlock val3_1(CBlock::TestValue1()), val4_1(CBlock::TestValue1());

			Assert::IsTrue(val1_0.ID() < val2_0.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val2_0.ID() < val3_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val3_1.ID() < val4_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());

			Assert::IsTrue(val1_0 == val1_0, L"Must be true", LINE_INFO());
			Assert::IsTrue(val3_1 == val4_1, L"Must be true", LINE_INFO());

			Assert::IsTrue(val1_0 == val2_0, L"Must be true", LINE_INFO());
			Assert::IsTrue(val2_0 == val1_0, L"Must be true", LINE_INFO());

			Assert::IsTrue(val3_1 == val4_1, L"Must be true", LINE_INFO());
			Assert::IsTrue(val3_1 == val4_1, L"Must be true", LINE_INFO());

			Assert::IsFalse(val1_0 == val3_1, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 == val1_0, L"Must be false", LINE_INFO());

			Assert::IsFalse(val2_0 == val4_1, L"Must be false", LINE_INFO());
			Assert::IsFalse(val4_1 == val2_0, L"Must be false", LINE_INFO());
			}

		TEST_METHOD(CBlock_operator_not_equal)
			{
			const CBlock val1_0(CBlock::TestValue0()), val2_0(CBlock::TestValue0());
			const CBlock val3_1(CBlock::TestValue1()), val4_1(CBlock::TestValue1());

			Assert::IsTrue(val1_0.ID() < val2_0.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val2_0.ID() < val3_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val3_1.ID() < val4_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());

			Assert::IsFalse(val1_0 != val1_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 != val4_1, L"Must be false", LINE_INFO());

			Assert::IsFalse(val1_0 != val2_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val2_0 != val1_0, L"Must be false", LINE_INFO());

			Assert::IsFalse(val3_1 != val4_1, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 != val4_1, L"Must be false", LINE_INFO());

			Assert::IsTrue(val1_0 != val3_1, L"Must be true", LINE_INFO());
			Assert::IsTrue(val3_1 != val1_0, L"Must be true", LINE_INFO());

			Assert::IsTrue(val2_0 != val4_1, L"Must be true", LINE_INFO());
			Assert::IsTrue(val4_1 != val2_0, L"Must be true", LINE_INFO());
			}

		TEST_METHOD(CBlock_operator_greater_than)
			{
			const CBlock val1_0(CBlock::TestValue0()), val2_0(CBlock::TestValue0());
			const CBlock val3_1(CBlock::TestValue1()), val4_1(CBlock::TestValue1());

			Assert::IsTrue(val1_0.ID() < val2_0.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val2_0.ID() < val3_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val3_1.ID() < val4_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());

			Assert::IsFalse(val1_0 < val1_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 < val4_1, L"Must be false", LINE_INFO());

			Assert::IsFalse(val1_0 < val2_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val2_0 < val1_0, L"Must be false", LINE_INFO());

			Assert::IsFalse(val3_1 < val4_1, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 < val4_1, L"Must be false", LINE_INFO());

			Assert::IsTrue(val1_0 < val3_1, L"Must be true", LINE_INFO());
			Assert::IsFalse(val3_1 < val1_0, L"Must be false", LINE_INFO());

			Assert::IsTrue(val2_0 < val4_1, L"Must be true", LINE_INFO());
			Assert::IsFalse(val4_1 < val2_0, L"Must be false", LINE_INFO());
			}

		TEST_METHOD(CBlock_operator_less_than)
			{
			const CBlock val1_0(CBlock::TestValue0()), val2_0(CBlock::TestValue0());
			const CBlock val3_1(CBlock::TestValue1()), val4_1(CBlock::TestValue1());

			Assert::IsTrue(val1_0.ID() < val2_0.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val2_0.ID() < val3_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());
			Assert::IsTrue(val3_1.ID() < val4_1.ID(), L"Wrong ClassInfo ID", LINE_INFO());

			Assert::IsFalse(val1_0 > val1_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 > val4_1, L"Must be false", LINE_INFO());

			Assert::IsFalse(val1_0 > val2_0, L"Must be false", LINE_INFO());
			Assert::IsFalse(val2_0 > val1_0, L"Must be false", LINE_INFO());

			Assert::IsFalse(val3_1 > val4_1, L"Must be false", LINE_INFO());
			Assert::IsFalse(val3_1 > val4_1, L"Must be false", LINE_INFO());

			Assert::IsFalse(val1_0 > val3_1, L"Must be false", LINE_INFO());
			Assert::IsTrue(val3_1 > val1_0, L"Must be true", LINE_INFO());

			Assert::IsFalse(val2_0 > val4_1, L"Must be false", LINE_INFO());
			Assert::IsTrue(val4_1 > val2_0, L"Must be true", LINE_INFO());
			}

		TEST_METHOD(CBlock_assignment_to_empty)
			{
			const CBlock cval(CBlock::TestValue1());
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
				{
				CBlock val;
				val = cval;

				living_after = ClassInfo<CBlock>::Living();
				allocsize_after = get_alloc_actual_size();
				Assert::IsTrue(living_before + 1 == living_after, L"Wrong number of instances", LINE_INFO());
				Assert::AreNotEqual(val.ID(), cval.ID(), L"IDs cannot be same", LINE_INFO());

				if constexpr(KCBlock_allocate)
					Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
				else
					Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());

				Assert::IsTrue(val.Value() == cval.Value(), L"Must be true", LINE_INFO());
				}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		TEST_METHOD(CBlock_assignment_to_existing)
			{
			const CBlock cval(CBlock::TestValue1());
			size_t allocsize_before = get_alloc_actual_size();
			ptrdiff_t living_before = ClassInfo<CBlock>::Living();
			ptrdiff_t living_after;
			size_t allocsize_after;
				{
				CBlock val(-cval);
				val = cval;

				living_after = ClassInfo<CBlock>::Living();
				allocsize_after = get_alloc_actual_size();
				Assert::IsTrue(living_before + 1 == living_after, L"Wrong number of instances", LINE_INFO());
				Assert::AreNotEqual(val.ID(), cval.ID(), L"IDs cannot be same", LINE_INFO());

				if constexpr(KCBlock_allocate)
					Assert::IsTrue(allocsize_before < allocsize_after, L"No memory allocation", LINE_INFO());
				else
					Assert::IsTrue(allocsize_before == allocsize_after, L"Memory allocated", LINE_INFO());

				Assert::IsTrue(val.Value() == cval.Value(), L"Must be true", LINE_INFO());
				}
			ptrdiff_t living_after2 = ClassInfo<CBlock>::Living();
			size_t allocsize_after2 = get_alloc_actual_size();
			Assert::IsTrue(living_before == living_after2, L"Wrong number of instances", LINE_INFO());
			Assert::AreEqual(allocsize_before, allocsize_after2, L"Memory leaking", LINE_INFO());
			}

		}; /* TEST_CLASS(CBlockFunctionalTests) */

	} /* namespace CBlockUnitTests */
