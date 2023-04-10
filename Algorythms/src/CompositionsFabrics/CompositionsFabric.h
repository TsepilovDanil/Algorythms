#pragma once
#include <iostream>
#include "../compositions/Composition.h"

class CompositionsFabric
{
public:
	CompositionsFabric() = default;
	virtual ~CompositionsFabric() = default;

	virtual std::shared_ptr<Composition> GetComposition() { return nullptr; };

};

