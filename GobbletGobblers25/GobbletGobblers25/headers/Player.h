#pragma once

#include <vector>
#include "../headers/Gobbler.h"
#include "../headers/enums.h"

class Player
{
public:
    /**
     * @brief Constructs a Player with a specified type and color.
     * @param type The type of the Player (PlayerType type).
     * @param color The color of the Player (PlayerColor type).
     */
    explicit Player(const PlayerType type, const PlayerColor color);

    /**
     * @brief Deleted copy constructor.
     * The Player object cannot be copied, ensuring no unexpected copies are made.
     */
    Player(const Player&) = delete;

    /**
     * @brief Default destructor.
     * Cleans up resources when the Player object is destroyed.
     */
    ~Player() = default;

    /**
     * @brief Gets the type of the Player.
     * @return The type of the Player (PlayerType type).
     */
    PlayerType getType() const;

    /**
     * @brief Gets the color of the Player.
     * @return The color of the Player (PlayerColor type).
     */
    PlayerColor getColor() const;

    /**
     * @brief Gets a pointer to a Gobbler in the Player's hand at the specified index.
     * @param index The index of the Gobbler in the Player's hand.
     * @return A pointer to the Gobbler at the given index in the hand.
     * @throws std::out_of_range If the index is out of bounds for the hand vector.
     */
    Gobbler* getGobblerFromHand(size_t index) const;

    /**
     * @brief Sets the type of the Player.
     * @param type The type to set for the Player (PlayerType type).
     */
    void setType(PlayerType type);

    /**
     * @brief Sets the color of the Player.
     * @param color The color to set for the Player (PlayerColor type).
     */
    void setColor(PlayerColor color);

    /**
     * @brief Removes a Gobbler from the Player's hand at the specified index.
     * @param index The index of the Gobbler to remove.
     * @throws std::out_of_range If the index is out of bounds for the hand vector.
     */
    void removeGobblerFromHand(size_t index);

    /**
     * @brief Inserts all Gobblers into the Player's hand.
     * This method ensures that all Gobblers are placed into the hand vector.
     */
    void insertAllGobblersToHand();

private:
    /**
     * @brief Initializes the hand of the Player.
     * Prepares the Player's hand with a certain number of Gobblers.
     */
    void initHand();

    /**
     * @brief Creates Gobblers for the Player.
     * Initializes the Gobblers that will be available for the Player's hand.
     */
    void createGobblers();

    /**
     * @brief Creates a specific number of Gobblers of a given size.
     * @param size: The size of the Gobblers to create (GobblerSize type).
     * @param numOfGobblers: The number of Gobblers to create of the specified size.
     *
     * This function creates and adds a specified number of Gobblers of a given size
     * to the Player's collection of Gobblers (m_gobblers).
     */
    void createGobblers(GobblerSize size, size_t numOfGobblers);

private:
    std::vector<Gobbler> m_gobblers; /**< The collection of all Gobblers available to the Player. */
    std::vector<Gobbler*> m_hand;    /**< The Player's hand containing pointers to Gobblers. */
    PlayerType m_type;               /**< The type of the Player (PlayerType type). */
    PlayerColor m_color;             /**< The color of the Player (PlayerColor type). */
};





