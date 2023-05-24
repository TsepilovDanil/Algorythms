#pragma once

#include <array>
#include <memory>
#include "../../DataLayer/Singletones/DataSingletone.h"
#include "../AlgorythmsStrategies/AlgorythmStrategy.h"

template<typename Type, std::size_t Count> class AlgorythmStrategy;
template<typename Type, std::size_t Count> class DataSingleton;

template<typename Type, std::size_t Count>
class Composition
{
public:
	Composition() : _strategy(nullptr) {};
	Composition(std::shared_ptr<AlgorythmStrategy<Type, Count>> strategy, std::shared_ptr<DataSingleton<Type, Count>> dataSource) : _strategy(strategy), _dataSource(dataSource) {};
	virtual ~Composition() = default;

	std::shared_ptr<AlgorythmStrategy<Type, Count>> _strategy;

	std::shared_ptr<DataSingleton<Type, Count>> _dataSource;

	void StartAlgorythm();

};

template<typename Type, std::size_t Count>
void Composition<Type, Count>::StartAlgorythm()
{
	if(Composition<Type, Count>::_strategy)
		Composition<Type, Count>::_strategy->StartWork();
}
