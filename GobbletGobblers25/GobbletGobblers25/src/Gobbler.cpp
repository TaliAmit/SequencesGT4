#include "../headers/Gobbler.h"
#include "../headers/Player.h"

Gobbler::Gobbler(const PlayerColor gobblerColor, const GobblerSize gobblerSize)
	: m_color(gobblerColor)
	, m_size(gobblerSize)
{
}

PlayerColor Gobbler::getColor() const
{
	return m_color;
}

GobblerSize Gobbler::getSize() const
{
	return m_size;
}


void Gobbler::setColor(PlayerColor gobblerColor)
{
	m_color = gobblerColor;
}

void Gobbler::setSize(GobblerSize gobblerSize)
{
	m_size = gobblerSize;
}
