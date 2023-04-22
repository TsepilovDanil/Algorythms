#pragma once

#include <array>
#include <memory>
#include "../Strategies/Strategy.h"

template<typename Type, std::size_t Count> class Strategy;

template<typename Type, std::size_t Count>
class Composition
{
public:
	Composition() : _Strategy(nullptr) {};
	Composition(std::shared_ptr<Strategy<Type, Count>> strategy) : _Strategy(strategy) {};
	virtual ~Composition() = default;

	//std::array<T, S> _WorkingArray;

	std::shared_ptr<Strategy<Type, Count>> _Strategy;


};


