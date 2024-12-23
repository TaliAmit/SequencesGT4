#include "../headers/Cell.h"
#include <cassert>

Cell::Cell()
{

}

void Cell::addGobbler(Gobbler* gobbler)
{
	assert(gobbler != nullptr);
	m_gobblers.push(gobbler);
}

Gobbler* Cell::getTopGobbler() const
{
	if (!isEmpty())
	{
		return m_gobblers.top();
	}
	return nullptr;
}

void Cell::removeTopGobbler()
{
	assert(!isEmpty());
	m_gobblers.pop();
}

bool Cell::isEmpty() const
{
	return m_gobblers.empty();
}