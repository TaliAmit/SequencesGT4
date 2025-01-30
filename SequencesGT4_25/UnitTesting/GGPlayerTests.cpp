#include "catch.hpp"
#include "GGPlayer.h"
#include "Gobbler.h"
#include "enums.h"
#include "Init.h"

// Test GGPlayer initialization (inherits from Player)
TEST_CASE("GGPlayer Initialization", "[GGPlayer][init]") {
    GGPlayer player(HUMAN, BLUE);
    REQUIRE(player.getType() == HUMAN);
    REQUIRE(player.getIdentifier() == BLUE);
}

// Test setting and getting GGPlayer type (inherits from Player)
TEST_CASE("Set and Get GGPlayer Type", "[GGPlayer][set][get]") {
    GGPlayer player(HUMAN, BLUE);
    player.setType(BOT);
    REQUIRE(player.getType() == BOT);
}

// Test setting and getting GGPlayer color (inherits from Player)
TEST_CASE("Set and Get GGPlayer Color", "[GGPlayer][set][get]") {
    GGPlayer player(HUMAN, BLUE);
    player.setIdentifier(RED);
    REQUIRE(player.getIdentifier() == RED);
}

// Test getting a Gobbler from the GGPlayer's hand
TEST_CASE("Get Gobbler from Hand", "[GGPlayer][get][Gobbler]") {
    GGPlayer player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    Gobbler* gobbler = player.getGobblerFromHand(0);
    REQUIRE(gobbler != nullptr);
    REQUIRE(gobbler->getIdentifier() == BLUE);
}

// Test removing a Gobbler from the GGPlayer's hand
TEST_CASE("Remove Gobbler from Hand", "[GGPlayer][remove][Gobbler]") {
    GGPlayer player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    player.removeGobblerFromHand(0);
    REQUIRE(player.getGobblerFromHand(0) == nullptr);
}

// Test inserting all Gobblers to the GGPlayer's hand
TEST_CASE("Insert All Gobblers to Hand", "[GGPlayer][insert][Gobbler]") {
    GGPlayer player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i) {
        REQUIRE(player.getGobblerFromHand(i) != nullptr);
    }
}
