#pragma once
#include <cstddef>
#include "ArrayStorage/ArrayStorage.h"

#define StorageSize 10

template <typename T, const std::size_t S> class Storage
{
public:

	Storage() = default;
	~Storage() = default;

	virtual void func() {};
	
};

