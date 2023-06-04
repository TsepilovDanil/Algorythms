#pragma once
#include "../../../compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/QuickSort/QuickSortStrategy.h"

template<typename Type>
class QuickSortComposition : public Composition<Type>
{
public:

	QuickSortComposition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : Composition<Type>(strategy, dataSource) {};
	~QuickSortComposition() = default;

};