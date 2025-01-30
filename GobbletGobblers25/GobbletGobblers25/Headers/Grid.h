#pragma once

#include <vector>

template <typename T>
class Grid
{
public:
	explicit Grid(size_t row, size_t col);

	Grid(const Grid&) = delete;
	Grid& operator=(const Grid&) = delete;
	Grid& operator=(Grid&&) = delete;
	~Grid() = default;

	T& at(size_t row, size_t col);
	const T& at(size_t row, size_t col) const;
	//const T& getPiece(size_t row, size_t col) const;

	size_t getRows() const;
	size_t getCols() const;

private:
	void validateIndices(size_t rows, size_t cols) const;

private:
	size_t m_rows;
	size_t m_cols;

	std::vector<std::vector<T>> m_grid;
};

#include "../Details/Grid.inl"

