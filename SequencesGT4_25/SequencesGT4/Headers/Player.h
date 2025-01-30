#pragma once

#include "Gobbler.h"
#include "GG_Enums.h"


template<typename T>
class Player
{
public:
    explicit Player(PlayerType playerType, T playerIdentfier);
    ~Player() = default;

    /**
     * @brief Gets the type of the Player.
     * @return The type of the Player (PlayerType type).
     */
    PlayerType getType() const;

    /**
     * @brief Sets the type of the Player.
     * @param type The type to set for the Player (PlayerType type).
     */
    void setType(PlayerType type);

    /**
     * @brief Gets the identifier of the Player.
     * @return The identifier of the Player (T type).
     */
    T getIdentifier() const;

    /**
     * @brief Sets the identifier of the Player.
     * @param identifier The identifier to set for the Player (T type).
     */
    void setIdentifier(T playerIdentifier);

private:
    PlayerType m_playerType; /**< The type of the Player (PlayerType type). */
    T m_playerIdentifier;    /**< The identifier of the Player (T type). */
};

#include "../Details/Player.inl"