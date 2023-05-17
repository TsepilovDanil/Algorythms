#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include "../DataSingletone.h"
#include "ArraySingleton.h"
#include "../../Iterators/ArrayIterator/ArrayIterator.h"

template <typename Type, const std::size_t Count> class DataSourceSingleton;

template <typename Type, const std::size_t Count>
class ArraySourceSingleton : public DataSourceSingleton <Type, Count>
{
public:
	
	float a = (float)1.1;
	using DataSourceSingleton<Type, Count>::function;

	ArraySourceSingleton() {  };
	~ArraySourceSingleton() = default;

	//void function() override {};

	static const std::string _singletonName;
	static std::shared_ptr<ArraySourceSingleton<Type, Count>> _instance;

	static std::shared_ptr<ArraySourceSingleton<Type, Count>> Instance();
	Type * const operator[] (const std::size_t index) override;

	void First() override {};
	void Next() override {};
	bool IsDone() override { return false; };
	Type* CurrentItem() override { return nullptr; };

private:

	static std::shared_ptr<std::array<Type, Count>> _arraySource;

};

template<typename Type, std::size_t Count>
const std::string ArraySourceSingleton<Type, Count>::_singletonName = "array";

template<typename Type, std::size_t Count>
std::shared_ptr<ArraySourceSingleton<Type, Count>> ArraySourceSingleton<Type, Count>::_instance = nullptr;

template<typename Type, std::size_t Count>
std::shared_ptr<std::array<Type, Count>> ArraySourceSingleton<Type, Count>::_arraySource = nullptr;

template<typename Type, std::size_t Count>
Type * const ArraySourceSingleton<Type, Count>::operator[] (std::size_t index)
{
	function(a);

	Type * elementPtr = nullptr;
	try
	{
		elementPtr = &(*_arraySource).at(index);
	}
	catch (const std::exception& exception)
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
				std::shared_ptr<std::array<Type, Count>> arraySource = std::make_shared<std::array<Type, Count>>();
				_instance = std::make_shared<ArraySourceSingleton<Type, Count>>();
				_instance->_arraySource = arraySource;
			}
		}
	}
	return _instance;
}