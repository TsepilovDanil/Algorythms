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

	std::shared_ptr<Composition> GetComposition() override;

};

template<typename ProcessinElementType, std::size_t ElementCount>
std::shared_ptr<Composition> BubbleSortFabric<ProcessinElementType, ElementCount>::GetComposition()
{
	auto strategy = std::make_shared<BubbleSortStrategy>();

	return std::make_shared<BubbelSortComposition>(strategy);
}

