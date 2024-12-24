#include "../headers/Init.h"
#include "../headers/Player.h"

Player::Player(const PlayerType type, const PlayerColor color)
	: m_type(type)
	, m_color(color)
{
	createGobblers();
	initHand();
}

PlayerType Player::getType() const
{
	return m_type;
}

PlayerColor Player::getColor() const
{
	return m_color;
}

Gobbler* Player::getGobblerFromHand(size_t index) const
{
	if (index < NUM_OF_GOBBLERS)
	{
		return m_hand[index];
	}

	return nullptr;
}


void Player::setType(PlayerType type)
{
	m_type = type;
}

void Player::setColor(PlayerColor color)
{
	m_color = color;
}


void Player::removeGobblerFromHand(size_t index)
{
	if (index < NUM_OF_GOBBLERS)
	{
		m_hand[index] = nullptr;
	}
}

void Player::insertAllGobblersToHand()
{
	for (int i = 0; i < NUM_OF_GOBBLERS; ++i)
	{
		m_hand[i] = &m_gobblers[i];
	}
}


void Player::initHand()
{
	for (int i = 0; i < NUM_OF_GOBBLERS; ++i)
	{
		m_hand.push_back(nullptr);
	}
}

void Player::createGobblers()
{
	m_gobblers.push_back(Gobbler(m_color, SMALL));
	m_gobblers.push_back(Gobbler(m_color, SMALL));
	m_gobblers.push_back(Gobbler(m_color, MEDIUM));
	m_gobblers.push_back(Gobbler(m_color, MEDIUM));
	m_gobblers.push_back(Gobbler(m_color, LARGE));
	m_gobblers.push_back(Gobbler(m_color, LARGE));
}



