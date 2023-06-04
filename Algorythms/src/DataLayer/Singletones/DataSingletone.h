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

public:

	virtual ~DataSingleton() = default;

	virtual Type* operator[] (const std::size_t index) { 
		return nullptr;
	}

	virtual std::shared_ptr<DataSingleton<Type>> Instance();
	bool GetSingletoneSize(const std::string& singletonName, std::size_t &size);

protected:

	bool registrator(const std::string& singletonName, const std::size_t singletonSize);
	
private:
	
	static std::map<std::string, const std::size_t> _registry;
	bool lookUp(const std::string& singletonName);
	void registerInserter(const std::string& singletonName, const std::size_t singletonSize);

};

template<typename Type>
std::map<std::string, const std::size_t> DataSingleton<Type>::_registry;

template<typename Type>
std::shared_ptr<DataSingleton<Type>> DataSingleton<Type>::Instance()
{
	return nullptr;
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

template<typename Type>
bool DataSingleton<Type>::registrator(const std::string& singletonName, const std::size_t singletonSize)
{
	if (lookUp(singletonName))
		return false;

	registerInserter(singletonName, singletonSize);
		return true;
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
void DataSingleton<Type>::registerInserter(const std::string& singletonName, const std::size_t singletonSize)
{
	_registry.insert({ singletonName, singletonSize });
}



