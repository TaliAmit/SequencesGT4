#include "catch.hpp"
#include "Board.h"
#include "Cell.h"
#include "Gobbler.h"
#include "GG_Enums.h"

// Test Board initialization
TEST_CASE("Board Initialization", "[Board][get][init]") {
    size_t rows = 5;
    size_t cols = 5;
    Board board(rows, cols);
    REQUIRE(board.getRows() == rows);
    REQUIRE(board.getCols() == cols);
}


// Test cell emptiness after initialization
TEST_CASE("Cell Emptiness After Initialization", "[Board][Cell]") {
    Board board(3, 3);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            REQUIRE(board.getCell(i, j).isEmpty());
        }
    }
}


// Test setting and getting Cells in the Board
TEST_CASE("Set and Get Cell in Board", "[Board][set][get][Cell]") {
    size_t rows = 3;
    size_t cols = 3;
    Board board(rows, cols);
    Gobbler gobbler(RED, LARGE);
    board.getCell(1, 1).addGobbler(&gobbler);
    REQUIRE(board.getCell(1, 1).getTopGobbler() == &gobbler);
}


// Test const access to cells
TEST_CASE("Const Access to Cells", "[Board][get][Cell][const]") {
    const Board board(3, 3);

    REQUIRE_NOTHROW(board.getCell(1, 1));
    REQUIRE(board.getCell(1, 1).isEmpty());
}


// Test getRows
TEST_CASE("getRows", "[Board][getRows]") {
    Board board(7, 1);
    REQUIRE(board.getRows() == 7);
}


// Test getCols
TEST_CASE("getCols", "[Board][getCols]") {
    Board board(7, 1);
    REQUIRE(board.getCols() == 1);
}