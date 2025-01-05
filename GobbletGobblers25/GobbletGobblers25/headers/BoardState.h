#pragma once

#include <vector>

/**
 * @brief Represents the state of a game board with rows, columns, and diagonals.
 *
 * This class manages the state of a board with a given number of rows and columns.
 * It allows for incrementing and decrementing counter values across rows, columns, and diagonals
 */
class BoardState
{
public:

    explicit BoardState(size_t numOfRows, size_t numOfCols);
    ~BoardState() = default;

    /**
     * @brief Increments the value at the specified (row, col) and all related elements.
     *
     * This function increments the value of the element at the specified row and column,
     * and also increments the corresponding values in the row, column, and diagonals that
     * contain this point.
     *
     * @param row The row index of the point to increment.
     * @param col The column index of the point to increment.
     */
    void incAll(size_t row, size_t col);

    /**
     * @brief Increment counter of a specified row.
     * @param row The index of the row to increment.
     */
    void incRow(size_t row);
    void incCol(size_t col);
    void incMainDiagonal(size_t row, size_t col);
    void incAntiDiagonal(size_t row, size_t col);


    void decAll(size_t row, size_t col);
    void decRow(size_t row);
    void decCol(size_t col);
    void decMainDiagonal(size_t row, size_t col);
    void decAntiDiagonal(size_t row, size_t col);

private:
    /**
     * @brief Calculates the index of the main diagonal containing the given (row, col).
     *
     * This function maps the coordinates of a point (row, col) to the corresponding index
     * in the main diagonal.
     *
     * @param row The row index of the point in the main diagonal.
     * @param col The column index of the point in the main diagonal.
     * @return The index of the main diagonal containing (row, col).
     */
    size_t pointToMainDiagonalIdx(size_t row, size_t col);
    size_t pointToAntiDiagonalIdx(size_t row, size_t col);

private:
    size_t m_numOfRows;                    ///< The number of rows in the board.
    size_t m_numOfCols;                    ///< The number of columns in the board.

    std::vector<size_t> m_rows;            ///< Stores a counter for each row.
    std::vector<size_t> m_cols;           
    std::vector<size_t> m_mainDiagonals;   
    std::vector<size_t> m_antiDiagonals;   
};

