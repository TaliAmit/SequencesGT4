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
    /**
    * @brief Constructs a BoardState with the specified dimensions.
    * @param numOfRows The number of rows in the board.
    * @param numOfCols The number of columns in the board.
    */
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
     * @note This function performs an assertion to ensure the indices are within bounds.
     *       Make sure to use this function only with valid indices.
     */
    void incAll(size_t row, size_t col);
    void incRow(size_t row);
    void incCol(size_t col);
    void incMainDiagonal(size_t row, size_t col);
    void incAntiDiagonal(size_t row, size_t col);

    /**
     * @brief Decrements the value at the specified (row, col) and all related elements.
     *
     * This function decrements the value of the element at the specified row and column,
     * and also decrements the corresponding values in the row, column, and diagonals that
     * contain this point.
     *
     * @param row The row index of the point to decrement.
     * @param col The column index of the point to decrement.
     * @note This function performs an assertion to ensure the indices are within bounds.
     *       Make sure to use this function only with valid indices.
     */
    void decAll(size_t row, size_t col);
    void decRow(size_t row);
    void decCol(size_t col);
    void decMainDiagonal(size_t row, size_t col);
    void decAntiDiagonal(size_t row, size_t col);

    /**
     * @brief Get the counter value for a specified row.
     * @param row The index of the row.
     * @return The counter value for the specified row.
     * @note This function performs an assertion to ensure the index is within bounds.
     *       Make sure to use this function only with valid indices.
     */
    size_t getRowCounter(size_t row);

    /**
     * @brief Get the counter value for a specified column.
     * @param col The index of the column.
     * @return The counter value for the specified column.
     * @note This function performs an assertion to ensure the index is within bounds.
     *       Make sure to use this function only with valid indices.
     */
    size_t getColCounter(size_t col);

    /**
     * @brief Get the counter value for the main diagonal containing the specified point.
     * @param row The row index of the point.
     * @param col The column index of the point.
     * @return The counter value for the main diagonal containing the specified point.
     * @note This function performs an assertion to ensure the indices are within bounds.
     *       Make sure to use this function only with valid indices.
     */
    size_t getMainDiagonalCounter(size_t row, size_t col);

    /**
     * @brief Get the counter value for the anti-diagonal containing the specified point.
     * @param row The row index of the point.
     * @param col The column index of the point.
     * @return The counter value for the anti-diagonal containing the specified point.
     * @note This function performs an assertion to ensure the indices are within bounds.
     *       Make sure to use this function only with valid indices.
     */
    size_t getAntiDiagonalCounter(size_t row, size_t col);

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
    std::vector<size_t> m_cols;            ///< Stores a counter for each column.
    std::vector<size_t> m_mainDiagonals;   ///< Stores a counter for each main diagonal.
    std::vector<size_t> m_antiDiagonals;   ///< Stores a counter for each anti-diagonal. 
};

