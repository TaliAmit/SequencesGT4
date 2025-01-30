#include "GG_Rules.h"
#include "Init.h"
#include "Cell.h"

#include <cassert>

Rules::Rules(const Board& board)
: m_board{ board }
, m_rows{ m_board.getRows()}
, m_cols{ m_board.getCols()}
{
}

bool Rules::canPlaceGobblerInCell(const Gobbler* gobbler, size_t row, size_t col) const
{
    assert(gobbler != nullptr);
    
    const Cell& cell = m_board.getCell(row, col);
    if (cell.isEmpty()) 
    {
        return true;
    }
    const Gobbler* existingGobbler = cell.getTopGobbler();
    return gobbler->getSize() > existingGobbler->getSize();
}

bool Rules::canPlaceGobblerInCell(const Gobbler* gobbler, size_t fromRow, size_t fromCol, size_t toRow, size_t toCol) const
{
    if (fromRow == toRow && fromCol == toCol)
    {
        return false;
    }

    return canPlaceGobblerInCell(gobbler, toRow, toCol);
}


bool Rules::canPlayerTakeGobbler(const GGPlayer& player, const Gobbler* gobbler) const
{
    assert(gobbler != nullptr);
    return player.getIdentifier() == gobbler->getIdentifier();
}

// should change to player identifier
PlayerColor Rules::checkWinner(size_t row, size_t col) const 
{
    PlayerColor winner = checkRowWinner(row, col);
    if (winner != NONE)
    {
        return winner;
    }

    winner = checkColWinner(row, col);
    if (winner != NONE)
    {
        return winner;
    }

    winner = checkMainDiagonalWinner(row, col);
    if (winner != NONE)
    {
        return winner;
    }

    winner = checkAntiDiagonalWinner(row, col);
    return winner;
}



PlayerColor Rules::checkRowWinner(size_t row, size_t col) const
{
    assert(row < m_rows && col < m_cols);
    
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getIdentifier();

    for (size_t checkCol = col + 1; checkCol < m_cols; ++checkCol)
    {
        currentGobbler = m_board.getCell(row, checkCol).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (size_t checkCol = col; checkCol > 0; --checkCol)
    {
        currentGobbler = m_board.getCell(row, checkCol - 1).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (count >= GameConstants::WINNING_STREAK)
    {
        return possibleWinnerColor;
    }
    else
    {
        return NONE;
    }
}


PlayerColor Rules::checkColWinner(size_t row, size_t col) const
{
    assert(row < m_rows && col < m_cols);
    
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getIdentifier();

    for (size_t checkRow = row + 1; checkRow < m_rows; ++checkRow)
    {
        currentGobbler = m_board.getCell(checkRow, col).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (size_t checkRow = row; checkRow > 0; --checkRow)
    {
        currentGobbler = m_board.getCell(checkRow - 1, col).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (count >= GameConstants::WINNING_STREAK)
    {
        return possibleWinnerColor;
    }
    else
    {
        return NONE;
    }
}

PlayerColor Rules::checkMainDiagonalWinner(size_t row, size_t col) const
{
    assert(row < m_rows && col < m_cols);
    
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getIdentifier();

    for (size_t i = 1; row + i < m_rows && col + i < m_cols; ++i)
    {
        currentGobbler = m_board.getCell(row + i, col + i).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (size_t i = 0; row - i > 0 && col - i > 0; ++i)
    {
        currentGobbler = m_board.getCell(row - i - 1, col - i - 1).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (count >= GameConstants::WINNING_STREAK)
    {
        return possibleWinnerColor;
    }
    else
    {
        return NONE;
    }
}

PlayerColor Rules::checkAntiDiagonalWinner(size_t row, size_t col) const
{
    assert(row < m_rows && col < m_cols);
    
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getIdentifier();

    for (size_t i = 1; row - i + 1 > 0 && col + i < m_cols; ++i)
    {
        currentGobbler = m_board.getCell(row - i, col + i).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

   for (size_t i = 1; row + i < m_rows && col - i + 1 > 0; --i)
    {
        currentGobbler = m_board.getCell(row + i, col - i).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getIdentifier() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (count >= GameConstants::WINNING_STREAK)
    {
        return possibleWinnerColor;
    }
    else
    {
        return NONE;
    }
}