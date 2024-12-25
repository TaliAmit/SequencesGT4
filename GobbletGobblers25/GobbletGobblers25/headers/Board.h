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
	 *
	 * This function retrieves a reference to the cell located at the specified
	 * row and column indices in the board. The non-const version allows for
	 * modification of the cell's contents.
	 *
	 * @param row The row index of the cell. Must be within the bounds of the board.
	 * @param col The column index of the cell. Must be within the bounds of the board.
	 * @return A reference to the requested cell.
	 *
	 * @note This function performs an assertion to ensure the indices are within bounds.
	 *       Make sure to use this function only with valid indices.
	*/
	Cell& getCell(size_t row, size_t col);

	/**
	 * @brief Retrieves a reference to the cell at the specified row and column (const version).
	 *
	 * This function retrieves a reference to the cell located at the specified
	 * row and column indices in the board. The const version does not allow for
	 * modification of the cell's contents and is intended for use with const objects.
	 *
	 * @param row The row index of the cell. Must be within the bounds of the board.
	 * @param col The column index of the cell. Must be within the bounds of the board.
	 * @return A const reference to the requested cell.
	 *
	 * @note This function performs an assertion to ensure the indices are within bounds.
	 *       Make sure to use this function only with valid indices.
	 */
	const Cell& getCell(size_t row, size_t col) const;


private:
	void validateIndices(size_t row, size_t col) const;
	std::vector<std::vector<Cell>> m_cells;
};