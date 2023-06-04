#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/MergeSort/MergeSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/MergeSort/MergeSortStrategy.h"
#include "../../../../DataLayer/Singletones/DataSingletone.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type>
class  MergeSortFabric : public CompositionsFabric<Type>
{
public:

	MergeSortFabric(std::initializer_list<Type>&& initializer);
	~MergeSortFabric() = default;

};

template<typename Type>
MergeSortFabric<Type>::MergeSortFabric(std::initializer_list<Type>&& initializer)
{
	std::shared_ptr<DataSingleton<Type>> dataSingleton = std::make_shared<ArraySingleton<Type>>(std::forward<std::initializer_list<Type>>(initializer));
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<MergeSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<MergeSortComposition<Type>>(strategy, dataSingleton);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}


