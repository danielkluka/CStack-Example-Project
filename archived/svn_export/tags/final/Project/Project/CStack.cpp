/** \file CStack.cpp
 *  \brief CStack class source
 *  \details File contains implementation of CStack support functions
 *  \authors Kluka, Majnus, Pesek, Prasek
 *  \version 2022
 *	\attention File CStack.cpp is in last stage of development.
 *  $Id: CStack.cpp 3691 2022-12-30 12:38:24Z xkluka00 $
 */

#include <cstring>
#include "CStack.h"

// comparison methods
/*	Private method CompareDeep
 *	authors	Majnus
 *	helped Kluka (whole source code)
 */
int CStack::CompareDeep(const CStack& aStack) const 
	{
	size_t aStack1_Count = iCount;
	size_t aStack2_Count = aStack.iCount;

	if (!aStack2_Count && !aStack1_Count)
		return 0;

	if (aStack1_Count < aStack2_Count) return -1;
	if (aStack1_Count > aStack2_Count) return 1;
	if (aStack1_Count == aStack2_Count)
		{
		CBlock* Current_Stack1 = iTop;
		CBlock* Current_Stack2 = aStack.iTop;

		while (Current_Stack1 != NULL)
			{
			if (Current_Stack1->Value() < Current_Stack2->Value()) return -1;
			if (Current_Stack1->Value() > Current_Stack2->Value()) return 1;
			if (Current_Stack1->Value() == Current_Stack2->Value())
				{
				Current_Stack1 = static_cast<CBlock*>(Current_Stack1->NextItem());
				Current_Stack2 = static_cast<CBlock*>(Current_Stack2->NextItem());
				}
			}
		}

	return 0;
	}

/*	Private method Compare
 *	author Pesek
 */
int CStack::Compare(const CStack& aStack) const
	{
	if (this->PocetPrvku() > aStack.PocetPrvku())
		{
		return 1;
		}
	else if (this->PocetPrvku() < aStack.PocetPrvku())
		{
		return -1;
		}
	else
		return 0;
	}

// c'tors
/*	Default c'tor
 *	author Majnus
 */
CStack::CStack(): iTop(nullptr), iBottom(nullptr),iCount(0)
	{
	}

/*	CBlock conversion c'tor
 *	author Kluka
 */
CStack::CStack(const CBlock& aBlock)
	{
#ifdef KLUKA_PRINT
	std::cout << "		CBlock conversion c'tor was called" << std::endl;
	std::cout << std::endl << "		C'tor loaded value: " << aBlock.Value() << std::endl;
#endif

	iTop = new CBlock(aBlock.Value(), nullptr, nullptr);
	iTop->SetPrevNext(nullptr, nullptr);
	iBottom = iTop;
	iCount = 1;

#ifndef NDEBUG
	IntegrityTest();
#endif

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		C'tor set values: " << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iTop->Value() << std::endl;
	std::cout << "		iCount: " << iCount << std::endl;
	std::cout << std::endl << "		CBlock conversion c'tor was called successfully" << std::endl;
#endif
	}

/*	Copy c'tor
 *	author Majnus
 */
CStack::CStack(const CStack& aStack) : iTop(nullptr), iBottom(nullptr), iCount(0) 
	{
	const CBlock *tmp = aStack.iBottom;
	while(tmp != nullptr)
		{
		Push(*tmp);
		tmp = dynamic_cast<const CBlock *>(tmp->PrevItem());
		}
	}

/*	String conversion c'tor
 *	author Kluka
 */
CStack::CStack(const std::string& aString) : iTop(nullptr), iBottom(nullptr), iCount(0)
	{
#ifdef KLUKA_PRINT
	std::cout << "		String conversion c'tor was called" << std::endl;
#endif

	std::stringstream ss;

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		C'tor is calling operator << " << std::endl;
#endif

	ss << aString;

#ifdef KLUKA_PRINT
	std::cout << "			Operator loaded stream: " << aString << std::endl;
#endif

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		C'tor is calling operator >> " << std::endl;
#endif

	ss >> *this;
#ifdef KLUKA_PRINT
	std::cout << "		String conversion c'tor was called succesfully" << std::endl;
#endif
	}

/*	CBlock conversion c'tor from array of known size
 *	author Pesek
 */
CStack::CStack(size_t aSize, const CBlock* aArray) : iTop(nullptr), iBottom(nullptr), iCount(0)
	{
	for (size_t i = 0; i < aSize; ++i)
		{
		Push(aArray[i]);
		}
	}

