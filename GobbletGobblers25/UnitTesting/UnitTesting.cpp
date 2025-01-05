// UnitTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../GobbletGobblers25/headers/Cell.h"
#include "../GobbletGobblers25/headers/Gobbler.h"
#include "../GobbletGobblers25/headers/enums.h"
// #include "../GobbletGobblers25/headers/"
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



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