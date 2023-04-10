#pragma once
#include "../../../strategies/sorting/insertion sort/InsertionSortStrategy.h"

class InsertionSortComposition : public Composition
{
public:
	InsertionSortComposition() : Composition(std::make_shared<InsertionSortStrategy>(this)) {};
	~InsertionSortComposition() = default;
};

