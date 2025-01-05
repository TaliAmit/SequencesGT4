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
     * @brief Checks if there is a winner based on the last move made on the board.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return The color of the winner, or NONE if there is no winner.
     */
    PlayerColor checkWinner(size_t row, size_t col) const;

    /**
     * @brief Checks if there is a winner in the row of the last move.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return The color of the winner, or NONE if there is no winner in the row.
     */
    PlayerColor checkRowWinner(size_t row, size_t col) const;

    /**
     * @brief Checks if there is a winner in the column of the last move.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return The color of the winner, or NONE if there is no winner in the column.
     */
    PlayerColor checkColWinner(size_t row, size_t col) const;

    /**
     * @brief Checks if there is a winner in the main diagonal (top-left to bottom-right) if the last move is on this diagonal.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return The color of the winner, or NONE if there is no winner in the main diagonal.
     */
    PlayerColor checkMainDiagonalWinner(size_t row, size_t col) const;

    /**
     * @brief Checks if there is a winner in the anti-diagonal (top-right to bottom-left) if the last move is on this diagonal.
     * @param row The row index of the last move.
     * @param col The column index of the last move.
     * @return The color of the winner, or NONE if there is no winner in the anti-diagonal.
     */
    PlayerColor checkAntiDiagonalWinner(size_t row, size_t col) const;


private:
    const Board& m_board;
    const size_t m_rows;
    const size_t m_cols;
};

