#pragma once

#include <array>
#include <memory>
#include "../DataSources/DataSource.h"
#include "../AlgorythmsStrategies/AlgorythmStrategy.h"

template<typename Type, std::size_t Count> class AlgorythmStrategy;
template<typename Type, std::size_t Count> class DataSource;

template<typename Type, std::size_t Count>
class Composition
{
public:
	Composition() : _aStrategy(nullptr) {};
	Composition(std::shared_ptr<AlgorythmStrategy<Type, Count>> aStrategy, std::shared_ptr<DataSource<Type, Count>> aDataSource) : _aStrategy(aStrategy), _aDataSource(aDataSource) {};
	virtual ~Composition() = default;

	std::shared_ptr<AlgorythmStrategy<Type, Count>> _aStrategy;

	std::shared_ptr<DataSource<Type, Count>> _aDataSource;

};


