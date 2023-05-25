#pragma once
#include <iostream>
#include <array>
#include "../compositions/Composition.h"

template<typename Type>
class CompositionsFabric
{
public:
	
	CompositionsFabric() = default;
	virtual ~CompositionsFabric() = default;

	virtual std::shared_ptr<Composition<Type>> GetComposition() { return nullptr; };

	std::shared_ptr<Composition<Type>> _composition = nullptr;

protected:

};


