#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/InsertionSort/InsertionSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/InsertionSort/InsertionSortStrategy.h"
#include "../../../../DataLayer/Singletones/DataSingletone.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type>
class  InsertionSortFabric : public CompositionsFabric<Type>
{
public:

	InsertionSortFabric(std::initializer_list<Type>&& initializer);
	~InsertionSortFabric() = default;

};

template<typename Type>
InsertionSortFabric<Type>::InsertionSortFabric(std::initializer_list<Type>&& initializer)
{
	std::shared_ptr<DataSingleton<Type>> dataSingleton = std::make_shared<ArraySingleton<Type>>(std::forward<std::initializer_list<Type>>(initializer));
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<InsertionSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<InsertionSortComposition<Type>>(strategy, dataSingleton);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}



