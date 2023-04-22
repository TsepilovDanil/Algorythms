#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "../../../Strategies/Sorting/BubbleSort/BubbleSortStrategy.h"
#include "../../../Storage/ArrayStorage/ArrayStorage.h"

template<typename Type, std::size_t Count>
class  BubbleSortFabric : public CompositionsFabric<Type, Count>
{
public:

	BubbleSortFabric() = default;
	~BubbleSortFabric() = default;

	std::shared_ptr<Composition<Type, Count>> GetComposition() override;

};

template<typename Type, std::size_t Count>
std::shared_ptr<Composition<Type, Count>> BubbleSortFabric<Type, Count>::GetComposition()
{
	auto bubbleStrategy = std::make_shared<BubbleSortStrategy<Type, Count>>();
	auto composition = std::make_shared<BubbelSortComposition<Type, Count>>(bubbleStrategy);
	return composition;
}

