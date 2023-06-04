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

	std::shared_ptr<Composition<Type>> GetComposition();

	std::shared_ptr<Composition<Type>> _composition = nullptr;

protected:

};

template<typename Type>
std::shared_ptr<Composition<Type>> CompositionsFabric<Type>::GetComposition()
{
	return CompositionsFabric<Type>::_composition;
}

