#pragma once
#include "../../../strategies/sorting/quick sort/QuickSortStrategy.h"

class QuickSortComposition : public Composition
{
public:
	QuickSortComposition() : Composition(std::make_shared<QuickSortStrategy>(this)) {};
	~QuickSortComposition() = default;
};

