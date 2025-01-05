#include "Board.h"
#include "Init.h"

#include <cassert>


Board::Board(size_t row, size_t col)
    : m_rows(row)
    , m_cols(col)
    , m_cells(row, std::vector<Cell>(col))
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

size_t Board::getRows() const
{
    return m_rows;
}

size_t Board::getCols() const
{
    return m_cols;
}

void Board::validateIndices(size_t row, size_t col) const
{
    assert(row < m_rows && col < m_cols);
}