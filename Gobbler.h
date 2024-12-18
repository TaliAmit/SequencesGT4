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
	explicit Gobbler(const PlayerColor gobblerColor, const GoblerSize gobblerSize, const int owner);
	Gobbler(const Gobbler&) = delete;
	~Gobbler() = default;

	PlayerColor getColor() const;
	GoblerSize getSize() const;
	int getOwner() const;
	bool getInHand() const;

	void setColor(PlayerColor gobblerColor); 
	void setSize(GoblerSize gobblerSize); // for future use (?)
	void setOwner(int owner); // for future use (?)
	void setInHand(bool inHand);

private:
	PlayerColor m_color;
	GoblerSize m_size;
	int m_owner;
	bool m_inHand;
};



