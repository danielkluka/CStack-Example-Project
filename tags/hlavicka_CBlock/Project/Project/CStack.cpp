/** \file CStack.cpp
 *  \brief CStack class source
 *  \details File contains implementation of CStack support functions
 *  \authors Kluka, Majnus, Pesek, Prasek
 *  \version 2022
 *	\attention File CStack.cpp is in very early stage of development.
 *  $Id: CStack.cpp 2227 2022-12-04 10:32:33Z xpesek13 $
 */

#include <cstring>
#include "CStack.h"

/*
bool CStack::CompareDeep(const CStack &aStack) const
	{
	return;
	// TODO: insert return statement here
	}
*/

int CStack::Compare(const CStack& aStack) const
{
	if (this->Actual() > aStack.Actual())
	{
		return 1;
	}
	else if (this->Actual() < aStack.Actual())
	{
		return -1;
	}
	else if (this->Actual() == aStack.Actual())
	{
		return 0;
	}
}

/*
CStack &CStack::operator++() const
	{
	return;
	// TODO: insert return statement here
	}
*/

/*
CStack CStack::operator+(const CStack& aStack) const
	{
	return;
	// TODO: insert return statement here
	}
*/

/*
CStack operator+(const CBlock& aBlock, const CStack& aStack)
	{
	return;
	// TODO: insert return statement here
	}
*/

/*
CStack& CStack::operator-() const
	{
	// TODO: insert return statement here
	}
*/

/*
CStack& CStack::operator+=(const CStack& aStack)
	{
	// TODO: insert return statement here
	}
*/

/*
CStack &CStack::operator-(const CStack &aStack) const
	{
	// TODO: insert return statement here
	}
*/

/*
CStack &CStack::operator+=(const CStack &aStack)
	{
	// TODO: insert return statement here
	}
*/

/*
CStack CStack::operator-(const CStack &aStack) const
	{
	return CStack();
	// TODO: insert return statement here
	}
*/

/*
CStack &CStack::operator+=(const CStack &aStack)
	{
	// TODO: insert return statement here
	}
*/

CStack& CStack::Push(const CBlock &aValue)
	{
	CBlock *node = new CBlock(aValue);

	node->SetValue(aValue.Value());
	node->SetNextItem(nullptr);
	node->SetPrevItem(this->iTop);

	this->iTop = node;

	node->SetPrevItem(nullptr);
	delete(node);

	return *this;
	}

 /*
CStack& CStack::Pop()
	{
	return CStack();
	// TODO: insert return statement here
	}
*/

/*
CStack CStack::Top(CBlock* aTop)
	{
	return CStack();
	// TODO: insert return statement here
	}
*/

/*
CStack CStack::Dup(CStack* aStack)
	{
	return CStack();
	// TODO: insert return statement here
	}
*/