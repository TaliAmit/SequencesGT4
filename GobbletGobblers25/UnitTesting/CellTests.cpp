#include "catch.hpp"
#include "Cell.h"
#include "Gobbler.h"
#include "enums.h"


// Test for Cell initialization and empty state
TEST_CASE("Cell Initialization") {
    Cell cell;
    REQUIRE(cell.isEmpty());
}

// Test for adding a Gobbler to the Cell
TEST_CASE("Add Gobbler to Cell") {
    Cell cell;
    Gobbler gobbler(RED, LARGE);
    cell.addGobbler(&gobbler);
    REQUIRE_FALSE(cell.isEmpty());
    REQUIRE(cell.getTopGobbler() == &gobbler);
}

// Test for getting the top Gobbler when the Cell is empty
TEST_CASE("Get Top Gobbler from Empty Cell") {
    Cell cell;
    REQUIRE(cell.getTopGobbler() == nullptr);
}

// Test for getting the top Gobbler when the Cell has Gobblers
TEST_CASE("Get Top Gobbler from Cell with Gobblers") {
    Cell cell;
    Gobbler gobbler1(RED, LARGE), gobbler2(RED, LARGE);
    cell.addGobbler(&gobbler1);
    cell.addGobbler(&gobbler2);
    REQUIRE(cell.getTopGobbler() == &gobbler2);
}

// Test for removing the top Gobbler from the Cell
TEST_CASE("Remove Top Gobbler from Cell") {
    Cell cell;
    Gobbler gobbler1(RED, LARGE), gobbler2(RED, LARGE);
    cell.addGobbler(&gobbler1);
    cell.addGobbler(&gobbler2);
    cell.removeTopGobbler();
    REQUIRE(cell.getTopGobbler() == &gobbler1);
    cell.removeTopGobbler();
    REQUIRE(cell.isEmpty());
}