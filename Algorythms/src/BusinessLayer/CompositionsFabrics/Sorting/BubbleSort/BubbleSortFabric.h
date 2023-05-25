#pragma once
#include <cstddef>
#include <memory>
#include "../../CompositionsFabric.h"
#include "../../../Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "../../../AlgorythmsStrategies/Sorting/BubbleSort/BubbleSortStrategy.h"
#include "../../../../DataLayer/Singletones/DataSingletone.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type>
class  BubbleSortFabric : public CompositionsFabric<Type>
{
public:

	//BubbleSortFabric(std::size_t sizeOfSource);

	BubbleSortFabric(std::initializer_list<Type>&& initializer);
	~BubbleSortFabric() = default;

	std::shared_ptr<Composition<Type>> GetComposition() override;
};

/*template<typename Type>
BubbleSortFabric<Type>::BubbleSortFabric(std::size_t sizeOfSource)
{
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<BubbleSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<BubbelSortComposition<Type>>(strategy, nullptr);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}*/

template<typename Type>
BubbleSortFabric<Type>::BubbleSortFabric(std::initializer_list<Type> && initializer)
{
	std::shared_ptr<DataSingleton<Type>> dataSingleton = std::make_shared<ArraySingleton<Type>>(std::forward<std::initializer_list<Type>>(initializer));
	std::shared_ptr<AlgorythmStrategy<Type>> strategy = std::make_shared<BubbleSortStrategy<Type>>();
	CompositionsFabric<Type>::_composition = std::make_shared<BubbelSortComposition<Type>>(strategy, dataSingleton);
	strategy->SetComposition(CompositionsFabric<Type>::_composition);
}

template<typename Type>
std::shared_ptr<Composition<Type>> BubbleSortFabric<Type>::GetComposition()
{

	//*(*ArraySingleton<Type, Count>::Instance())[0] = 1; BubbleSortFabric<Type>::_sizeOfSource
	
	return CompositionsFabric<Type>::_composition;
}

