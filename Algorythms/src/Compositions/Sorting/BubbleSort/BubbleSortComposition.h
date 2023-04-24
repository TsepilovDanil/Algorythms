#pragma once
#include "../../../compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/BubbleSort/BubbleSortStrategy.h"

template<typename Type, std::size_t Count>
class BubbelSortComposition : public Composition<Type, Count>
{
public:
	
	BubbelSortComposition() = default;
	BubbelSortComposition(std::shared_ptr<AlgorythmStrategy<Type, Count>> aStrategy, std::shared_ptr<DataSource<Type, Count>> aDataSource) : Composition<Type, Count>(aStrategy, aDataSource) {};
	~BubbelSortComposition() = default;

};

