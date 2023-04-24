#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/BubbleSort/BubbleSortStrategy.h"
#include "../../../DataSources/ArraySource/ArraySource.h"

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
	auto aDataSource = std::make_shared<ArraySource<Type, Count>>();
	auto aBubbleStrategy = std::make_shared<BubbleSortStrategy<Type, Count>>();
	auto aComposition = std::make_shared<BubbelSortComposition<Type, Count>>(aBubbleStrategy, aDataSource);
	return aComposition;
}

