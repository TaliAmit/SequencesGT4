#include "Init.h"
#include "GGPlayer.h"

Gobbler* GGPlayer::getGobblerFromHand(size_t index) const
{
	if (index < GameConstants::GOBBLERS_PER_PLAYER)
	{
		return m_hand[index];
	}

	return nullptr;
}


void GGPlayer::removeGobblerFromHand(size_t index)
{
	if (index < GameConstants::GOBBLERS_PER_PLAYER)
	{
		m_hand[index] = nullptr;
	}
}

void GGPlayer::insertAllGobblersToHand()
{
	for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i)
	{
		m_hand[i] = &m_gobblers[i];
	}
}


void GGPlayer::initHand()
{
	for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i)
	{
		m_hand.push_back(nullptr);
	}
}

void GGPlayer::createGobblers()
{
	createGobblers(LARGE, GameConstants::LARGE_GOBBLERS);
	createGobblers(MEDIUM, GameConstants::MEDIUM_GOBBLERS);
	createGobblers(SMALL, GameConstants::SMALL_GOBBLERS);
}

void GGPlayer::createGobblers(GobblerSize size, size_t numOfGobblers)
{
	PlayerColor color = getIdentifier();
	
	for (size_t i = 0; i < numOfGobblers; ++i)
	{
		m_gobblers.push_back(Gobbler(color, size));
	}
}



