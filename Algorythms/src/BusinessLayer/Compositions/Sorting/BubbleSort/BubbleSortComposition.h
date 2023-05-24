#pragma once
#include "../../../compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/BubbleSort/BubbleSortStrategy.h"

template<typename Type, std::size_t Count>
class BubbelSortComposition : public Composition<Type, Count>
{
public:
	
	BubbelSortComposition() = default;
	BubbelSortComposition(std::shared_ptr<AlgorythmStrategy<Type, Count>> strategy, std::shared_ptr<DataSingleton<Type, Count>> dataSource) : Composition<Type, Count>(strategy, dataSource) {};
	~BubbelSortComposition() = default;

};

