#include "catch.hpp"
#include "Gobbler.h"
#include "Enums.h"

// Test Gobbler initialization with color and size
TEST_CASE("Gobbler Initialization", "[Gobbler][init]") {
    Gobbler gobbler(RED, LARGE);
    REQUIRE(gobbler.getColor() == RED);
    REQUIRE(gobbler.getSize() == LARGE);
}

// Test getting the color of the Gobbler
TEST_CASE("Get Gobbler Color", "[Gobbler][get]") {
    Gobbler gobbler(BLUE, MEDIUM);
    REQUIRE(gobbler.getColor() == BLUE);
}

// Test getting the size of the Gobbler
TEST_CASE("Get Gobbler Size", "[Gobbler][get]") {
    Gobbler gobbler(GREEN, SMALL);
    REQUIRE(gobbler.getSize() == SMALL);
}

// Test setting a new color for the Gobbler
TEST_CASE("Set Gobbler Color", "[Gobbler][set]") {
    Gobbler gobbler(ORANGE, LARGE);
    gobbler.setColor(BLUE);
    REQUIRE(gobbler.getColor() == BLUE);
}

// Test setting a new size for the Gobbler
TEST_CASE("Set Gobbler Size", "[Gobbler][set]") {
    Gobbler gobbler(RED, MEDIUM);
    gobbler.setSize(SMALL);
    REQUIRE(gobbler.getSize() == SMALL);
}
