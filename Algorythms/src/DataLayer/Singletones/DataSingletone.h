#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <map>
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
	
	static bool Registrator(const std::string &singletonName, const std::size_t singletonSize);

	virtual Type* operator[] (const std::size_t index) { 
		return nullptr;
	}

	bool GetSingletoneSize(const std::string& singletonName, std::size_t &size);

protected:

	bool lookUp(const std::string& singletonName);
	

private:
	
	static std::map<std::string, const std::size_t> _registry;
	static void registerInserter(const std::string& singletonName, const std::size_t singletonSize);

};

template<typename Type>
std::map<std::string, const std::size_t> DataSingleton<Type>::_registry;

template<typename Type>
bool DataSingleton<Type>::Registrator(const std::string& singletonName, const std::size_t singletonSize)
{
	if (singletonName == ArraySingleton<Type>::_singletonName)
	{
		registerInserter(singletonName, singletonSize);
		return true;
	}
	else
		return false;
}

template<typename Type>
void DataSingleton<Type>::registerInserter(const std::string& singletonName, const std::size_t singletonSize)
{
	if (!_registry.size())
	{
		_registry.insert({ singletonName, singletonSize });
	}
	else
	{
		if (_registry.find(singletonName) == _registry.end())
		{
			_registry.insert({singletonName, singletonSize});
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

template<typename Type>
bool DataSingleton<Type>::GetSingletoneSize(const std::string& singletonName, std::size_t& size)
{
	if (!lookUp(singletonName))
		return false;
	auto singletonePair = _registry.find(singletonName);
	size = singletonePair->second;
	return true;
}