#pragma once
#include <cstddef>
template <typename T, std::size_t S>
class Storage
{
public:
	Storage() = default;
	~Storage() = default;

	std::array<T, S> _Array;
};

