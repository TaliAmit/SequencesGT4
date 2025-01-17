#pragma once

#include "Piece.h"
#include "Enums.h"



class Gobbler: public Piece<PlayerColor>
{
public:
    /**
     * @brief Constructs a Gobbler with a specified color and size.
     * @param gobblerColor The color of the Gobbler (PlayerColor type).
     * @param gobblerSize The size of the Gobbler (GobblerSize type).
     */
    explicit Gobbler(PlayerColor gobblerColor, GobblerSize gobblerSize);
    /*:Piece<PlayerColor>(gobblerColor)
    , m_size(gobblerSize)
    {
    }*/

    /**
     * @brief Default copy constructor.
     * This is used when inserting the Gobbler into containers like std::vector or pushing onto std::stack.
     */
    Gobbler(const Gobbler&) = default;

    /**
     * @brief Default destructor.
     * Used for cleanup if necessary. No special destruction behavior is defined for this class.
     */
    ~Gobbler() = default;

    /**
     * @brief Gets the color of the Gobbler.
     * @return The current color of the Gobbler (PlayerColor type).
     */
    //PlayerColor getColor() const;

    /**
     * @brief Gets the size of the Gobbler.
     * @return The current size of the Gobbler (GobblerSize type).
     */
    GobblerSize getSize() const;

    /**
     * @brief Sets the color of the Gobbler.
     * @param gobblerColor The color to set for the Gobbler (PlayerColor type).
     */
    //void setColor(PlayerColor gobblerColor);

    /**
     * @brief Sets the size of the Gobbler.
     * This method is included for future use, though the size property is currently not being actively utilized.
     * @param gobblerSize The size to set for the Gobbler (GobblerSize type).
     */
    void setSize(GobblerSize gobblerSize);

private:
    //PlayerColor m_color; /**< The color of the Gobbler. */
    GobblerSize m_size;  /**< The size of the Gobbler. */
};



#include "Gobbler.inl"