/*	Conversion c'tor from init list
 *	author Prasek
 */
CStack::CStack(std::initializer_list<CBlock> aInitList) : CStack(aInitList.size(), std::data(aInitList))
	{
	}

/*	Conversion c'tor of type size_t
 *	author Prasek
 */
CStack::CStack(const size_t aSize) : iTop(nullptr), iBottom(nullptr), iCount(0)
	{
	for(size_t i = 0; i < aSize; ++i)
		{
		this->Push(CBlock());
		}
	}

// d'tor
/*	Destructor
 *	author Majnus
 *	helped Kluka
 */
CStack::~CStack() noexcept(false)
	{
	Destroy();
	}

/*	Destroy
 *	author Kluka
 */
void CStack::Destroy()
	{
	if(!iCount && !iTop)
		return;

	CBlock *node = iTop;
	while(node)
		{
		iTop = static_cast<CBlock *>(node->NextItem());
		node->SetPrevNext(nullptr, nullptr);
		delete node;
		node = iTop;
		}

	iTop = iBottom = nullptr;
	iCount = 0;

	return;
	}

// InstanceInfo getters
/*	Actual getter
 *	author Majnus
 */
size_t CStack::Actual() const 
	{
	return iInstanceInfo.Living();
	}

/*	ID getter
 *	author Majnus
 */
size_t CStack::ID() const
	{
	return iInstanceInfo.ID();
	}

/*	Total getter
 *	author Majnus
 */
size_t CStack::Total() const
	{
	return iInstanceInfo.Total();
	}

// setters/getters
/*	PocetPrvku getter
 *	author Kluka
 */
size_t CStack::PocetPrvku() const
	{
#ifdef KLUKA_PRINT
	std::cout << "		PocetPrvku was called" << std::endl;
	std::cout << std::endl << "		iCount: " << iCount << std::endl;
	std::cout << std::endl << "		PocetPrvku was called successfully" << std::endl;
#endif

	return iCount;
	}

/*	Usage getter
 *	author Pesek
 */
double CStack::Usage()
	{
	CBlock* node = new CBlock();

	double iStack_memory = sizeof(CBlock);
	double iArray_memory = sizeof(node->Value());

	delete(node);

	return 100 * ((iStack_memory-iArray_memory) / iArray_memory);
	}

// unary operators
/*	Unary Operator +
 *	author Pesek
 */
CStack& CStack::operator+()
	{
	return *this;
	}

/*	Unary Operator -
 *	author Kluka
 */
CStack& CStack::operator-() 
	{
#ifdef KLUKA_PRINT
	std::cout << "		Operator - was called" << std::endl;
#endif

	if (!iCount)
		{
		throw "Error: iCount is 0";
		}

	if (!iTop)
		{
		throw "Error: iTop is nullptr";
		}

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Operator is calling Reverzuj " << std::endl;
#endif

	Reverzuj();

	if (!iCount)
		{
		throw "Error: iCount is 0";
		}

	if (!iTop)
		{
		throw "Error: iTop is nullptr";
		}

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Check if operator - received correct data: " << std::endl;
	std::cout << std::endl << "		Stack info after Reverzuj: " << std::endl;
	std::cout << "		iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	CBlock* Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}
	std::cout << std::endl << "		Operator - was called successfully " << std::endl;
#endif

#ifndef NDEBUG
	IntegrityTest();
#endif

	return *this;
	}

/*	Unary Operator ++
 *	author Prasek
 */
CStack& CStack::operator++() 
	{
	return this->Push(CBlock());
	}

/*	Unary Operator --
 *	author Kluka
 */
CStack& CStack::operator--()
	{
#ifdef KLUKA_PRINT
	std::cout << "		Operator -- was called" << std::endl;
#endif

	if (!iCount)
		{
		throw "Error: iCount is 0";
		}

	if (!iTop)
		{
		throw "Error: iTop is nullptr";
		}

	const size_t Count_before = iCount;

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Stack info before Pop: " << std::endl;
	std::cout << "		iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	CBlock* Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}

	std::cout << std::endl << "		Operator is calling Pop" << std::endl;
#endif

	Pop();

	const size_t Count_after = iCount;

#ifdef KLUKA_PRINT
	std::cout << "		Check if operator -- received correct data:" << std::endl;
	std::cout << std::endl << "		Stack info after Pop: " << std::endl;
	std::cout << "		iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}
#endif

#ifndef NDEBUG
	IntegrityTest();
#endif

	if (Count_before > Count_after)
		{
#ifdef KLUKA_PRINT
		std::cout << std::endl << "		Operator -- was called successfully " << std::endl;
#endif

		return *this;
		}
	else
		{
		throw "Error: Pop is not working correctly";
		}
	}

