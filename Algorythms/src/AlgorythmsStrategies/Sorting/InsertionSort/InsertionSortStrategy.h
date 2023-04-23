#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../../../compositions/sorting/insertion sort/InsertionSortComposition.h"

class InsertionSortStrategy : public Strategy
{
public:
	InsertionSortStrategy() = default;
	InsertionSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "InsertionSortStrategy" << std::endl; }
	~InsertionSortStrategy() = default;

private:
	
	void algorythm(void*);

};



