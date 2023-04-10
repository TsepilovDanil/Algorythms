#pragma once
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "../../../Strategies/Sorting/BubbleSort/BubbleSortStrategy.h"

class  BubbleSortFabric : public CompositionsFabric
{
public:

	BubbleSortFabric() = default;
	~BubbleSortFabric() = default;

	std::shared_ptr<Composition> GetComposition() override;

};

