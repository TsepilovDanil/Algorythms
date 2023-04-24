#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include "../DataSource.h"
#include "ArraySource.h"

template <typename Type, const std::size_t Count> class DataSource;

template <typename Type, const std::size_t Count> class ArraySource : public DataSource <Type, Count>
{
public:
    
    ArraySource() = default;
    ~ArraySource() = default;

    std::array<Type, Count> _aArray;

    const Type * const operator[] (const std::size_t index) override;
};

template<typename Type, std::size_t Count>
const Type * const ArraySource<Type, Count>::operator[] (std::size_t index)
{
	Type * aElementPtr = nullptr;

	try
	{
		aElementPtr = &_aArray.at(index);
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return aElementPtr;
}

