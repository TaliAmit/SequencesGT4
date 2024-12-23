#include "../headers/Board.h"

#include <cassert>

Board::Board(size_t rows, size_t cols)
    : m_cells(rows, std::vector<Cell>(cols)) 
{
}

Cell& Board::getCell(size_t row, size_t col)
{
    validateIndices(row, col);
    return m_cells[row][col];
}

void Board::validateIndices(size_t row, size_t col) const
{
    assert(row < m_cells.size() && col < m_cells[0].size());
}