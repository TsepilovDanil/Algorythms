#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <string>

template <typename Type, const std::size_t Count> 
class DataSourceSingleton
{
protected:

	DataSourceSingleton() = default;
	

	static bool lookUp(const std::string& singletonName);

public:
	virtual ~DataSourceSingleton() = default;

	static bool Registrator(const std::string &singletonName);	
	virtual Type * operator[] (const std::size_t index) {return nullptr;}

	static std::set<std::string> _registry;

private:
	
	
	static void registerInserter(const std::string& singletonName);
};

template<typename Type, std::size_t Count>
std::set<std::string> DataSourceSingleton<Type, Count>::_registry;

template<typename Type, std::size_t Count>
bool DataSourceSingleton<Type, Count>::Registrator(const std::string& singletonName)
{
	if (singletonName == "array")
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