#pragma once

#include "Gobbler.h"
#include "Cell.h"
#include "Board.h"
#include "GG_Player.h"
#include "GG_Enums.h"

class GGRules {
public:
    explicit GGRules(const Board& board);
    GGRules(const GGRules& a_other) = delete;
    GGRules& operator=(const GGRules&) = default;
    GGRules(GGRules&&) = delete;
    GGRules& operator=(GGRules&&) = delete;
    ~GGRules() = default;


    bool canPlaceGobblerInCell(const Gobbler* gobbler, size_t row, size_t col) const;
    bool canPlaceGobblerInCell(const Gobbler* gobbler, size_t fromRow, size_t fromCol, size_t toRow, size_t toCol) const;
    bool canPlayerTakeGobbler(const GGPlayer& player, const Gobbler* gobbler) const;
    PlayerColor checkWinner(size_t row, size_t col) const;
    PlayerColor checkRowWinner(size_t row, size_t col) const;
    PlayerColor checkColWinner(size_t row, size_t col) const;
    PlayerColor checkMainDiagonalWinner(size_t row, size_t col) const;
    PlayerColor checkAntiDiagonalWinner(size_t row, size_t col) const;


private:
    const Board& m_board;
    const size_t m_rows;
    const size_t m_cols;
};

