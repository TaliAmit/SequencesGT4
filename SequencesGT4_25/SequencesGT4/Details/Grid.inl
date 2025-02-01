#pragma once

#include <cassert> // assert
#include "Grid.h"
#include "Piece.h"

template<typename T>
inline Grid<T>::Grid(size_t rows, size_t cols)
	: m_rows(rows)
	, m_cols(cols)
	, m_grid(rows, std::vector<T>(cols))
{
}

template <typename T>
inline T& Grid<T>::at(size_t row, size_t col)
{
	validateIndices(row, col);
	return m_grid[row][col];
}

template<typename T>
inline const T& Grid<T>::at(size_t row, size_t col) const
{
	validateIndices(row, col);
	return m_grid[row][col];
}


//template<typename T>
//inline const T& Hand<T>::getPiece(size_t row, size_t col) const
//{
//	validateIndices(row, col);
//	return m_hand[row][col];
//}


template<typename T>
inline size_t Grid<T>::getRows() const
{
	return size_t();
}

template<typename T>
inline size_t Grid<T>::getCols() const
{
	return size_t();
}

template<typename T>
inline void Grid<T>::validateIndices(size_t rows, size_t cols) const
{
	assert(rows < m_rows && cols < m_cols);
}
