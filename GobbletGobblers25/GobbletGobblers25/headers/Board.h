#pragma once

#include "Cell.h"
#include <vector>

class Board
{
public:
	explicit Board();

	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	Board& operator=(Board&&) = delete;
	~Board() = default;

	/**
	* @brief Retrieves a reference to the cell at the specified row and column.
	* @param row The row index of the cell.
	* @param col The column index of the cell.
	* @return A reference to the requested cell.
	*
	* @note This function performs an assertion to ensure the indices are within bounds.
	*       Make sure to use this function only with valid indices.
	*/
	Cell& getCell(size_t row, size_t col);

private:
	void validateIndices(size_t row, size_t col) const;
	std::vector<std::vector<Cell>> m_cells;
};