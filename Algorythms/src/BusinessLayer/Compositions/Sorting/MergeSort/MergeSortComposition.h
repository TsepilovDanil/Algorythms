#pragma once
#include "../../../compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/MergeSort/MergeSortStrategy.h"

template<typename Type>
class MergeSortComposition : public Composition<Type>
{
public:

	MergeSortComposition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : Composition<Type>(strategy, dataSource) {};
	~MergeSortComposition() = default;

};
