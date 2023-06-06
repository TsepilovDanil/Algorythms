#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include "../DataSingletone.h"
#include "../../DataSources/DataSource.h"
#include "../../DataSources/ArraySource/ArraySource.h"

template <typename Type> class DataSingleton;
template <typename Type> class DataSource;
template <typename Type> class ArraySource;

template <typename Type>
class ArraySingleton : public DataSingleton <Type>
{

public:
	
	ArraySingleton() = default;
	ArraySingleton(std::initializer_list<Type>&& initializer);
	~ArraySingleton() = default;

	static const std::string _singletonName;
	static std::shared_ptr<ArraySource<Type>> _arraySource;

	static std::shared_ptr<ArraySingleton<Type>> _instance;

	std::shared_ptr<DataSingleton<Type>> Instance() override;

	Type* operator[] (const std::size_t index) override { return (*_arraySource)[index]; }

};

template<typename Type>
const std::string ArraySingleton<Type>::_singletonName = "array";

template<typename Type>
std::shared_ptr<ArraySource<Type>> ArraySingleton<Type>::_arraySource = nullptr;

template<typename Type>
std::shared_ptr<ArraySingleton<Type>> ArraySingleton<Type>::_instance = nullptr;

template<typename Type>
ArraySingleton<Type>::ArraySingleton(std::initializer_list<Type>&& initializer)
{
	if (DataSingleton<Type>::registrator(_singletonName, initializer.size()))
	{
		std::shared_ptr<ArraySource<Type>> arraySource = std::make_shared<ArraySource<Type>>(std::forward<std::initializer_list<Type>>(initializer));
		_instance = std::make_shared<ArraySingleton<Type>>();
		_instance->_arraySource = arraySource;
	}
}

template<typename Type>
std::shared_ptr<DataSingleton<Type>> ArraySingleton<Type>::Instance()
{
	return _instance;
}