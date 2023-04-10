#pragma once
#include "../../../compositions/Composition.h"

class BubbelSortComposition : public Composition
{
public:
	
	BubbelSortComposition() = default;
	BubbelSortComposition(std::shared_ptr<Strategy> strategy) : Composition(strategy) {};
	~BubbelSortComposition() = default;

};

