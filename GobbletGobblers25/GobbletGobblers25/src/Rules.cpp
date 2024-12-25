#include "../headers/Rules.h"
#include "../headers/Init.h"
#include "../headers/Cell.h"

#include <cassert>

Rules::Rules()
{
}

bool Rules::canPlaceGobblerInCell(const Gobbler* gobbler, const Cell& cell) const
{
    assert(gobbler != nullptr);
    if (cell.isEmpty())
    {
        return true;
    }
    const Gobbler* existingGobbler = cell.getTopGobbler();
    return gobbler->getSize() > existingGobbler->getSize();
}


bool Rules::canPlayerTakeGobbler(const Player& player, const Gobbler* gobbler) const
{
    assert(gobbler != nullptr);
    return player.getColor() == gobbler->getColor();
}


bool Rules::isWinner(const Board& board) const
{

}


bool Rules::hasRowWinner(const Board& board, size_t row)
{
    size_t count = 0;
    Gobbler* previousGobbler = nullptr;

    for (size_t col = 0; col < GameConstants::BOARD_COLS; ++col)
    {
        Gobbler* currentGobbler = board.getCell(row, col).getTopGobbler();

        if (currentGobbler != nullptr) {
            if (currentGobbler == previousGobbler)
            {
                count++;
            }
            else
            {
                count = 1;
                previousGobbler = currentGobbler;
            }
        }
        else
        {
            count = 0;
            previousGobbler = nullptr;
        }

        if (count >= GameConstants::WINNING_STREAK)
        {
            return true;
        }
    }
    return false;
}


bool Rules::hasColWinner(const Board& board, size_t col)
{
    size_t count = 0;
    Gobbler* previousGobbler = nullptr;

    for (size_t row = 0; row < GameConstants::BOARD_ROWS; ++row)
    {
        Gobbler* currentGobbler = board.getCell(row, col).getTopGobbler();

        if (currentGobbler != nullptr) {
            if (currentGobbler == previousGobbler)
            {
                count++;
            }
            else
            {
                count = 1;
                previousGobbler = currentGobbler;
            }
        }
        else
        {
            count = 0;
            previousGobbler = nullptr;
        }

        if (count >= GameConstants::WINNING_STREAK)
        {
            return true;
        }
    }
    return false;
}


bool Rules::hasDiagonalWinner(const Board& board)
{

}