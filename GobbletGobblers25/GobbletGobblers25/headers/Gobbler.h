#pragma once

#include "../headers/enums.h"

class Gobbler
{
public:
	explicit Gobbler(const PlayerColor gobblerColor, const GobblerSize gobblerSize);

	Gobbler(const Gobbler&) = default; // std::vector::insert, std::stack::push
	~Gobbler() = default;

	PlayerColor getColor() const;
	GobblerSize getSize() const;

	void setColor(PlayerColor gobblerColor);
	void setSize(GobblerSize gobblerSize); // future use

private:
	PlayerColor m_color;
	GobblerSize m_size;
};



