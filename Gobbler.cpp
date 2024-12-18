#include "Gobbler.h"
#include "Player.h"

Gobbler::Gobbler(const PlayerColor gobblerColor, const GoblerSize gobblerSize, const int owner)
	: m_color(gobblerColor)
	, m_size(gobblerSize) 
	, m_owner(owner)
	, m_inHand(true)
{
}

PlayerColor Gobbler::getColor() const
{
	return m_color;
}

GoblerSize Gobbler::getSize() const
{
	return m_size;
}

int Gobbler::getOwner() const
{
	return m_owner;
}

bool Gobbler::getInHand() const
{
	return m_inHand;
}


void Gobbler::setColor(PlayerColor gobblerColor)
{
	m_color = gobblerColor;
}

void Gobbler::setSize(GoblerSize gobblerSize)
{
	m_size = gobblerSize;
}

void Gobbler::setOwner(int owner)
{
	m_owner = owner;
}

void Gobbler::setInHand(bool inHand)
{
	m_inHand = inHand;
}
