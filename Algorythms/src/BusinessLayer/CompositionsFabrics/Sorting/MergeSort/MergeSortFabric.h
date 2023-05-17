#pragma once
#include "../../CompositionsFabric.h"
#include "../../../compositions/sorting/merge sort/MergeSortComposition.h"

class  MergeSortFabric : public CompositionsFabric
{
public:
	MergeSortFabric() = default;
	~MergeSortFabric() = default;

	std::shared_ptr<Composition> GetComposition() override { return std::make_shared<MergeSortComposition>(); };
};

