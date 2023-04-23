#pragma once
#include <cstddef>
#include <array>
#include <memory>
#include "../DataSource.h"
#include "ArraySource.h"

template <typename T, const std::size_t S> class DataSource;

template <typename T, const std::size_t S> class ArraySource : public DataSource <T, S>
{
public:
    
    ArraySource() = default;
    ~ArraySource() = default;

    std::array<T, S> _Array;

    int operator[] (std::size_t index) override { return 2; }
};

