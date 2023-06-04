#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/QuickSort/QuickSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/QuickSort/QuickSortStrategy.h"
#include "../../../../DataLayer/Singletones/DataSingletone.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type>
class  QuickSortFabric : public CompositionsFabric<Type>
{
public:

	QuickSortFabric(std::initializer_list<Type>&& initializer);
	~QuickSortFabric() = default;
};

template<typename Type>
QuickSortFabric<Type>::QuickSortFabric(std::initializer_list<Type>&& initializer)
{
	std::shared_ptr<DataSingleton<Type>> dataSingleton = std::make_shared<ArraySingleton<Type>>(std::forward<std::initializer_list<Type>>(initializer));
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<QuickSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<QuickSortComposition<Type>>(strategy, dataSingleton);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}

