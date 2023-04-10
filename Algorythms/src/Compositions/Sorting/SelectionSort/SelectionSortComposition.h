#pragma once
#include "../../../strategies/sorting/selection sort/SelectionSortStrategy.h"

class SelectionSortStrategy;

class SelectionSortComposition : public Composition
{
public:
	SelectionSortComposition() : Composition(std::make_shared<SelectionSortStrategy>(this)) {};
	~SelectionSortComposition() = default;
};

