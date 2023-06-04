#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/SelectionSort/SelectionSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/SelectionSort/SelectionSortStrategy.h"
#include "../../../../DataLayer/Singletones/DataSingletone.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type>
class  SelectionSortFabric : public CompositionsFabric<Type>
{
public:

	SelectionSortFabric(std::initializer_list<Type>&& initializer);
	~SelectionSortFabric() = default;
};

template<typename Type>
SelectionSortFabric<Type>::SelectionSortFabric(std::initializer_list<Type>&& initializer)
{
	std::shared_ptr<DataSingleton<Type>> dataSingleton = std::make_shared<ArraySingleton<Type>>(std::forward<std::initializer_list<Type>>(initializer));
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<SelectionSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<SelectionSortComposition<Type>>(strategy, dataSingleton);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}

