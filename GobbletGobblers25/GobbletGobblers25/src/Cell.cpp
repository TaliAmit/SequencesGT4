#include "../headers/Cell.h"


Cell::Cell()
{

}

bool Cell::addGobbler(Gobbler* gobbler)
{
	if (gobbler != nullptr)
	{
		m_gobblers.push(gobbler);
		return true;
	}
	return false;
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
	if (!isEmpty())
	{
		m_gobblers.pop();
	}
}

bool Cell::isEmpty() const
{
	return m_gobblers.empty();
}