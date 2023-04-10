#pragma once

#include <array>
#include <memory>
#include "../Strategies/Strategy.h"

class Strategy;

class Composition
{
public:
	Composition() : _Strategy(nullptr) {};
	Composition(std::shared_ptr<Strategy> strategy) : _Strategy(strategy) {};
	virtual ~Composition() = default;

	//std::array<T, S> _WorkingArray;

	std::shared_ptr<Strategy> _Strategy;


};


