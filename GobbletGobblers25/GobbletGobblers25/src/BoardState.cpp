#pragma once

#include "../headers/BoardState.h"
//#include "../headers/Init.h"


BoardState::BoardState(size_t numOfRows, size_t numOfCols)
	: m_numOfRows(numOfRows)
	, m_numOfCols(numOfCols)
	, m_rows(numOfRows, 0)
	, m_cols(numOfCols, 0)
	, m_mainDiagonals(numOfRows + numOfCols + 1, 0)
	, m_antiDiagonals(numOfRows + numOfCols + 1, 0)
{
}

size_t BoardState::pointToMainDiagonalIdx(size_t row, size_t col)
{
	return row + m_numOfCols - col - 1;
}

size_t BoardState::pointToAntiDiagonalIdx(size_t row, size_t col)
{
	return row + col;
}

void BoardState::incAll(size_t row, size_t col)
{
	incRow(row);
	incCol(col);
	incMainDiagonal(row, col);
	incAntiDiagonal(row, col);
}

void BoardState::incRow(size_t row)
{
	++m_rows[row];
}

void BoardState::incCol(size_t col)
{
	++m_cols[col];
}

void BoardState::incMainDiagonal(size_t row, size_t col)
{
	++m_mainDiagonals[pointToMainDiagonalIdx(row, col)];
}

void BoardState::incAntiDiagonal(size_t row, size_t col)
{
	++m_antiDiagonals[pointToAntiDiagonalIdx(row, col)];
}

void BoardState::decAll(size_t row, size_t col)
{
	decRow(row);
	decCol(col);
	decMainDiagonal(row, col);
	decAntiDiagonal(row, col);
}

void BoardState::decRow(size_t row)
{
	if (m_rows[row] > 0)
	{
		--m_rows[row];
	}
}

void BoardState::decCol(size_t col)
{
	if (m_cols[col] > 0)
	{
		--m_cols[col];
	}
}

void BoardState::decMainDiagonal(size_t row, size_t col)
{
	size_t diagonalIdx = pointToMainDiagonalIdx(row, col);

	if (m_mainDiagonals[diagonalIdx] > 0)
	{
		--m_mainDiagonals[pointToMainDiagonalIdx(row, col)];
	}
}

void BoardState::decAntiDiagonal(size_t row, size_t col)
{
	size_t diagonalIdx = pointToAntiDiagonalIdx(row, col);

	if (m_antiDiagonals[diagonalIdx] > 0)
	{
		--m_antiDiagonals[pointToMainDiagonalIdx(row, col)];
	}
}

size_t BoardState::getRowCounter(size_t row)
{
	return m_rows[row];
}


size_t BoardState::getColCounter(size_t col)
{
	return m_cols[col];
}


size_t BoardState::getMainDiagonalCounter(size_t row, size_t col)
{
	size_t diagonalIdx = pointToMainDiagonalIdx(row, col);
	return m_mainDiagonals[diagonalIdx];
}

size_t BoardState::getAntiDiagonalCounter(size_t row, size_t col)
{
	size_t diagonalIdx = pointToAntiDiagonalIdx(row, col);
	return m_antiDiagonals[diagonalIdx];
}