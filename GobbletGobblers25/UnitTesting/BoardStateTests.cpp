#include "catch.hpp"
#include "BoardState.h"

// Test initialization of the BoardState class
TEST_CASE("BoardState Initialization", "[BoardState][init]") {
    BoardState boardState(3, 3);
    REQUIRE(boardState.getRowCounter(0) == 0);
    REQUIRE(boardState.getColCounter(0) == 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 2) == 0);
}

// Test the incAll function
TEST_CASE("BoardState Increment All", "[BoardState][increment][all]") {
    BoardState boardState(3, 3);
    boardState.incAll(0, 0);
    REQUIRE(boardState.getRowCounter(0) == 1);
    REQUIRE(boardState.getColCounter(0) == 1);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 1);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 1);
}

// Test the decAll function
TEST_CASE("BoardState Decrement All", "[BoardState][decrement][all]") {
    BoardState boardState(3, 3);
    boardState.incAll(0, 0);
    boardState.decAll(0, 0);
    REQUIRE(boardState.getRowCounter(0) == 0);
    REQUIRE(boardState.getColCounter(0) == 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 0);
}

// Test the incRow function
TEST_CASE("BoardState Increment Row", "[BoardState][increment][row]") {
    BoardState boardState(3, 3);
    boardState.incRow(0);
    REQUIRE(boardState.getRowCounter(0) == 1);
}

// Test the decRow function
TEST_CASE("BoardState Decrement Row", "[BoardState][decrement][row]") {
    BoardState boardState(3, 3);
    boardState.incRow(0);
    boardState.decRow(0);
    REQUIRE(boardState.getRowCounter(0) == 0);
}

// Test the incCol function
TEST_CASE("BoardState Increment Column", "[BoardState][increment][column]") {
    BoardState boardState(3, 3);
    boardState.incCol(0);
    REQUIRE(boardState.getColCounter(0) == 1);
}

// Test the decCol function
TEST_CASE("BoardState Decrement Column", "[BoardState][decrement][column]") {
    BoardState boardState(3, 3);
    boardState.incCol(0);
    boardState.decCol(0);
    REQUIRE(boardState.getColCounter(0) == 0);
}

// Test the incMainDiagonal function
TEST_CASE("BoardState Increment Main Diagonal", "[BoardState][increment][mainDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incMainDiagonal(0, 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 1);
}

// Test the decMainDiagonal function
TEST_CASE("BoardState Decrement Main Diagonal", "[BoardState][decrement][mainDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incMainDiagonal(0, 0);
    boardState.decMainDiagonal(0, 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 0);
}

// Test the incAntiDiagonal function
TEST_CASE("BoardState Increment Anti Diagonal", "[BoardState][increment][antiDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incAntiDiagonal(0, 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 1);
}

// Test the decAntiDiagonal function
TEST_CASE("BoardState Decrement Anti Diagonal", "[BoardState][decrement][antiDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incAntiDiagonal(0, 0);
    boardState.decAntiDiagonal(0, 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 0);
}

// Specific tests for get functions
TEST_CASE("BoardState Get Row Counter", "[BoardState][get][row]") {
    BoardState boardState(3, 3);
    boardState.incRow(0);
    REQUIRE(boardState.getRowCounter(0) == 1);
    boardState.decRow(0);
    REQUIRE(boardState.getRowCounter(0) == 0);
}

TEST_CASE("BoardState Get Column Counter", "[BoardState][get][column]") {
    BoardState boardState(3, 3);
    boardState.incCol(0);
    REQUIRE(boardState.getColCounter(0) == 1);
    boardState.decCol(0);
    REQUIRE(boardState.getColCounter(0) == 0);
}

TEST_CASE("BoardState Get Main Diagonal Counter", "[BoardState][get][mainDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incMainDiagonal(0, 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 1);
    boardState.decMainDiagonal(0, 0);
    REQUIRE(boardState.getMainDiagonalCounter(0, 0) == 0);
}

TEST_CASE("BoardState Get Anti Diagonal Counter", "[BoardState][get][antiDiagonal]") {
    BoardState boardState(3, 3);
    boardState.incAntiDiagonal(0, 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 1);
    boardState.decAntiDiagonal(0, 0);
    REQUIRE(boardState.getAntiDiagonalCounter(0, 0) == 0);
}
