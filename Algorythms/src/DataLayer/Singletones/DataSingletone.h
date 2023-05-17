#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <string>
#include "../Iterators/Iterator.h"
#include "ArraySingleton/ArraySingleton.h"

template <typename Type, const std::size_t Count> class ArraySourceSingleton;

template <typename Type, const std::size_t Count> 
class DataSourceSingleton : public Iterator<Type, Count>
{
protected:

	DataSourceSingleton() = default;

public:
	
	virtual ~DataSourceSingleton() = default;
	
	//virtual void function() {};
	//virtual int function(int value) { return value; };
	virtual float function(float value) { return value; };

	static bool Registrator(const std::string &singletonName);	
	virtual Type * const operator[] (const std::size_t index) {return nullptr;}

protected:

	static bool lookUp(const std::string& singletonName);

private:
	
	static std::set<std::string> _registry;
	static void registerInserter(const std::string& singletonName);

};

template<typename Type, std::size_t Count>
std::set<std::string> DataSourceSingleton<Type, Count>::_registry;

template<typename Type, std::size_t Count>
bool DataSourceSingleton<Type, Count>::Registrator(const std::string& singletonName)
{
	if (singletonName == ArraySourceSingleton<Type, Count>::_singletonName)
	{
		registerInserter(singletonName);
		return true;
	}
	else
		return false;
}

template<typename Type, std::size_t Count>
void DataSourceSingleton<Type, Count>::registerInserter(const std::string& singletonName)
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
bool DataSourceSingleton<Type, Count>::lookUp(const std::string& singletonName)
{
	if (_registry.find(singletonName) != _registry.end())
	{
		return true;
	}
	return false;
}