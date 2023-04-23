#pragma once
#include "../../Strategy.h"
#include ".././../../compositions/Composition.h"
#include "../../../compositions/sorting/selection sort/SelectionSortComposition.h"

class SelectionSortStrategy : public Strategy
{
public:
	SelectionSortStrategy() = default;
	SelectionSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "SelectionSortStrategy" << std::endl; }
	~SelectionSortStrategy() = default;

private:

	void algorythm(void*);
	
};



