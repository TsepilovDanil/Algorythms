#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <string>
#include "../Iterators/Iterator.h"
#include "ArraySingleton/ArraySingleton.h"

template <typename Type, const std::size_t Count> class ArraySingleton;

template <typename Type, const std::size_t Count> 
class DataSingleton 
{
protected:

	DataSingleton() = default;
	virtual ~DataSingleton() = default;

public:
	
	static bool Registrator(const std::string &singletonName);	

protected:

	static bool lookUp(const std::string& singletonName);

private:
	
	static std::set<std::string> _registry;
	static void registerInserter(const std::string& singletonName);

};

template<typename Type, std::size_t Count>
std::set<std::string> DataSingleton<Type, Count>::_registry;

template<typename Type, std::size_t Count>
bool DataSingleton<Type, Count>::Registrator(const std::string& singletonName)
{
	if (singletonName == ArraySingleton<Type, Count>::_singletonName)
	{
		registerInserter(singletonName);
		return true;
	}
	else
		return false;
}

template<typename Type, std::size_t Count>
void DataSingleton<Type, Count>::registerInserter(const std::string& singletonName)
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

template<typename Type, std::size_t Count>
bool DataSingleton<Type, Count>::lookUp(const std::string& singletonName)
{
	if (_registry.find(singletonName) != _registry.end())
	{
		return true;
	}
	return false;
}