#pragma once
#include <cstddef>

template <typename Type, const std::size_t Count> class DataSource
{
public:

	DataSource() = default;
	~DataSource() = default;

	virtual const Type * const operator[] (const std::size_t index) { return nullptr; }
};

