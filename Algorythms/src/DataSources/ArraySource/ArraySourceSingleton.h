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
protected:
    
    ArraySourceSingleton() = default;
    ~ArraySourceSingleton() = default;

public:

	static std::shared_ptr<std::array<Type, Count>> * Instance();

	const Type* const operator[] (const std::size_t index) override;

private:
	
    static std::shared_ptr<std::array<Type, Count>> * _instance;


};

template<typename Type, std::size_t Count>
const Type * const ArraySourceSingleton<Type, Count>::operator[] (std::size_t index)
{
	Type * elementPtr = nullptr;

	try
	{
		elementPtr = &(*ArraySourceSingleton<Type, Count>::_instance)->at(index);
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return elementPtr;
}

template<typename Type, std::size_t Count>
std::shared_ptr<std::array<Type, Count>>* ArraySourceSingleton<Type, Count>::_instance = nullptr;

template<typename Type, std::size_t Count>
std::shared_ptr<std::array<Type, Count>>* ArraySourceSingleton<Type, Count>::Instance()
{
	if (_instance == nullptr)
	{
		std::string singletonName = "array";
		if (DataSourceSingleton<Type, Count>::lookUp(singletonName))
		{

		}
	}
	return _instance;
}