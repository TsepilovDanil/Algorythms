#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include "../DataSourceSingleton.h"
#include "ArraySourceSingleton.h"

template <typename Type, const std::size_t Count> class DataSourceSingleton;

template <typename Type, const std::size_t Count>
class ArraySourceSingleton : public DataSourceSingleton <Type, Count>
{
public:

	ArraySourceSingleton() = default;
	~ArraySourceSingleton() = default;

	static std::shared_ptr<ArraySourceSingleton<Type, Count>> Instance();

	Type * operator[] (const std::size_t index) override;

	static std::shared_ptr<ArraySourceSingleton<Type, Count>> _instance;

private:

	static const std::string _singletonName;
	std::shared_ptr<std::array<Type, Count>> _array;
	

};

template<typename Type, std::size_t Count>
const std::string ArraySourceSingleton<Type, Count>::_singletonName = "array";

template<typename Type, std::size_t Count>
std::shared_ptr<ArraySourceSingleton<Type, Count>> ArraySourceSingleton<Type, Count>::_instance = nullptr;

//template<typename Type, std::size_t Count>
//std::shared_ptr<std::array<Type, Count>> ArraySourceSingleton<Type, Count>::_array = nullptr;

template<typename Type, std::size_t Count>
Type * ArraySourceSingleton<Type, Count>::operator[] (std::size_t index)
{
	Type * elementPtr = nullptr;
	try
	{
		//std::shared_ptr<ArraySourceSingleton<Type, Count>> item = Instance();
		elementPtr = &(*_array).at(index);
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "ArraySourceSingleton<Type, Count>::operator[] exception: " << exception.what() << std::endl;
	}
	return elementPtr;
}

template<typename Type, std::size_t Count>
std::shared_ptr<ArraySourceSingleton<Type, Count>> ArraySourceSingleton<Type, Count>::Instance()
{
	if (_instance == nullptr)
	{
		if (!DataSourceSingleton<Type, Count>::lookUp(_singletonName))
		{
			if (DataSourceSingleton<Type, Count>::Registrator(_singletonName))
			{
				_instance = std::make_shared<ArraySourceSingleton<Type, Count>>();
				_instance->_array = std::make_shared<std::array<Type, Count>>();
			}
		}
	}
	return _instance;
}