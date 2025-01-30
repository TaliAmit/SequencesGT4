#include "catch.hpp"
#include "Gobbler.h"
#include "GG_Enums.h"

// Test Gobbler initialization with color and size (inherits from Piece)
TEST_CASE("Gobbler Initialization", "[Gobbler][init]") {
    Gobbler gobbler(RED, LARGE);
    REQUIRE(gobbler.getIdentifier() == RED);
    REQUIRE(gobbler.getSize() == LARGE);
}

// Test getting the color of the Gobbler (inherits from Piece)
TEST_CASE("Get Gobbler Color", "[Gobbler][get]") {
    Gobbler gobbler(BLUE, MEDIUM);
    REQUIRE(gobbler.getIdentifier() == BLUE);
}

// Test getting the size of the Gobbler
TEST_CASE("Get Gobbler Size", "[Gobbler][get]") {
    Gobbler gobbler(GREEN, SMALL);
    REQUIRE(gobbler.getSize() == SMALL);
}

// Test setting a new color for the Gobbler (inherits from Piece)
TEST_CASE("Set Gobbler Color", "[Gobbler][set]") {
    Gobbler gobbler(ORANGE, LARGE);
    gobbler.setIdentifier(BLUE);
    REQUIRE(gobbler.getIdentifier() == BLUE);
}

// Test setting a new size for the Gobbler
TEST_CASE("Set Gobbler Size", "[Gobbler][set]") {
    Gobbler gobbler(RED, MEDIUM);
    gobbler.setSize(SMALL);
    REQUIRE(gobbler.getSize() == SMALL);
}
