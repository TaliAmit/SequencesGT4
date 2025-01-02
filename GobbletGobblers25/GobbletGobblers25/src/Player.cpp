#include "../headers/Init.h"
#include "../headers/Player.h"

Player::Player(PlayerType type, PlayerColor color)
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
	if (index < GameConstants::GOBBLERS_PER_PLAYER)
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
	if (index < GameConstants::GOBBLERS_PER_PLAYER)
	{
		m_hand[index] = nullptr;
	}
}

void Player::insertAllGobblersToHand()
{
	for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i)
	{
		m_hand[i] = &m_gobblers[i];
	}
}


void Player::initHand()
{
	for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i)
	{
		m_hand.push_back(nullptr);
	}
}

void Player::createGobblers()
{
	createGobblers(LARGE, GameConstants::LARGE_GOBBLERS);
	createGobblers(MEDIUM, GameConstants::MEDIUM_GOBBLERS);
	createGobblers(SMALL, GameConstants::SMALL_GOBBLERS);
}

void Player::createGobblers(GobblerSize size, size_t numOfGobblers)
{
	for (size_t i = 0; i < numOfGobblers; ++i)
	{
		m_gobblers.push_back(Gobbler(m_color, size));
	}
}



