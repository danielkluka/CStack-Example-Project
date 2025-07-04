/** \file main.cpp
 *  \brief Main source
 *  \details Simple CContainer example of usage
 *  \author Kluka, Majnus, Pesek, Prasek, Pety 20XX / 2022 modified Richter
 *  $Id: main.cpp 3496 2022-12-21 22:57:36Z xkluka00 $
 */

#include <ctime>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>		// Due to: std::is_same_v<>

#include "demagle.h"
#include "CBlock.h"
#include "check.h"
#include "CStack.h"

using std::endl;
using std::cout;
using std::cin;
using std::cerr;

int main(int argc, char *argv[])
	{
#ifdef NDEBUG
	std::srand(unsigned(std::time(nullptr)));	// Initialize random generator by actual time
#else
	std::srand(unsigned(42));					// Initialize random generator by fixed value useful for debugging
#endif

	cout << "Pocet parametru: " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << "Parametr #" << i << ": " << argv[i] << endl;
	
	cout << endl << "Nyni existuje " << ClassInfo<CBlock>::Living() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;
	cout << "Velikost jedne instance tridy " << DM(typeid(CBlock).name()) << " je: " << sizeof(CBlock) << " bajtu." << endl;

	cout << endl << "Nyni existuje " << ClassInfo<CStack>::Living() << " instanci tridy: " << DM(typeid(CStack).name()) << endl;
	cout << "Velikost jedne instance tridy " << DM(typeid(CStack).name()) << " je: " << sizeof(CStack) << " bajtu." << endl;
	cout << endl;

	try
		{
		cout << "===============================================================================" << endl;
		cout << "Nyni existuje " << ClassInfo<CBlock>::Living() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;
		cout << "Nyni existuje " << ClassInfo<CStack>::Living() << " instanci tridy: " << DM(typeid(CStack).name()) << endl;
		cout << endl;

		CBlock EmptyCBlock;
		CBlock CBlockVal0(CBlock::TestValue0());
		CBlock CBlockVal1(CBlock::TestValue1());
		CBlock CBlockValRand(CBlock::TestValueRandom());
		CBlock CBlockString(CBlock::TestStringValue1());
		std::string string;

		//(implementation of CStack class methods created and sorted by each author - author1, author2, author3, author4)
		{// author1 - MAJNUS ===========================
			cout << endl << "Testing methods of author1 - Majnus:" << endl ;
			
			cout << endl << "	Calling default c'tor" << endl;

				CStack Stack1;
				cout << endl << "		"<< Stack1 << " - Empty Stack1 " << endl;
			
			cout << endl << "	Calling copy c'tor" << endl;
				cout << endl << "		Pushing 3 values to stack1 " << endl;
				Stack1.Push(CBlockVal0);
				Stack1.Push(CBlockVal1);
				Stack1.Push(CBlockVal0);
				cout << "		" << Stack1 << " - Stack1 with 3 values pushed inside" << endl;

				cout << endl << "		Starting copying Stack1 into the Stack2" << endl;
				CStack Stack2(Stack1);
				cout << "		" << Stack2 << "Stack2 with copied values from Stack1" << endl;

			cout << endl << "	Calling unary Operator !" << endl;
				!Stack1;
				cout << endl << "		For exception, please uncomment comment section" << endl;

				/* For exception, please uncomment
				CStack Stack3;
				!Stack3;
				*/

			cout << endl << "	Calling binary Operator +" << endl;
				CStack Stack4 = Stack1 + Stack2;
				cout << endl << "		" << Stack4 << " - Stack4 = Stack1+Stack2" << endl;
				
			cout << endl << "	Calling binary Operator =" << endl;
				Stack1 = Stack4;
				cout << endl << "		" << Stack1 << " - Stack1 = Stack4" << endl;

			cout << endl << "	Calling Actual getter =" << endl;
				cout << endl << "		" << Stack1.Actual() << " - Stack1 Actual" << endl;
				cout << "		" << Stack2.Actual() << " - Stack2 Actual" << endl;
				cout << "		" << Stack4.Actual() << " - Stack4 Actual" << endl;

			cout << endl << "	Calling ID getter =" << endl;
				cout << endl << "		" << Stack1.ID() << " - Stack1 ID" << endl;
				cout << "		" << Stack2.ID() << " - Stack2 ID" << endl;
				cout << "		" << Stack4.ID() << " - Stack4 ID" << endl;

			cout << endl << "	Calling Total getter =" << endl;
				cout << endl << "		" << Stack1.Total() << " - Stack1 Total" << endl;
				cout << "		" << Stack2.Total() << " - Stack2 Total" << endl;
				cout << "		" << Stack4.Total() << " - Stack4 Total" << endl;

			cout << endl << "	Calling Top =" << endl;
				cout << endl << "		" << Stack1.Top() << " - Stack1 Top adress" << endl;
				cout << "		" << Stack2.Top() << " - Stack2 Top adress" << endl;
				cout << "		" << Stack4.Top() << " - Stack4 Top adress" << endl;
				cout << endl << "		" << Stack1.Top()->Value() << " - Stack1 Top value" << endl;
				cout << "		" << Stack2.Top()->Value() << " - Stack2 Top value" << endl;
				cout << "		" << Stack4.Top()->Value() << " - Stack4 Top value" << endl;

			cout << endl << "	Calling Bottom =" << endl;
				cout << endl << "		" << Stack1.Bottom() << " - Stack1 Bottom adress" << endl;
				cout << "		" << Stack2.Bottom() << " - Stack2 Bottom adress" << endl;
				cout << "		" << Stack4.Bottom() << " - Stack4 Bottom adress" << endl;
				cout << endl << "		" << Stack1.Bottom()->Value() << " - Stack1 Bottom value" << endl;
				cout << "		" << Stack2.Bottom()->Value() << " - Stack2 Bottom value" << endl;
				cout << "		" << Stack4.Bottom()->Value() << " - Stack4 Bottom value" << endl;

			cout << endl << "End of testing methods of author1 - Majnus" << endl;

			cout << endl;
		}// END author1 - MAJNUS =======================

		{// author2 - KLUKA ============================
			cout << "Testing methods of author2 - Kluka:" << endl;
#ifdef KLUKA_PRINT
			cout << endl << "	KLUKA_PRINT is enabled." << endl;
#else
			cout << endl <<
				   "	KLUKA_PRINT mode in CStack.h is not enabled. To see each step of my methods in detail, please," << endl
				<< "	enable this mode defined in the CStack.h file at the top of this file. This also gives you extra" << endl
				<< "	control of methods of other authors. Formated well only for author Kluka; CBLOCK LEVEL." << endl;
#endif
			// CBlock conversion c'tor
			cout << endl << "	Calling CBlock conversion c'tor" << endl;
				{
				CStack stack1(CBlockVal0);

				cout << "		CStack stack1("<<CBlockVal0<<"): " << stack1 << endl;
				}

			// String conversion c'tor
			cout << endl << "	Calling string conversion c'tor" << endl;
				{
				std::cout << "		stream: " << "(" + CBlock::TestStringValue0() + "," + CBlock::TestStringValue1() + ")" << endl;

				CStack stack2("("+CBlock::TestStringValue0()+","+ CBlock::TestStringValue1() + ")");

				cout << "		stack2: " << stack2 << endl;
				}

			// PocetPrvku getter
			cout << endl << "	Calling PocetPrvku getter" << endl;
				{
				CStack stack3;
				size_t count;

				count = stack3.PocetPrvku();

				cout << "		Empty Stack: " << stack3 << endl;
				cout << "		stack3.PocetPrvku(): " << count << endl;

				stack3.Push(CBlockVal0);
				stack3.Push(CBlockVal0);
				stack3.Push(CBlockVal0);

				count = stack3.PocetPrvku();

				cout << endl << "		Stack with 3 values: " << stack3 << endl;
				cout << "		stack3.PocetPrvku(): " << count << endl;
				}

			// Unary operator -
			cout << endl << "	Calling unary operator -" << endl;
				{
				CStack stack4;

				stack4.Push(CBlockVal0);
				stack4.Push(CBlockVal0);
				stack4.Push(CBlockVal1);

				cout << "		stack4: " << stack4 << endl;

				-stack4;

				cout << "		-stack4: " << stack4 << endl;
				}

			// Unary operator --
			cout << endl << "	Calling unary operator --" << endl;
				{
				CStack stack5;

				stack5.Push(CBlockVal0);
				stack5.Push(CBlockVal0);

				cout << "		stack5: " << stack5 << endl;

				--stack5;

				cout << "		--stack5: " << stack5 << endl;
				}

			// Binary operator -=
			cout << endl << "	Calling binary operator -=" << endl;
				{
				CStack stack6;
				CStack stack7;

				stack6.Push(CBlockVal0);
				stack6.Push(CBlockVal1);
				stack6.Push(CBlockVal0);

				cout << "		stack6: " << stack6 << endl;

				stack7.Push(CBlockVal1);

				cout << "		stack7: " << stack7 << endl;

				stack6 -= stack7;

				cout << endl << "		stack6 after stack6 -= stack7: " << stack6 << endl;
				}

			// Relational Operator ==
			cout << endl << "	Calling relational operator ==" << endl;
				{
				CStack stack8;
				CStack stack9;
				bool result;

				stack8.Push(CBlockVal0);

				cout << "		stack8: " << stack8 << endl;

				stack9.Push(CBlockVal0);

				result = stack8 == stack9;

				cout << "		stack9: " << stack9 << endl << endl;
				cout << "		stack8 == stack9: " << result << endl;
				}

			// Three-way comparison by Value operator
			cout << endl << "	Calling three-way comparison by Value operator" << endl;
				{
				CStack stack10;
				CStack stack11;
				bool result1, result2, result3;

				stack10.Push(CBlockVal0);

				cout << "		stack10: " << stack10 << endl;

				stack11.Push(CBlockVal1);

				cout << "		stack11: " << stack11 << endl << endl;

				result1 = (stack10 < stack11);
				result2 = (stack10 > stack11);
				result3 = (stack10 <= stack11);

				cout << "		stack10 < stack11: " << result1 << endl;
				cout << "		stack10 > stack11: " << result2 << endl;
				cout << "		stack10 <= stack11: " << result3 << endl;
				}

			// Method aaa.Reverzuj
			cout << endl << "	Calling method aaa.Reverzuj" << endl;
				{
				CStack stack12;

				stack12.Push(CBlockVal0);
				stack12.Push(CBlockVal0);
				stack12.Push(CBlockVal1);

				cout << "		stack12: " << stack12 << endl;

				stack12.Reverzuj();

				cout << "		stack12.Reverzuj(): " << stack12 << endl;
				}

			cout << endl << "End of testing methods of author2 - Kluka" << endl;
			cout << endl;

		}// END author2 - KLUKA ========================

		{// author3 - PRASEK ===========================
			cout << "Testing methods of author3 - Prasek:" << endl;

			// Convert C'tor from init list
			cout << "\n	Calling Convert C'tor from init list" << endl;
				{
				CStack stackS1 = { CBlockVal0, CBlockVal1 };
				cout << "		The stackS1 consists of an array of size: " << stackS1.PocetPrvku() << endl;
				cout << "		stackS1 = " << stackS1 << endl;
				}

			// Conversion C'tor of type size_t
				cout << "\n	Calling Conversion C'tor of type size_t " << endl;
				{
				CStack stackS2(3);
				cout << "		The stackS2 consists of size of size_t: " << (size_t)stackS2 << endl;
				cout << "		stackS2 = " << stackS2 << endl;
				}
			 
			// Unary operator ++
			cout << "\n	Calling unary operator ++" << endl;
				{
				CStack stackS3;
				++stackS3;
				cout << "		New CBlock element: " << stackS3.Top()->Value() << " was pushed on Top of the StackS3" << endl;
				cout << "		stackS3 = " << stackS3 << endl;
				}

			// Binary operator -
			cout << "\n	Calling binary operator -" << endl;
				{
				CStack stackS4;
				CStack stackS5;
				CStack stackRes;

				stackS4.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS4" << endl;
				stackS4.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS4" << endl;

				cout << "		stackS4 = " << stackS4 << endl;

				stackS5.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS5" << endl;
				stackS5.Push(CBlockVal1);
				cout << "		CBlock element:" << CBlockVal1 << " was pushed into the stackS5" << endl;

				cout << "		stackS5 = " << stackS5 << endl;

				stackRes = stackS4 - stackS5;
				cout << "		Substracting stackS5 from stackS4" << endl;
				cout <<	"		stackRes =" << stackRes << endl;
				}	

			// Operator size_t
			cout << "\n	Calling operator size_t" << endl;
				{
				CStack stackS6;
				stackS6.Push(CBlockVal0);
				cout << "		Size_t of stackS6 is: " <<(size_t)stackS6 << endl;
				cout << "		stackS6 = " << stackS6 << endl;
				}

			// Relation operator <
			cout << "\n	Calling relation operator <" << endl;
				{
				CStack stackS7;
				CStack stackS8;

				stackS7.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS7" << endl;
				stackS8.Push(CBlockVal1);
				cout << "		CBlock element:" << CBlockVal1 << " was pushed into the stackS8" << endl;
				stackS8.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS8" << endl;

				if(stackS7 < stackS8)
					cout << "		StackS7" << stackS7 << "have less elements than stackS8"<< stackS8 << endl;
				else
					cout << "		StackS7" << stackS7 << "have more elements than stackS8" << stackS8 << endl;
				}

			// Function Reverzuj(aaa)
			cout << "\n	Calling function Reverzuj(aaa)" << endl;
				{
				CStack stackS9;
				stackS9.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS9" << endl;
				stackS9.Push(CBlockVal1);
				cout << "		CBlock element:" << CBlockVal1 << " was pushed into the stackS9" << endl;
				cout << "		stackS9 = " << stackS9 << endl;
				CStack stackS10 = Reverzuj(stackS9);
				cout << "		Reversing stackS9" << endl;
				cout << "		stackS10 = " << stackS10 << endl;
				}

			// Method Stack Pop
			cout << "\n	Calling method Stack Pop" << endl;
				{
				CStack stackS11;
				stackS11.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS11" << endl;
				stackS11.Pop();
				cout << "		Using Pop() on the stackS11" << endl;
				cout << "		stackS11 = " << stackS11 << endl;
				}

			// Method Stack Top - Tested by author4

			// Method Stack Search
			cout << "\n	Calling method Stack Search" << endl;
				{
				CStack stackS12;
				stackS12.Push(CBlockVal0);
				cout << "		CBlock element:" << CBlockVal0 << " was pushed into the stackS12" << endl;
				stackS12.Push(CBlockVal1);
				cout << "		CBlock element:" << CBlockVal1 << " was pushed into the stackS12" << endl;
				cout << "		Searching for CBlock element: " <<CBlockVal0<< endl;
				if(stackS12.Search(CBlockVal0))
					{
					cout << "		CBlock element found" << endl;
					}
				else
					cout << "		CBlock element not found" << endl;
				cout << "		stackS12 = " << stackS12 << endl;
				}
			
			cout << "End of testing methods of author3 - Prasek" << endl;
			cout << endl;
		}// END author3 - PRASEK =======================

		{// author4 - PESEK ============================

			cout << "Testing methods of author4 - Pesek:" << endl;

			// Method Stack Push
			cout << "\n	Testing method Stack Push" << endl;
				{
				CStack Stack;
				Stack.Push(CBlockVal1);
				cout << "		Value to be pushed onto stack = " << CBlockVal1 << endl;
				cout << "		Value on Top of Stack = " << Stack.Top()->Value() << endl;
				cout << "		Stack = " << Stack << endl;
				}

			// Method Stack Top
			cout << "\n	Testing method Stack Top" << endl;
				{
				size_t n = 2;
				CBlock* Array = CStack::TestValueRandom(n);
				CStack Stack = CStack(n, Array);
				free(Array);
				cout << "		Value on Top of Stack = " << Stack.Top()->Value() << endl;
				cout << "		Stack = " << Stack << endl;
				}

			//CBlock array of known size conversion c'tor
			cout << "\n	Testing conversion c'tor from CBlock array of known size" << endl;
				{
				size_t n = 3;
				CBlock* Array = CStack::TestValueRandom(n);
				CStack Stack = CStack(n, Array);
				

				for (size_t i = 0; i < n; ++i)
					{
					cout << "		Array[" << i << "] = " << Array[i] << endl;
					}
				free(Array);

				cout << "		Array size = " << n << endl;
				cout << "		Stack size = " << Stack.PocetPrvku() << endl;
				cout << "		Stack = " << Stack << endl;
				}

			//binary operator +=
			cout << "\n	Testing binary operator +="<< endl;
				{
				CBlock* Array1 = CStack::TestValueRandom(2);
				CBlock* Array2 = CStack::TestValueRandom(3);

				CStack Stack1 = CStack(2, Array1);
				CStack Stack2 = CStack(3, Array2);

				free(Array1);
				free(Array2);

				size_t Stack1_old_size = Stack1.PocetPrvku();

				cout << "		" << Stack1 << "+ " << Stack2 << "= ";
				Stack1 += Stack2;
				cout << Stack1 << "\n" << endl;

				cout << "		       " << Stack1_old_size << "        +      " << Stack2.PocetPrvku() << "     " << " =       " << Stack1.PocetPrvku() << endl;
				cout << "		Stack5_old_size + Stack6_size = Stack5_new_size" << endl;
				}

			//binary non member operator +
			cout << "\n	Testing binary CStack class non member operator +" << endl;
				{
				CBlock* Array = CStack::TestValueRandom(2);

				CStack Stack = CStack(2, Array);
				free(Array);

				cout << "		Stack = " << Stack << endl;
				cout << "		CBlock = " << CBlockVal1 << endl;
				cout << "		CBlock + Stack = " << CBlockVal1 + Stack << "\n" << endl;

				cout << "		Stack = " << Stack << endl;
				cout << "		CBlock = " << CBlockVal1 << endl;
				cout << "		Stack + CBlock = " << Stack + CBlockVal1 << endl;
				}

			//binary operator >
			cout << "\n	Testing binary operator >" << endl;
				{
				CBlock* Array1 = CStack::TestValueRandom(2);
				CBlock* Array2 = CStack::TestValueRandom(3);
				CBlock* Array3 = CStack::TestValueRandom(3);
				CBlock* Array4 = CStack::TestValueRandom(3);

				CStack Stack1 = CStack(2, Array1);
				CStack Stack2 = CStack(3, Array2);
				CStack Stack3 = CStack(3, Array3);
				CStack Stack4 = CStack(3, Array4);

				free(Array1);
				free(Array2);
				free(Array3);
				free(Array4);

				cout << "		Stack1 = " << Stack1 << endl;
				cout << "		Stack2 = " << Stack2 << endl;
				cout << "		Stack3 = " << Stack3 << endl;
				cout << "		Stack4 = " << Stack4 << endl;

				if (Stack2 > Stack1)
					{
					cout << "		Stack2 is bigger than Stack1" << endl;
					}
				else
					{
					cout << "		Stack2 is not bigger than Stack1" << endl;
					}

				if (Stack4 > Stack3)
					{
					cout << "		Stack4 is bigger than Stack3" << endl;
					}
				else
					{
					cout << "		Stack4 is not bigger than Stack3" << endl;
					}
				}

			//Unary operator +
			cout << "\n	Testing unary operator+" << endl;
				{
				CBlock* Array = CStack::TestValueRandom(3);
				CStack Stack1 = CStack(3, Array);
				free(Array);
				CStack Stack2 = +Stack1;

				cout << "		Stack1 size = Stack2 size" << endl;
				cout << "		     " << Stack1.PocetPrvku() << "      =      " << Stack2.PocetPrvku() << "     " << endl;

				cout << "		Stack1 = " << Stack1 << endl;
				cout << "		Stack2 = " << Stack2 << endl;
				}

			//method Usage
			cout << "\n	Testing method Usage" << endl;
				{
				double Usage = CStack::Usage();
				cout <<
					"		Stack uses " << Usage << " % more memory than array of the same amount of CBlock encapsulated values "
					<< endl;
				}

			//method Dup
			cout << "\n	Testing method Dup" << endl;
				{
				CBlock* Array = CStack::TestValueRandom(3);
				CStack Stack1 = CStack(3, Array);
				free(Array);

				CStack Stack2 = Stack1.Dup();

				cout << "		Stack1 = " << Stack1 << endl;
				cout << "		Stack2 = " << Stack2 << endl;
				}

			//method TestValueRandom
			cout << "\n	Testing method CStack::TestValueRandom" << endl;
				{
				size_t n = 5;
				CBlock* Array = CStack::TestValueRandom(n);

				for(size_t i = 0; i<n; ++i)
					{
					cout << "		Array[" << i << "] = " << Array[i] << endl;
					}
				free(Array);
				//std::cout << "	CStack length = " << aa.PocetPrvku() << std::endl;
				}

			cout << "End of testing methods of author4 - Pesek" << endl;
			cout << endl;

		}// END author4 - PESEK ========================

		cout << "Hotovo." << endl;
		cout << "===============================================================================" << endl;
		} /* try */

	catch(std::invalid_argument &e)
		{
		cerr << "std::invalid_argument: " << e.what() << "!!!\n\a" << endl;
		}
	catch(std::length_error &e)
		{
		cerr << "std::length_error: " << e.what() << "!!!\n\a" << endl;
		}
	catch(std::out_of_range &e)
		{
		cerr << "std::out_of_range: " << e.what() << "!!!\n\a" << endl;
		}
	catch(std::range_error &e)
		{
		cerr << "std::range_error: " << e.what() << "!!!\n\a" << endl;
		}
	catch(std::runtime_error &e)
		{
		cerr << "std::runtime_error: " << e.what() << "!!!\n\a" << endl;
		}
	catch(std::bad_alloc &e)
		{
		cerr << "std::bad_alloc: " << e.what() << "!!!\n\a" << endl;
		}
	catch(char const *e)
		{
		cerr << "Exception detected: " << e << " !!!\n\a" << endl;
		}
	
	cout << endl << "Nyni existuje " << ClassInfo<CBlock>::Living() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;

	cout << endl << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_bool::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_bool::CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_long::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_long::CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_TInterval::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_TInterval::CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_TWeekDay::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_TWeekDay::CBlock).name()) << endl;

	cout << endl << "Nyni existuje " << ClassInfo<CStack>::Living() << " instanci tridy: " << DM(typeid(CStack).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CStack>::Total() << " instanci tridy: " << DM(typeid(CStack).name()) << endl;

	return 0;
	}
