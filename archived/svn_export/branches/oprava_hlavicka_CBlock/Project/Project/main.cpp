/** \file main.cpp
 *  \brief Main source
 *  \details Simple CContainer example of usage
 *  \author Kluka, Majnus, Pesek, Prasek, Pety 20XX / 2022 modified Richter
 *  $Id: main.cpp 2228 2022-12-04 10:38:39Z xkluka00 $
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

	try
		{
		cout << "Nyni existuje " << ClassInfo<CBlock>::Living() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;
		cout << endl;

		// Tady bude zdrojovy text pouzivajici vas projekt
		CBlock EmptyCBlock;
		CBlock CBlockVal0(CBlock::TestValue0());
		CBlock CBlockVal1(CBlock::TestValue1());
		CBlock CBlockValRand(CBlock::TestValueRandom());
		std::string string;


		//(implementation of CStack class methods created and sorted by each author - author1, author2, author3, author4)
		{// author1 - MAJNUS ===========================
		cout << "Testing methods of author1 - Majnus:" << endl ;
		cout << "-" << endl;
		cout << "End of testing methods of author1 - Majnus" << endl << endl;
		}// END author1 - MAJNUS =======================

		{// author2 - KLUKA ============================
			cout << "Testing methods of author2 - Kluka:" << endl;

			//CBlock conversion c'tor
			cout << "	Calling CBlock conversion c'tor" << endl;
			{
				CStack stack1(EmptyCBlock);						//(conversion c'tor uses "new" to allocate memory, d'tor using "delete" needed)
			}

			//String conversion c'tor
			cout << "	Calling string conversion c'tor" << endl;
			{
				CStack stack2(string.data());
			}

			//PocetPrvku getter
			cout << "	Calling PocetPrvku getter" << endl;
			{
				CStack stack3;
				size_t PocetPrvku(stack3);
			}

			//Unary operator -
			cout << "	Calling unary operator -" << endl;
			{
				CStack stack4;
				-stack4;
			}

			//Unary operator --
			cout << "	Calling unary operator --" << endl;
			{
				CStack stack5;
				--stack5;										
			}

			//Binary operator -=
			cout << "	Not calling binary operator -= in this version" << endl;
			{
				CStack stack6;
				CStack stack7;
				//stack6 -= stack7;								
			}

			//Threeway comparison by Value operator
			cout << "	Calling threeway comparison by Value operator" << endl;
			{
				CStack stack9;
				CStack stack10;
				stack9 <=> stack10;
			}

			//Method aaa.Reverse
			cout << "	Calling method aaa.Reverse" << endl;
			{
				CStack stack8;
				stack8.Reverse();
			}

			cout << "End of testing methods of author2 - Kluka" << endl;
			cout << "Methods of author2 report: operator -- is waiting for method Pop and operator -= is probably not working (exception because of empty stacks?)" << endl;
			cout << endl;
			//test commitu pre Simona
		}// END author2 - KLUKA ========================

		{// author3 - PRASEK ===========================



		}// END author3 - PRASEK =======================

		{// author4 - PESEK ============================
			CStack s;
			CBlock b;
			s.Push(b);

			cout << "TEST OF TESTVALUE0" << endl;
			
			size_t n = 5;
			CStack aa = CStack::TestValue0(n);
			
			std::cout << "CStack length = " << aa.PocetPrvku() << std::endl;
			
			

		}// END author4 - PESEK ========================

		cout << "Hotovo." << endl;
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

	cout << endl << "Nyni existuje " << ClassInfo<CBlock>::Living() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock).name()) << endl;

	cout << endl << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_bool::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_bool::CBlock).name()) << endl;
	cout << "V prubehu programu vzniklo celkem " << ClassInfo<CBlock_TWeekDay::CBlock>::Total() << " instanci tridy: " << DM(typeid(CBlock_TWeekDay::CBlock).name()) << endl;

	return 0;
	}
