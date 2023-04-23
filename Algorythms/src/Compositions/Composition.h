#pragma once

#include <array>
#include <memory>
#include "../AlgorythmsStrategies/AlgorythmStrategy.h"

template<typename Type, std::size_t Count> class AlgorythmStrategy;

template<typename Type, std::size_t Count>
class Composition
{
public:
	Composition() : _Strategy(nullptr) {};
	Composition(std::shared_ptr<AlgorythmStrategy<Type, Count>> strategy) : _Strategy(strategy) {};
	virtual ~Composition() = default;

	std::shared_ptr<AlgorythmStrategy<Type, Count>> _Strategy;

};


