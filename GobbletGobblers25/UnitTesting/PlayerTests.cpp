#include "catch.hpp"
#include "Player.h"
#include "Gobbler.h"
#include "Enums.h"
#include "Init.h"

// Test Player initialization
TEST_CASE("Player Initialization", "[Player][init]") {
    Player player(HUMAN, BLUE);
    REQUIRE(player.getType() == HUMAN);
    REQUIRE(player.getColor() == BLUE);
}

// Test setting and getting Player type
TEST_CASE("Set and Get Player Type", "[Player][set][get]") {
    Player player(HUMAN, BLUE);
    player.setType(BOT);
    REQUIRE(player.getType() == BOT);
}

// Test setting and getting Player color
TEST_CASE("Set and Get Player Color", "[Player][set][get]") {
    Player player(HUMAN, BLUE);
    player.setColor(RED);
    REQUIRE(player.getColor() == RED);
}

// Test getting a Gobbler from the Player's hand
TEST_CASE("Get Gobbler from Hand", "[Player][get][Gobbler]") {
    Player player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    Gobbler* gobbler = player.getGobblerFromHand(0);
    REQUIRE(gobbler != nullptr);
    REQUIRE(gobbler->getColor() == BLUE);
}

// Test removing a Gobbler from the Player's hand
TEST_CASE("Remove Gobbler from Hand", "[Player][remove][Gobbler]") {
    Player player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    player.removeGobblerFromHand(0);
    REQUIRE(player.getGobblerFromHand(0) == nullptr);
}

// Test inserting all Gobblers to the Player's hand
TEST_CASE("Insert All Gobblers to Hand", "[Player][insert][Gobbler]") {
    Player player(HUMAN, BLUE);
    player.insertAllGobblersToHand();
    for (int i = 0; i < GameConstants::GOBBLERS_PER_PLAYER; ++i) {
        REQUIRE(player.getGobblerFromHand(i) != nullptr);
    }
}
