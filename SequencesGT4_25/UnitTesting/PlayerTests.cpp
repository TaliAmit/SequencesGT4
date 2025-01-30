#include "catch.hpp"
#include "GG_Player.h"
#include "GG_Enums.h"

// Test Player initialization
TEST_CASE("Player Initialization", "[Player][init]") {
    Player<PlayerColor> player(HUMAN, BLUE);
    REQUIRE(player.getType() == HUMAN);
    REQUIRE(player.getIdentifier() == BLUE);
}

// Test setting and getting Player type
TEST_CASE("Set and Get Player Type", "[Player][set][get]") {
    Player<PlayerColor> player(HUMAN, BLUE);
    player.setType(BOT);
    REQUIRE(player.getType() == BOT);
}

// Test setting and getting Player identifier
TEST_CASE("Set and Get Player Identifier", "[Player][set][get]") {
    Player<PlayerColor> player(HUMAN, BLUE);
    player.setIdentifier(RED);
    REQUIRE(player.getIdentifier() == RED);
}
