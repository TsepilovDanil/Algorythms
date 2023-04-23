#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../../../compositions/sorting/quick sort/QuickSortComposition.h"

class QuickSortStrategy : public Strategy
{
public:
	QuickSortStrategy() = default;
	QuickSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "QuickSortStrategy" << std::endl; }
	~QuickSortStrategy() = default;

private:

	void algorythm(void*);
	
};



