#pragma once
#include <cstddef>
#include <memory>
#include <iostream>
#include <initializer_list>

template<typename Type> class Iterator;

template<typename Type>
class DataSource
{
public:
	DataSource() = default;
	virtual ~DataSource() = default;

	virtual Type* operator[] (const std::size_t index) { 
		return nullptr; 
	}
	
protected:

	std::size_t _sizeOfSource = 0;

};

