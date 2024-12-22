#pragma once

#include <vector>
#include "../headers/Gobbler.h"
#include "../headers/enums.h"

class Player
{
public:
	explicit Player(const PlayerType type, const PlayerColor color);
	Player(const Player&) = delete;
	~Player() = default;

	PlayerType getType() const;
	PlayerColor getColor() const;
	Gobbler* getGobblerFromHand(int index) const;

	void setType(const PlayerType type);
	void setColor(const PlayerColor color);

	void removeGobblerFromHand(int index);
	void insertAllGobblersToHand();

private:
	void initHand();
	void createGobblers();

private:
	std::vector<Gobbler> m_gobblers;
	std::vector<Gobbler*> m_hand;
	PlayerType m_type;
	PlayerColor m_color;
};





