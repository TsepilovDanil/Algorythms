#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../.././../compositions/sorting/merge sort/MergeSortComposition.h"

class MergeSortStrategy : public Strategy
{
public:
	MergeSortStrategy() = default;
	MergeSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "MergeSortStrategy" << std::endl; }
	~MergeSortStrategy() = default;

private:

	void algorythm(void*);
	
};



