#include "Gobbler.h"
#include "Player.h"

//Gobbler::Gobbler(PlayerColor gobblerColor, GobblerSize gobblerSize)
//:Piece<PlayerColor>(gobblerColor)
//,m_size(gobblerSize)
//{
//}

//PlayerColor Gobbler::getColor() const
//{
//	return m_color;
//}

GobblerSize Gobbler::getSize() const
{
	return m_size;
}


//void Gobbler::setColor(PlayerColor gobblerColor)
//{
//	m_color = gobblerColor;
//}

void Gobbler::setSize(GobblerSize gobblerSize)
{
	m_size = gobblerSize;
}