/*	Unary Operator !
 *	author Majnus
 */
bool CStack::operator!() const
	{
	if(!iTop)
		{
		throw "Error: iTop is nullptr";
		}

	return false;
	}

// binary operators
/*	Binary Operator +
 *	author Majnus
 */
CStack CStack::operator+(const CStack &aStack) const
	{
	CStack newstack;
	CBlock *tmp1 = this->iBottom;
	CBlock *tmp2 = aStack.iBottom;

	while(newstack.iCount != this->iCount)
		{
		newstack.Push(*tmp1);
		tmp1 = static_cast<CBlock *>(tmp1->PrevItem());
		}
	while((newstack.iCount - this->iCount) != aStack.iCount)
		{
		newstack.Push(*tmp2);
		tmp2 = static_cast<CBlock *>(tmp2->PrevItem());
		}

	return newstack;
	}

/*	Binary Operator =
 *	author Majnus
 */
CStack& CStack::operator=(const CStack &aStack)
	{
	while (iCount)
		{
		Pop();
		}

	CBlock *actual = aStack.iBottom;

	while(actual)
		{
		Push(*actual);
		actual = static_cast<CBlock *>(actual->PrevItem());
		}

	return *this;
	}

/*	Binary non-member Operator +
 *	author Pesek
 */
CStack operator+(const CBlock& aBlock, const CStack& aStack)
	{
	CStack NewStack(aStack);
	NewStack.Push(aBlock);
	return NewStack;
	}

/*	Binary non-member Operator +
 *	author Pesek
 */
CStack operator+(const CStack& aStack, const CBlock& aBlock)
	{
	CStack NewStack = CStack();
	NewStack.Push(aBlock);
	return NewStack + aStack;
	}

/*	Binary Operator -
 *	author Prasek
 */
CStack CStack::operator-(const CStack& aStack) const
	{
	CStack result;
	CBlock* stack2 = aStack.iTop;

	while (stack2 != nullptr)
		{
		CBlock *stack1 = this->iTop;
		bool found = false;
		while (stack1 != nullptr)
			{
			if (stack1->Value() == stack2->Value())
				{
				found = true;
				break;
				}
			stack1 = static_cast<CBlock *>(stack1->NextItem());
			}
		if(!found) 
			{
			result.Push(static_cast<CBlock>(stack2->Value()));
			}
		stack2 = static_cast<CBlock *>(stack2->NextItem());
		}

	return result;
	}

/*	Binary Operator -=
 *	author Kluka
 */
CStack& CStack::operator-=(const CStack& aStack)
	{
#ifdef KLUKA_PRINT
	std::cout << "		Operator -= was called" << std::endl;
#endif

	if (!iTop)
		{
		throw "Error: Stack1 iTop is nullptr";
		}

	if (!aStack.iTop)
		{
		throw "Error: Stack2 iTop is nullptr";
		}
	
	CBlock* Current_Stack = iTop;
	const CBlock* Current_Stack2;
	CStack New_Stack;
	bool skipped;

#ifdef KLUKA_PRINT
		std::cout << std::endl << "		Stack iCount: " << iCount << std::endl;
		std::cout << "		Stack2 iCount: " << aStack.iCount << std::endl << std::endl;
#endif

	while (Current_Stack != nullptr)
		{
		skipped = false;
		Current_Stack2 = aStack.iTop;

#ifdef KLUKA_PRINT
		std::cout << "		Stack value: " << Current_Stack->Value() << std::endl;
#endif

		while (Current_Stack2 != nullptr)
			{
#ifdef KLUKA_PRINT
			std::cout << "				Stack2 value: " << Current_Stack2->Value() << std::endl;
#endif

			if (Current_Stack->Value() == Current_Stack2->Value())
			{
#ifdef KLUKA_PRINT
				std::cout << "				match" << std::endl;
#endif

				Current_Stack = static_cast<CBlock*>(Current_Stack->NextItem());
				skipped = true;
				break;
				}
			Current_Stack2 = static_cast<const CBlock*>(Current_Stack2->NextItem());
			}

		if (skipped == true) continue;
		New_Stack.Push(static_cast<CBlock>(Current_Stack->Value()));
		Current_Stack = static_cast<CBlock*>(Current_Stack->NextItem());
		}

#ifdef KLUKA_PRINT
	std::cout << "		New Stack: " << std::endl;
	std::cout << "		New Stack iCount: " << New_Stack.iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	CBlock* Check_Stack = New_Stack.iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}
