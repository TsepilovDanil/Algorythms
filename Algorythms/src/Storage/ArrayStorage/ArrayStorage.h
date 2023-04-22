#pragma once
#include <cstddef>
#include <array>
#include <memory>
#include "../Storage.h"
#include "ArrayStorage.h"

template <typename T, const std::size_t S> class Storage;

template <typename T, const std::size_t S> class ArrayStorage : public Storage <T, S>
{
public:
    
    ArrayStorage() = default;
    ~ArrayStorage() = default;

    void func() override {};

    std::array<T, S> _Array;
};

