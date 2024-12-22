#pragma once
#include <vector>
#include "Gobbler.h"

enum PlayerType
{
	HUMAN,
	BOT
};


enum PlayerColor
{
	BLUE,
	RED,
	GREEN,
	ORANGE
};


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





