#pragma once
#include "../../../Compositions/Composition.h"
#include "../../../AlgorythmsStrategies/Sorting/InsertionSort/InsertionSortStrategy.h"

template<typename Type>
class InsertionSortComposition : public Composition<Type>
{
public:

	InsertionSortComposition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : Composition<Type>(strategy, dataSource) {};
	~InsertionSortComposition() = default;

};

