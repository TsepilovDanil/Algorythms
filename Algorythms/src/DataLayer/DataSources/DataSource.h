#pragma once
#include <cstddef>
#include <memory>
#include <iostream>
#include <initializer_list>
#include "../Iterators/Iterator.h"

template<typename Type, std::size_t Count> class Iterator;

template<typename Type, const std::size_t Count>
class DataSource
{
public:
	DataSource() = default;
	virtual ~DataSource() = default;

	virtual std::shared_ptr<Iterator<Type, Count>> GetForwardIterator() { return nullptr; }

	virtual Type* operator[] (const std::size_t index) { return nullptr; }
};

