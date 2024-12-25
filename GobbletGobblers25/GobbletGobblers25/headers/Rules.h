#pragma once

#include "Gobbler.h"
#include "Cell.h"
#include "Board.h"
#include "Player.h"

class Rules {
public:
    explicit Rules();
    Rules(const Rules&) = delete;
    Rules& operator=(const Rules&) = default;
    Rules(Rules&&) = delete;
    Rules& operator=(Rules&&) = delete;
    ~Rules() = default;

    /**
     * @brief Checks if a Gobbler can be placed in a specific cell.
     * @param gobbler A pointer to the Gobbler to be placed.
     * @param cell A reference to the Cell where the Gobbler is to be placed.
     * @return true if the Gobbler can be placed in the cell, false otherwise.
     */
    bool canPlaceGobblerInCell(const Gobbler* gobbler, const Cell& cell) const;

    /**
     * @brief Checks if a player can take a specific Gobbler.
     * @param player A reference to the Player attempting to take the Gobbler.
     * @param gobbler A pointer to the Gobbler that the player wants to take.
     * @return true if the player can take the Gobbler, false otherwise.
     */
    bool canPlayerTakeGobbler(const Player& player, const Gobbler* gobbler) const;

    /**
     * @brief Determines if there is a winner based on the current state of the board.
     * @param board A reference to the Board object representing the current game state.
     * @return true if there is a winner, false otherwise.
     */
    bool isWinner(const Board& board) const;

private:
    /**
     * @brief Checks if a specific row has a winner.
     * @param board The game board.
     * @param row The row index to check.
     * @return true if the row has a winner, false otherwise.
     */
    bool hasRowWinner(const Board& board, size_t row);

    /**
     * @brief Checks if a specific column has a winner.
     * @param board The game board.
     * @param col The column index to check.
     * @return true if the column has a winner, false otherwise.
     */
    bool hasColWinner(const Board& board, size_t col);

    /**
     * @brief Checks if either diagonal has a winner.
     * @param board The game board.
     * @return true if either diagonal has a winner, false otherwise.
     */
    bool hasDiagonalWinner(const Board& board);
};

