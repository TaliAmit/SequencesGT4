#ifndef GOBBLER_H
#define GOBBLER_H

#include "../headers/enums.h"

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

#endif


