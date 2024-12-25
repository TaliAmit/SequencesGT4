#include "../headers/Board.h"
#include "../headers/Init.h"

#include <cassert>


Board::Board()
: m_cells(GameConstants::BOARD_ROWS, std::vector<Cell>(GameConstants::BOARD_COLS))
{
}

Cell& Board::getCell(size_t row, size_t col)
{
    validateIndices(row, col);
    return m_cells[row][col];
}

const Cell& Board::getCell(size_t row, size_t col) const
{
    return m_cells[row][col];
}

void Board::validateIndices(size_t row, size_t col) const
{
    assert(row < GameConstants::BOARD_ROWS && col < GameConstants::BOARD_COLS);
}