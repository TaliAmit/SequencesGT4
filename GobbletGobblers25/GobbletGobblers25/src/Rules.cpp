#include "../headers/Rules.h"
#include "../headers/Init.h"
#include "../headers/Cell.h"

#include <cassert>

Rules::Rules(const Board& board)
: m_board{ board }
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


bool Rules::canPlayerTakeGobbler(const Player& player, const Gobbler* gobbler) const
{
    assert(gobbler != nullptr);
    return player.getColor() == gobbler->getColor();
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
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    assert(row < m_board.getRows() && col < m_board.getCols());

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getColor();

    for (size_t checkCol = col + 1; checkCol < m_board.getCols(); ++checkCol)
    {
        currentGobbler = m_board.getCell(row, checkCol).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (col > 0)
    {
        for (size_t checkCol = col; checkCol > 0; --checkCol)
        {
            currentGobbler = m_board.getCell(row, checkCol - 1).getTopGobbler();

            if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
            {
                count++;
            }
            else
            {
                break;
            }
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
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    assert(row < m_board.getRows() && col < m_board.getCols());

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getColor();

    for (size_t checkRow = row + 1; checkRow < m_board.getRows(); ++checkRow)
    {
        currentGobbler = m_board.getCell(checkRow, col).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (row > 0)
    {
        for (size_t checkRow = row; checkRow > 0; --checkRow)
        {
            currentGobbler = m_board.getCell(checkRow - 1, col).getTopGobbler();

            if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
            {
                count++;
            }
            else
            {
                break;
            }
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
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    assert(row < m_board.getRows() && col < m_board.getCols());

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getColor();

    for (size_t i = 1; row + i < m_board.getRows() && col + i < m_board.getCols(); ++i)
    {
        currentGobbler = m_board.getCell(row + i, col + i).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (row > 0 && col > 0)
    {
        for (size_t i = 0; row - i > 0 && col - i > 0; --i)
        {
            currentGobbler = m_board.getCell(row - i - 1, col - i - 1).getTopGobbler();

            if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
            {
                count++;
            }
            else
            {
                break;
            }
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
    size_t count = 1;
    Gobbler* currentGobbler = m_board.getCell(row, col).getTopGobbler();

    assert(row < m_board.getRows() && col < m_board.getCols());

    if (currentGobbler == nullptr)
    {
        return NONE;
    }

    PlayerColor possibleWinnerColor = currentGobbler->getColor();

    for (size_t i = 1; row - i + 1 > 0 && col + i < m_board.getCols(); ++i)
    {
        currentGobbler = m_board.getCell(row - i, col + i).getTopGobbler();

        if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    if (row > 0 && col > 0)
    {
        for (size_t i = 1; row + i < m_board.getRows() && col - i + 1 > 0; --i)
        {
            currentGobbler = m_board.getCell(row + i, col - i).getTopGobbler();

            if (currentGobbler != nullptr && currentGobbler->getColor() == possibleWinnerColor)
            {
                count++;
            }
            else
            {
                break;
            }
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