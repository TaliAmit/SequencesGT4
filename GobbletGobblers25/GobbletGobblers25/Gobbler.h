#pragma once
#include "Player.h"

enum GoblerSize
{
	SMALL,
	MEDIUM,
	LARGE
};

class Gobbler
{
public:
	explicit Gobbler(const PlayerColor gobblerColor, const GoblerSize gobblerSize); 

	Gobbler(const Gobbler&) = delete;
	~Gobbler() = default;

	PlayerColor getColor() const;
	GoblerSize getSize() const;

	void setColor(PlayerColor gobblerColor); 
	void setSize(GoblerSize gobblerSize); // for future use (?)

private:
	PlayerColor m_color;
	GoblerSize m_size;
};



