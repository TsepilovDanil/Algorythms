#pragma once
#include "../../../strategies/sorting/merge sort/MergeSortStrategy.h"

class MergeSortComposition : public Composition
{
public:
	MergeSortComposition() : Composition(std::make_shared<MergeSortStrategy>(this)) {};
	~MergeSortComposition() = default;
};


