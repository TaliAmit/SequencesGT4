#include "catch.hpp"
#include "Piece.h"
#include "GG_Enums.h"

// Test Piece initialization
TEST_CASE("Piece Initialization", "[Piece][init]") {
    Piece<PlayerColor> piece(RED);
    REQUIRE(piece.getIdentifier() == RED);
}

// Test setting and getting Piece identifier
TEST_CASE("Set and Get Piece Identifier", "[Piece][set][get]") {
    Piece<PlayerColor> piece(RED);
    piece.setIdentifier(BLUE);
    REQUIRE(piece.getIdentifier() == BLUE);
}
