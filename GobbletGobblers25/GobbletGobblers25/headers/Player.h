#pragma once

#include <vector>
#include "../headers/Gobbler.h"
#include "../headers/enums.h"

class Player
{
public:
	explicit Player(PlayerType type, PlayerColor color); ////???
	Player(const Player&) = delete; ///????
	~Player() = default; //????

	PlayerType getType() const;
	PlayerColor getColor() const;

	void setType(const PlayerType type);
	void setColor(const PlayerColor color);

	Gobbler* getGobblerFromHand(Gobbler* gobbler);
	void removeGobblerFromHand(Gobbler* gobbler);

private:
	void insertGobblerToHand(Gobbler* gobbler);


private:
	std::vector<Gobbler> m_gobblers;
	std::vector<Gobbler*> m_hand;
	PlayerType m_type;
	PlayerColor m_color;
};