#endif

	-New_Stack;

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Operator is calling operator =" << std::endl;
#endif

	*this = New_Stack;

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		this: iTop -> iBottom " << std::endl;
	std::cout << "		this iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}
#endif

#ifndef NDEBUG
	IntegrityTest();
#endif

	if (*this == New_Stack)
		{
#ifdef KLUKA_PRINT
		std::cout << std::endl << "		Operator -= was called successfully " << std::endl;
#endif

		return *this;
		}
	else throw "Error: Operator = is not working correctly";
	}

/*	Binary Operator +=
 *	author Pesek
 */
CStack& CStack::operator+=(const CStack& aStack)
	{
	CBlock *node = aStack.Bottom();
	while(node)
		{
		Push(*node);
		node = static_cast<CBlock*>(node->PrevItem());
		}

	return *this;
	}

/*	Operator size_t
 *	author Prasek
 */
 CStack::operator size_t() const
	{
	return iCount;
	}

/*	Relational Operator ==
 *	author Kluka
 */
bool CStack::operator==(const CStack& aStack) const
	{
#ifdef KLUKA_PRINT
	std::cout << "		Operator == was called" << std::endl;
	std::cout << std::endl << "		Calling method CompareDeep" << std::endl;
#endif

	if (this->CompareDeep(aStack) == 0)
		{
#ifdef KLUKA_PRINT
		std::cout << std::endl << "		CompareDepp returned 0, Stacks are same" << std::endl;
		std::cout << std::endl << "		Operator == was called successfully " << std::endl;
#endif

		return true;
		}
	else
		{
#ifdef KLUKA_PRINT
		std::cout << std::endl << "		CompareDepp returned -1 or 1, Stacks aren't same" << std::endl;
		std::cout << std::endl << "		Operator == was called successfully " << std::endl;
#endif

		return false;
		}
	}

#ifdef CBLOCK_THREE_WAY_COMPARISON
/*	Three-way comparison by Value Operator
 *	author Kluka
 */
std::strong_ordering CStack::operator<=>(const CStack &aStack) const
	{
	return iCount <=> aStack.iCount;
	}

#else
// relational operators
/*	Relational Operator !=
 *	author Majnus
 */
bool CStack::operator!=(const CStack& aStack) const
	{
	if(this->CompareDeep(aStack) == 0)
		{
		return true;
		}
	else
		{
		return false;
		}
	}

/*	Relational Operator <
 *	author Prasek
 */
bool CStack::operator<(const CStack& aStack) const
	{
	if (CompareDeep(aStack) == -1))
		{
		return true;
		}
	else
		{
		return false;
		}
	}

/*	Relational Operator >
 *	author Pesek
 */
bool CStack::operator>(const CStack& aStack) const
	{
	if (this->CompareDeep(aStack) == 1)
		{
		return true;
		}
	else
		{
		return false;
		}
	}

#endif /* CBLOCK_THREE_WAY_COMPARISON */

/*	Output to the stream operator
 *	author Majnus
 */
std::ostream& operator<<(std::ostream &aOStream, const CStack &aStack)
	{
	aOStream << '(' << aStack.iCount << ": ";

	CBlock *ptr = aStack.iTop;
	while(ptr)
		{
		aOStream << *ptr;
		ptr = static_cast<CBlock *>(ptr->NextItem());
		if(ptr)
			aOStream << ",";
		}
	aOStream << ") ";

	return aOStream;
	}

/*	Input from the stream operator
 *	author Majnus
 */
std::istream& operator>>(std::istream &aIStream, CStack &aStack)
	{
	char ch;
	aIStream >> ch;
	if(ch != '(')
		throw std::runtime_error("Input stream data integrity error!");

	ch = aIStream.peek();
	if(ch == ')')
		{
		aIStream >> ch;
		return aIStream;
		}
	
	while(ch != ')')
		{
		CBlock blk;
		aIStream >> blk;
		if(!aIStream.good())
			throw std::runtime_error("Input stream data integrity error!");

		aStack.Push(blk);
		aIStream >> ch;
		if(!aIStream.good() || (ch != ',' && ch != ')'))
			throw std::runtime_error("Input stream data integrity error!");
		}

	return aIStream;
	}

