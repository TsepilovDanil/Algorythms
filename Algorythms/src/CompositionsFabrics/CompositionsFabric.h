#pragma once
#include <iostream>
#include "../compositions/Composition.h"

template<typename ProcessinElementType, std::size_t ElementCount>
class CompositionsFabric
{
public:
	CompositionsFabric() = default;
	virtual ~CompositionsFabric() = default;

	virtual std::shared_ptr<Composition> GetComposition() { return nullptr; };

	
	virtual void StartAlgorythm(void*) {};
	
};

