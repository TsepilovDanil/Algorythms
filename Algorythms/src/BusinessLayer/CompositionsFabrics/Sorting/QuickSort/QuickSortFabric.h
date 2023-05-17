#pragma once
#include "../../CompositionsFabric.h"
#include "../../../compositions/sorting/quick sort/QuickSortComposition.h"


class  QuickSortFabric : public CompositionsFabric
{
public:
	QuickSortFabric() = default;
	~QuickSortFabric() = default;

	std::shared_ptr<Composition> GetComposition() override { return std::make_shared<QuickSortComposition>(); };

};

