#pragma once
#include "../../../Compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/SelectionSort/SelectionSortStrategy.h"

template<typename Type>
class SelectionSortComposition : public Composition<Type>
{
public:

	SelectionSortComposition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : Composition<Type>(strategy, dataSource) {};
	~SelectionSortComposition() = default;

};
