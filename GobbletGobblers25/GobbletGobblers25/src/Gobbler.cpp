#include "Gobbler.h"
#include "Player.h"

Gobbler::Gobbler(PlayerColor gobblerColor, GobblerSize gobblerSize)
:Piece<PlayerColor>(gobblerColor)
,m_size(gobblerSize)
{
}


GobblerSize Gobbler::getSize() const
{
	return m_size;
}


void Gobbler::setSize(GobblerSize gobblerSize)
{
	m_size = gobblerSize;
}


//PlayerColor Gobbler::getColor() const
//{
//	return m_color;
//}


//void Gobbler::setColor(PlayerColor gobblerColor)
//{
//	m_color = gobblerColor;
//}


