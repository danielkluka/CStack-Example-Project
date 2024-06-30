#ifndef CLASSINFO_H
#define CLASSINFO_H
/** \file ClassInfo.h
 *  \brief ClassInfo class header
 *  \details ClassInfo is class for statistical information about created and active objects of given class. 
 *  Inserting data parameter of ClassInfo as member of another class will (automaticaly) count creation and destruction of objects of these type.
 *  Due to this member is possible to find out number of objects (created and active) and unique ID for object (from creation order).
 *  Contain ClassInfo definition with 64bit counter support.
 *  \warning Don't modify this file
 *  \authors Petyovsky, Richter
 *  \version 2021
 *  $Id: ClassInfo.h 3 2022-10-26 17:03:14Z petyovsky $
 */

#include <cstddef>	// due size_t and ptrdiff_t (ssize_t) (unsigned and int better equivalent for x64 platforms)

/** \brief ClassInfo class template
 *  \tparam	T	The class name of type that want to keep statistical information
 *  \details Definition of ClassInfo class template. There is defined all common methods and member variables.
 */
template <typename T>
	class ClassInfo
		{
		const size_t iID;					///< Constant value for simple runtime instance identification and debuging (unique in class T)
		static size_t iTotalCounter;		///< Summary count of all created instances of T
		static ptrdiff_t iLivingCounter;	///< Counter of actually existing instances of T .Probably `ssize_t` in [C++23](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0330r8.html)
#if (__cplusplus >= 201103L) || (_MSC_VER >= 1600)
		friend T;							///< Set Template argument class as friend. So no one (only class) have access to the private methods of ClassInfo instances. C++11 feature.
#else
	public:
#endif
		// c'tors:
#define CLASSINFO_DEFAULT_CTOR_BODY :iID(iTotalCounter++) { iLivingCounter++; }
#if (__cplusplus >= 201103L) || (_MSC_VER >= 1800)
	#define CLASSINFO_DEFAULT_CTOR_BODY_DELEGATED :ClassInfo() {}
#else
	#define CLASSINFO_DEFAULT_CTOR_BODY_DELEGATED CLASSINFO_DEFAULT_CTOR_BODY
#endif

		/** \brief Default c'tor
		 *  \details Initialise iID and increment counters.
		 */
		ClassInfo() CLASSINFO_DEFAULT_CTOR_BODY

		/** \brief Copy c'tor
		 *  \details Initialise iID and increment counters.
		 */
		ClassInfo(const ClassInfo &) CLASSINFO_DEFAULT_CTOR_BODY_DELEGATED

		// d'tor
		/** \brief d'tor
		 *  \details Decrement Living instance counter only.
		 */
		~ClassInfo()
			{
			iLivingCounter--;
			}

		/** \brief Assigment operator
		 *  \return Just return self
		 */
		ClassInfo& operator=(const ClassInfo &)
			{
			return *this;
			}

#define CLASSINFO_MOVE_SEMANTICS
#ifdef CLASSINFO_MOVE_SEMANTICS
		
		/** \brief Move c'tor!
		 *  \details Initialise new iID and increment counters.
		 */
		ClassInfo(ClassInfo &&) CLASSINFO_DEFAULT_CTOR_BODY_DELEGATED

		/** \brief Move operator
		 *  \return Just return self
		 */
		ClassInfo& operator=(ClassInfo &&)
			{
			return *this;
			}

#endif /* CLASSINFO_MOVE_SEMANTICS */

		/** \brief ID getter
		 *  \return Unique instance ID
		 */
		size_t ID() const
			{
			return iID;
			}

#if (__cplusplus >= 201103L) || (_MSC_VER >= 1600)
	public:
#endif
		// counters getters:
		/** \brief Getter for actual count of all created instances
		 *  \return Actual count of all created instances
		 */
		static size_t Total()
			{
			return iTotalCounter;
			}

		/** \brief Getter for count of actually existing instances
		 *  \return Count of actually existing instances
		 */
		static ptrdiff_t Living()		// ssize_t in C++23: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0330r8.html
			{
			return iLivingCounter;
			}

		}; /* class ClassInfo */

template <typename T>
	size_t ClassInfo<T>::iTotalCounter = 0;

template <typename T>
	ptrdiff_t ClassInfo<T>::iLivingCounter = 0;

#endif /* CLASSINFO_H */
