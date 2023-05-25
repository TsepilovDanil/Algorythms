#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <string>
#include "../Iterators/Iterator.h"
#include "ArraySingleton/ArraySingleton.h"

template <typename Type> class ArraySingleton;

template <typename Type> 
class DataSingleton 
{
protected:

	DataSingleton() = default;
	virtual ~DataSingleton() = default;

public:
	
	static bool Registrator(const std::string &singletonName);

	virtual Type* operator[] (const std::size_t index) { return nullptr; }

protected:

	static bool lookUp(const std::string& singletonName);

private:
	
	static std::set<std::string> _registry;
	static void registerInserter(const std::string& singletonName);

};

template<typename Type>
std::set<std::string> DataSingleton<Type>::_registry;

template<typename Type>
bool DataSingleton<Type>::Registrator(const std::string& singletonName)
{
	if (singletonName == ArraySingleton<Type>::_singletonName)
	{
		registerInserter(singletonName);
		return true;
	}
	else
		return false;
}

template<typename Type>
void DataSingleton<Type>::registerInserter(const std::string& singletonName)
{
	if (!_registry.size())
	{
		_registry.insert(singletonName);	
	}
	else
	{
		if (_registry.find(singletonName) == _registry.end())
		{
			_registry.insert(singletonName);
		}
	}
}

template<typename Type>
bool DataSingleton<Type>::lookUp(const std::string& singletonName)
{
	if (_registry.find(singletonName) != _registry.end())
	{
		return true;
	}
	return false;
}