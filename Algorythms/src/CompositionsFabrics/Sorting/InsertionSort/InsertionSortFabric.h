#pragma once
#include "../../CompositionsFabric.h"
#include "../../../compositions/sorting/insertion sort/InsertionSortComposition.h"

class  InsertionSortFabric : public CompositionsFabric
{
public:
	InsertionSortFabric() = default;
	~InsertionSortFabric() = default;

	std::shared_ptr<Composition> GetComposition() override { return std::make_shared<InsertionSortComposition>(); };
};

