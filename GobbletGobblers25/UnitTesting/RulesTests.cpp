#include "catch.hpp"
#include "Rules.h"
#include "Board.h"
#include "Cell.h"
#include "Gobbler.h"
#include "Player.h"
#include "Enums.h"

// Test canPlaceGobblerInCell (placing Gobbler in empty cell)
TEST_CASE("canPlaceGobblerInCell - Empty Cell", "[Rules][Gobbler][place]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    REQUIRE(rules.canPlaceGobblerInCell(&gobbler, 0, 0));
}

// Test canPlaceGobblerInCell (placing larger Gobbler on smaller Gobbler)
TEST_CASE("canPlaceGobblerInCell - Larger Gobbler on Smaller", "[Rules][Gobbler][place]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler smallGobbler(RED, SMALL);
    Gobbler largeGobbler(BLUE, LARGE);
    board.getCell(0, 0).addGobbler(&smallGobbler);
    REQUIRE(rules.canPlaceGobblerInCell(&largeGobbler, 0, 0));
}

// Test canPlaceGobblerInCell (placing smaller Gobbler on larger Gobbler)
TEST_CASE("canPlaceGobblerInCell - Smaller Gobbler on Larger", "[Rules][Gobbler][place]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler largeGobbler(RED, LARGE);
    Gobbler smallGobbler(BLUE, SMALL);
    board.getCell(0, 0).addGobbler(&largeGobbler);
    REQUIRE_FALSE(rules.canPlaceGobblerInCell(&smallGobbler, 0, 0));
}

// Test canPlaceGobblerInCell (placing Gobblers of the same size)
TEST_CASE("canPlaceGobblerInCell - Same Size Gobblers", "[Rules][Gobbler][place]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler1(RED, MEDIUM);
    Gobbler gobbler2(BLUE, MEDIUM);
    board.getCell(0, 0).addGobbler(&gobbler1);
    REQUIRE_FALSE(rules.canPlaceGobblerInCell(&gobbler2, 0, 0));
}

// Test canPlaceGobblerInCell (placing Gobbler in the same cell it was taken from)
TEST_CASE("canPlaceGobblerInCell - Same Cell", "[Rules][Gobbler][place]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    board.getCell(0, 0).addGobbler(&gobbler);
    REQUIRE_FALSE(rules.canPlaceGobblerInCell(&gobbler, 0, 0, 0, 0));
}

// Test canPlayerTakeGobbler
TEST_CASE("canPlayerTakeGobbler", "[Rules][player][take][Gobbler]") {
    Board board(3, 3);
    Rules rules(board);
    Player player(HUMAN, RED);
    Gobbler gobbler(RED, LARGE);
    REQUIRE(rules.canPlayerTakeGobbler(player, &gobbler));
}

// Test canPlayerTakeGobbler when player tries to take Gobbler of the wrong color
TEST_CASE("canPlayerTakeGobbler - Wrong Color", "[Rules][player][take][Gobbler]") {
    Board board(3, 3);
    Rules rules(board);
    Player player(HUMAN, RED);
    Gobbler gobbler(BLUE, LARGE);
    REQUIRE_FALSE(rules.canPlayerTakeGobbler(player, &gobbler));
}

// Test checkWinner when there is no winner
TEST_CASE("checkWinner - No Winner", "[Rules][winner][none]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler1(RED, LARGE);
    Gobbler gobbler2(BLUE, LARGE);
    board.getCell(0, 0).addGobbler(&gobbler1);
    board.getCell(0, 1).addGobbler(&gobbler2);
    board.getCell(0, 2).addGobbler(&gobbler1);
    REQUIRE(rules.checkWinner(0, 0) == NONE);
    REQUIRE(rules.checkWinner(0, 1) == NONE);
    REQUIRE(rules.checkWinner(0, 2) == NONE);
    REQUIRE(rules.checkWinner(1, 0) == NONE);
    REQUIRE(rules.checkWinner(1, 1) == NONE);
    REQUIRE(rules.checkWinner(1, 2) == NONE);
    REQUIRE(rules.checkWinner(2, 0) == NONE);
    REQUIRE(rules.checkWinner(2, 1) == NONE);
    REQUIRE(rules.checkWinner(2, 2) == NONE);
}

// Test checkWinner & checkRowWinner (row winner)
TEST_CASE("checkWinner - Row", "[Rules][winner][row]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    for (size_t col = 0; col < 3; ++col) {
        board.getCell(0, col).addGobbler(&gobbler);
    }
    REQUIRE(rules.checkWinner(0, 2) == RED);
    REQUIRE(rules.checkRowWinner(0, 0) == RED);
    REQUIRE(rules.checkRowWinner(0, 1) == RED);
    REQUIRE(rules.checkRowWinner(0, 2) == RED);
}

// Test checkWinner & checkColWinner (column winner)
TEST_CASE("checkWinner - Column", "[Rules][winner][column]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    for (size_t row = 0; row < 3; ++row) {
        board.getCell(row, 0).addGobbler(&gobbler);
    }
    REQUIRE(rules.checkWinner(2, 0) == RED);
    REQUIRE(rules.checkColWinner(0, 0) == RED);
    REQUIRE(rules.checkColWinner(1, 0) == RED);
    REQUIRE(rules.checkColWinner(2, 0) == RED);
}

// Test checkWinner & checkMainDiagonalWinner (main diagonal winner)
TEST_CASE("checkWinner - Main Diagonal", "[Rules][winner][main_diagonal]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    for (size_t i = 0; i < 3; ++i) {
        board.getCell(i, i).addGobbler(&gobbler);
    }
    REQUIRE(rules.checkWinner(2, 2) == RED);
    REQUIRE(rules.checkMainDiagonalWinner(0, 0) == RED);
    REQUIRE(rules.checkMainDiagonalWinner(1, 1) == RED);
    REQUIRE(rules.checkMainDiagonalWinner(2, 2) == RED);
}

// Test checkWinner & checkAntiDiagonalWinner (anti-diagonal winner)
TEST_CASE("checkWinner - Anti Diagonal", "[Rules][winner][anti_diagonal]") {
    Board board(3, 3);
    Rules rules(board);
    Gobbler gobbler(RED, LARGE);
    for (size_t i = 0; i < 3; ++i) {
        board.getCell(i, 2 - i).addGobbler(&gobbler);
    }
    REQUIRE(rules.checkWinner(2, 0) == RED);
    REQUIRE(rules.checkAntiDiagonalWinner(2, 0) == RED);
    REQUIRE(rules.checkAntiDiagonalWinner(1, 1) == RED);
    REQUIRE(rules.checkAntiDiagonalWinner(0, 2) == RED);
}
