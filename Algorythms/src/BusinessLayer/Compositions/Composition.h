#pragma once

#include <array>
#include <memory>
#include "../../DataLayer/Singletones/DataSingletone.h"
#include "../AlgorythmsStrategies/AlgorythmStrategy.h"

template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;

template<typename Type>
class Composition
{
public:
	Composition(std::shared_ptr<AlgorythmStrategy<Type>> strategy, std::shared_ptr<DataSingleton<Type>> dataSource) : _strategy(strategy), _dataSingleton(dataSource) {};
	virtual ~Composition() = default;

	std::shared_ptr<AlgorythmStrategy<Type>> _strategy = nullptr;
	
	std::shared_ptr<DataSingleton<Type>> _dataSingleton = nullptr;

	void StartAlgorythm();

};

template<typename Type>
void Composition<Type>::StartAlgorythm()
{
	if(Composition<Type>::_strategy)
		Composition<Type>::_strategy->StartWork();
}
