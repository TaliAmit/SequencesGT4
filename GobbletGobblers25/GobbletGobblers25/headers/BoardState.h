#pragma once

#include <vector>

class BoardState
{
public:
    explicit BoardState();
    ~BoardState() = default;

    void incAll(size_t row, size_t col);
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
    std::vector<size_t> m_rows;            // by row
    std::vector<size_t> m_columns;         // by col
    std::vector<size_t> m_mainDiagonals;   // by row - col
    std::vector<size_t> m_antiDiagonals;   // by row + col
};
