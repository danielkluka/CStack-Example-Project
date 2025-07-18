/** \file main.cpp
 *  \brief Main source
 *  \details Simple CContainer example of usage
 *  \author Pety 20XX / 2022 modified Richter
 *  $Id: main.cpp 3 2022-10-26 17:03:14Z petyovsky $
 */

#include <ctime>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>		// Due to: std::is_same_v<>

#include "demagle.h"
#include "CBlock.h"
#include "check.h"

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

		// Tady bude zdrojovy text pouzivajici vas projekt

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
