#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../headers/Gobbler.h"
#include "../headers/enums.h"



class Player
{
public:
	explicit Player(PlayerColor);
	Player(const Player&) = delete;
	~Player() = default;

	PlayerType getType() const;
	PlayerColor getColor() const;

	void setType(PlayerType type);
	void setColor(PlayerColor color);




private:
	std::vector<Gobbler> m_hand;
	PlayerType m_type;
	PlayerColor m_color;
};


#endif


