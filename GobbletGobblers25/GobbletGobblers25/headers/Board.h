#pragma once

#include "Cell.h"
#include <vector>

class Board
{
public:
	/**
	 * @brief Constructs a Board object with the specified number of rows and columns.
	 * @param rows The number of rows on the board. Default is 3.
	 * @param cols The number of columns on the board. Default is 3.
	 *
	 * @note The number of rows and columns must be positive.
	 */
	explicit Board(size_t rows = 3, size_t cols = 3);

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