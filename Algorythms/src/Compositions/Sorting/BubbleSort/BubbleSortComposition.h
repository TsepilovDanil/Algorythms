#pragma once
#include "../../../compositions/Composition.h"
#include "../../../Strategies/Sorting/BubbleSort/BubbleSortStrategy.h"

//template<typename ProcessinElementType, std::size_t ElementCount> class BubbleSortStrategy;

class BubbleSortStrategy;

class BubbelSortComposition : public Composition
{
public:
	
	BubbelSortComposition() = default;
	BubbelSortComposition(std::shared_ptr<Strategy> strategy) : Composition(strategy) {};
	~BubbelSortComposition() = default;

};

