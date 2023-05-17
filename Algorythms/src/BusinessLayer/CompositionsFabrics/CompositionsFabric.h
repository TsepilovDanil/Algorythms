#pragma once
#include <iostream>
#include <array>
#include "../compositions/Composition.h"

template<typename Type, std::size_t Count>
class CompositionsFabric
{
public:
	
	CompositionsFabric() = default;
	virtual ~CompositionsFabric() = default;

	virtual std::shared_ptr<Composition<Type, Count>> GetComposition() { return nullptr; };
	
	virtual void StartAlgorythm(void*) {};
};

