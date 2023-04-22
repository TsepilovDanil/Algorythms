#pragma once
#include "../../../compositions/Composition.h"
#include "../../../Strategies/Sorting/BubbleSort/BubbleSortStrategy.h"

template<typename Type, std::size_t Count>
class BubbelSortComposition : public Composition<Type, Count>
{
public:
	
	BubbelSortComposition() = default;
	BubbelSortComposition(std::shared_ptr<Strategy<Type, Count>> strategy) : Composition<Type, Count>(strategy) {};
	~BubbelSortComposition() = default;

};

