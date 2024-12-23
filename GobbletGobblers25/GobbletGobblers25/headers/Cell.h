#pragma once

#include "Gobbler.h"
#include "stack"

class Cell
{
public:
	explicit Cell();
	Cell(const Cell&) = delete;
	Cell& operator=(const Cell&) = default;
	Cell& operator=(Cell&&) = delete;
	~Cell() = default;

	/**
	 * @brief Adds a Gobbler to the Cell.
	 * @param gobbler Pointer to the Gobbler to add. Must not be nullptr.
	 * @throws std::bad_alloc If memory allocation for adding the Gobbler fails.
	 */
	void addGobbler(Gobbler* gobbler);

	/**
	* @brief Retrieves the top Gobbler in the Cell.
	* @return Pointer to the top Gobbler, or nullptr if the Cell is empty.
	*/
	Gobbler* getTopGobbler() const;

	/**
	 * @brief Removes the top Gobbler from the Cell.
	 * @pre The Cell must not be empty.
	 */
	void removeTopGobbler();

	/**
	 * @brief Checks if the Cell is empty.
	 * @return True if the Cell contains no Gobblers, false otherwise.
	 */
	bool isEmpty() const;

private:
	std::stack<Gobbler*> m_gobblers;
};