// CStack characteristic methods
/*	Method aaa.Reverzuj
 *	author Kluka
 */
CStack& CStack::Reverzuj()
	{
#ifdef KLUKA_PRINT
	std::cout << "		Reverzuj was called" << std::endl;
#endif

	if (!iCount)
		{
		throw "Error: iCount is 0";
		}

	if (!iTop)
		{
		throw "Error: iTop is nullptr";
		}

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Original Stack: " << std::endl;
	std::cout << "		Original Stack iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	CBlock* Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}
#endif

	CBlock* Head = iTop;
	CBlock* Prev = nullptr, * Next = nullptr;
	
#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Reversing using pointers: " <<  std::endl;
#endif

	iBottom = iTop;
	while (Head != nullptr)
		{
		Next = static_cast<CBlock*>(Head->NextItem());
		Head->SetPrevNext(Next,Prev);
		Prev = Head;
		Head = Next;
		}

	iTop = Prev;

#ifdef KLUKA_PRINT
	std::cout << std::endl << "		Reversed Stack: iTop -> iBottom " << std::endl;
	std::cout << "		Reversed Stack iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	Check_Stack = iTop;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->NextItem());
		}

	std::cout << std::endl << "		Reversed Stack: iBottom -> iTop " << std::endl;
	std::cout << "		Reversed Stack iCount: " << iCount << std::endl;
	std::cout << "		iTop: " << iTop->Value() << std::endl;
	std::cout << "		iBottom: " << iBottom->Value() << std::endl;

	Check_Stack = iBottom;
	while (Check_Stack != nullptr)
		{
		std::cout << "			Value: " << Check_Stack->Value() << std::endl;
		Check_Stack = static_cast<CBlock*>(Check_Stack->PrevItem());
		}

	std::cout << std::endl << "		Reverzuj was called successfully " << std::endl;
#endif

#ifndef NDEBUG
	IntegrityTest();
#endif

	return *this;
	}

/*	Function Reverzuj(aaa)
 *	author Prasek
 */
CStack Reverzuj(CStack aValue)
	{
	CStack result = aValue;
	return result.Reverzuj();
	}

/*	Stack Push
 *	authors Prasek, Pesek (with help of Petyovsky)
 */
CStack& CStack::Push(const CBlock& aValue)
	{
	if(!iCount)
		iTop = iBottom = new CBlock(aValue);
	else
		{
		CBlock *node = new CBlock(aValue.Value(), nullptr, iTop);
		iTop->SetPrevItem(node);
		iTop = node;
		}

	++iCount;
	return *this;
	}

/*	Stack Pop
 *	authors Prasek, Pesek
 *	using source code of Kluka - previous version was throwing error (deleted by pointers and not nullptr)
 */
CStack& CStack::Pop()
	{
	if (!iCount)
		{
		throw "Error: iCount is 0";
		}

	if (!iTop)
		{
		throw "Error: iTop is nullptr";
		}

	CBlock *iNode = iTop;
	if(iCount == 1)
		{
		iNode->SetPrevNext(nullptr, nullptr);
		iTop = iNode;
		iTop = nullptr;
		iBottom = nullptr;
		delete iNode;
		iCount = 0;
		}

	if(iCount > 1)
		{
		iNode = static_cast<CBlock *>(iNode->NextItem());
		iTop = iNode;
		iNode->PrevItem()->SetPrevNext(nullptr, nullptr);
		delete iNode->PrevItem();
		iNode->SetPrevItem(nullptr);
		--iCount;
		}

	return *this;
	}

/*	Stack Top
 *	authors Prasek, Pesek
 */
CBlock* CStack::Top() const
	{
	return iTop;
	}

/*	Stack Bottom
 *	author Majnus
 */

CBlock* CStack::Bottom() const
	{
	return iBottom;
	}

/*	Stack Search
 *	authors Prasek, Pesek
 *	fixed while cycle, just a little tweak - Kluka 
 */
bool CStack::Search(const CBlock &aValue) const
	{
	const CBlock *iCurrent = iTop;

	while(iCurrent != nullptr)
		{
		if(iCurrent->Value() == aValue.Value())	return true;
		iCurrent = static_cast<CBlock *>(iCurrent->NextItem());
		}

	return false;
	}
	
/*	Stack Dup
 *	authors	Prasek, Pesek
 */
CStack CStack::Dup() const
	{
	CStack Stack(*this);
	return Stack;
	}
