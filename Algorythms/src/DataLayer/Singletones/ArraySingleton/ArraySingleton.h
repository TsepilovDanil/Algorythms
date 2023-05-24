#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include "../DataSingletone.h"
#include "ArraySingleton.h"
#include "../../Iterators/ForwardIterator/ForwardIterator.h"

template <typename Type, const std::size_t Count> class DataSingleton;

template <typename Type, const std::size_t Count = 0>
class ArraySingleton : public DataSingleton <Type, Count>
{

public:
	
	ArraySingleton() = default;
	~ArraySingleton() = default;

	static const std::string _singletonName;
	static std::shared_ptr<ArraySingleton<Type, Count>> _instance;

	static std::shared_ptr<ArraySingleton<Type, Count>> Instance();

private:

};

template<typename Type, std::size_t Count>
const std::string ArraySingleton<Type, Count>::_singletonName = "array";

template<typename Type, std::size_t Count>
std::shared_ptr<ArraySingleton<Type, Count>> ArraySingleton<Type, Count>::_instance = nullptr;

template<typename Type, std::size_t Count>
std::shared_ptr<ArraySingleton<Type, Count>> ArraySingleton<Type, Count>::Instance()
{
	if (_instance == nullptr)
	{
		if (!DataSingleton<Type, Count>::lookUp(_singletonName))
		{
			if (DataSingleton<Type, Count>::Registrator(_singletonName))
			{
				std::shared_ptr<std::array<Type, Count>> arraySource = std::make_shared<std::array<Type, Count>>();
				_instance = std::make_shared<ArraySingleton<Type, Count>>();
				_instance->_arraySource = arraySource;
			}
		}
	}
	return _instance;
}