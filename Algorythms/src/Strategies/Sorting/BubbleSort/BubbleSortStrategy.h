#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../../../compositions/sorting/bubblesort/BubbleSortComposition.h"

class BubbleSortStrategy : public Strategy
{
public:
	BubbleSortStrategy() = default;
	BubbleSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "BubbleSortStrategy" << std::endl; };
	~BubbleSortStrategy() = default;

private:

	void algorythm(void*);
	
};




