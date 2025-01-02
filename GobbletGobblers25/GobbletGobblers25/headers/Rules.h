#pragma once

#include "Gobbler.h"
#include "Cell.h"
#include "Board.h"
#include "Player.h"
#include "Enums.h"

class Rules {
public:
    explicit Rules(const Board& board);
    Rules(const Rules&) = delete;
    Rules& operator=(const Rules&) = default;
    Rules(Rules&&) = delete;
    Rules& operator=(Rules&&) = delete;
    ~Rules() = default;

    /**
 * @brief Checks if it is allowed to place a gobbler in a specific cell on the board when it arrives from outside the board.
 * @param gobbler A pointer to the gobbler to be placed.
 * @param row The row number where the gobbler is to be placed.
 * @param col The column number where the gobbler is to be placed.
 * @return true if placing the gobbler in the specified cell is allowed; otherwise, false.
 */
    bool canPlaceGobblerInCell(const Gobbler* gobbler, size_t row, size_t col) const;

    /**
     * @brief Checks if it is allowed to move a gobbler from one location to another on the board.
     * @param gobbler A pointer to the gobbler being moved.
     * @param fromRow The row number from which the gobbler is being moved.
     * @param fromCol The column number from which the gobbler is being moved.
     * @param toRow The row number to which the gobbler is being moved.
     * @param toCol The column number to which the gobbler is being moved.
     * @return true if moving the gobbler to the specified cell is allowed; otherwise, false.
     */
    bool canPlaceGobblerInCell(const Gobbler* gobbler, size_t fromRow, size_t fromCol, size_t toRow, size_t toCol) const;

    /**
     * @brief Checks if a player can take a specific Gobbler.
     * @param player A reference to the Player attempting to take the Gobbler.
     * @param gobbler A pointer to the Gobbler that the player wants to take.
     * @return true if the player can take the Gobbler, false otherwise.
     */
    bool canPlayerTakeGobbler(const Player& player, const Gobbler* gobbler) const;

    /**
     * @brief Checks if there is a winner based on the current state of the board.
     * @param board A reference to the Board object representing the current game state.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return An optional containing the color of the winner, or std::nullopt if there is no winner.
     */
    PlayerColor checkWinner(size_t row, size_t col) const;

private:
    const Board& m_board;


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

