#pragma once

#include "Piece.h"
#include "GG_Enums.h"


class Gobbler: public Piece<PlayerColor>
{
public:
    explicit Gobbler(PlayerColor gobblerColor, GobblerSize gobblerSize);

    Gobbler(const Gobbler&) = default;
    ~Gobbler() = default;

    GobblerSize getSize() const;
    void setSize(GobblerSize gobblerSize);

    //PlayerColor getColor() const;
    //void setColor(PlayerColor gobblerColor);


private:
    GobblerSize m_size;

    //PlayerColor m_color; /**< The color of the Gobbler. */
};


// #include "../Details/Gobbler.inl"

