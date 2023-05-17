#pragma once
#include "../../CompositionsFabric.h"
#include "../../../compositions/sorting/selection sort/SelectionSortComposition.h"

class  SelectionSortFabric : public CompositionsFabric
{
public:
	SelectionSortFabric() = default;
	~SelectionSortFabric() = default;

	std::shared_ptr<Composition> GetComposition() override { return std::make_shared<SelectionSortComposition>(); };

};

