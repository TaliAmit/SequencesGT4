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

	void addGobbler(Gobbler* gobbler);
	Gobbler* getTopGobbler() const;
	void removeTopGobbler();

	bool isEmpty() const;

private:
	std::stack<Gobbler*> m_gobblers;
};