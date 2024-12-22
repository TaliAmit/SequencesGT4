#include "../headers/Player.h"

Player::Player(PlayerType type, PlayerColor color)
	: m_type(type)
	, m_color(color)
{
	// createGobblers();
	m_gobblers.push_back(Gobbler(m_color, SMALL));
	m_gobblers.push_back(Gobbler(m_color, SMALL));
	m_gobblers.push_back(Gobbler(m_color, MEDIUM));
	m_gobblers.push_back(Gobbler(m_color, MEDIUM));
	m_gobblers.push_back(Gobbler(m_color, LARGE));
	m_gobblers.push_back(Gobbler(m_color, LARGE));

	/*
	for (auto gobbler : m_gobblers)
	{
		m_hand.push_back(&gobbler);
	}
	*/
	


}

PlayerType Player::getType() const
{
	return m_type;
}

PlayerColor Player::getColor() const
{
	return m_color;
}

void Player::setType(const PlayerType type)
{
	m_type = type;
}

void Player::setColor(const PlayerColor color)
{
	m_color = color;
}

Gobbler* Player::getGobblerFromHand(Gobbler* gobbler)
{
	return nullptr;
}
