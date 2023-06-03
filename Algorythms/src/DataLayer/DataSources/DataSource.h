#pragma once
#include <cstddef>
#include <memory>
#include <iostream>
#include <initializer_list>
#include "../Iterators/Iterator.h"

template<typename Type> class Iterator;

template<typename Type>
class DataSource
{
public:
	DataSource() = default;
	virtual ~DataSource() = default;

	std::shared_ptr<Iterator<Type>> _iterator = nullptr;

	std::shared_ptr<Iterator<Type>> GetIterator() { return _iterator; }

	virtual void SetIterator(std::shared_ptr<Iterator<Type>> iterator) { _iterator = iterator; }

	virtual Type* operator[] (const std::size_t index) { 
		return nullptr; 
	}
	
protected:

	std::size_t _sizeOfSource = 0;

};

