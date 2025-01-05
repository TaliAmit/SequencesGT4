#include "gtest/gtest.h"
#include "Cell.h"
#include "Gobbler.h"
#include "enums.h"

// Test for Cell initialization and empty state
TEST(CellTest, Initialization) {
    Cell cell;
    EXPECT_TRUE(cell.isEmpty());
}

// Test for adding a Gobbler to the Cell
TEST(CellTest, AddGobbler) {
    Cell cell;
    Gobbler gobbler(RED, LARGE);
    cell.addGobbler(&gobbler);
    EXPECT_FALSE(cell.isEmpty());
    EXPECT_EQ(cell.getTopGobbler(), &gobbler);
}

// Test for getting the top Gobbler when the Cell is empty
TEST(CellTest, GetTopGobblerEmpty) {
    Cell cell;
    EXPECT_EQ(cell.getTopGobbler(), nullptr);
}

// Test for getting the top Gobbler when the Cell has Gobblers
TEST(CellTest, GetTopGobbler) {
    Cell cell;
    Gobbler gobbler1(RED, LARGE), gobbler2(RED, LARGE);
    cell.addGobbler(&gobbler1);
    cell.addGobbler(&gobbler2);
    EXPECT_EQ(cell.getTopGobbler(), &gobbler2);
}

// Test for removing the top Gobbler from the Cell
TEST(CellTest, RemoveTopGobbler) {
    Cell cell;
    Gobbler gobbler1(RED, LARGE), gobbler2(RED, LARGE);
    cell.addGobbler(&gobbler1);
    cell.addGobbler(&gobbler2);
    cell.removeTopGobbler();
    EXPECT_EQ(cell.getTopGobbler(), &gobbler1);
    cell.removeTopGobbler();
    EXPECT_TRUE(cell.isEmpty());
}

//Main function to run all tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
