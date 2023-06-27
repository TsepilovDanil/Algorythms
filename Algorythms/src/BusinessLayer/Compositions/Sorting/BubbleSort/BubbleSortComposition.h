#pragma once
#include "../../../Compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/BubbleSort/BubbleSortStrategy.h"

template<typename Type>
class BubbelSortComposition : public Composition<Type>
{
public:
	
	BubbelSortComposition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : Composition<Type>(strategy, dataSource) {};
	~BubbelSortComposition() = default;

};

