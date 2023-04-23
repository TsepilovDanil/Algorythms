#pragma once
#include <cstddef>
#include "ArraySource/ArraySource.h"


template <typename T, const std::size_t S> class DataSource
{
public:

	DataSource() = default;
	~DataSource() = default;

	virtual int operator[] (std::size_t index) { return 1; }
};

