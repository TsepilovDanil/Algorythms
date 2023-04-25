#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <map>
#include <string>

template <typename Type, const std::size_t Count> 
class DataSourceSingleton
{
protected:

	DataSourceSingleton() = default;
	virtual ~DataSourceSingleton() = default;

	static std::shared_ptr<DataSourceSingleton<Type, Count>> lookUp(std::string &singletonName);

public:
	
	std::shared_ptr<DataSourceSingleton<Type, Count>> Registrator(std::string &singletonName, std::shared_ptr<DataSourceSingleton<Type, Count>>);	
	virtual const Type * const operator[] (const std::size_t index) { return nullptr; }

private:

	static std::map<std::string, std::shared_ptr<DataSourceSingleton<Type, Count>>> _registry;
	std::shared_ptr<DataSourceSingleton<Type, Count>> registerInserter(std::string& singletonName, std::shared_ptr<DataSourceSingleton<Type, Count>>);
};

template<typename Type, std::size_t Count>
std::shared_ptr<DataSourceSingleton<Type, Count>> DataSourceSingleton<Type, Count>::Registrator(std::string& singletonName, std::shared_ptr<DataSourceSingleton<Type, Count>> singletonPtr)
{
	if (singletonName == "array")
	{
		std::pair<std::string, std::shared_ptr<DataSourceSingleton<Type, Count>>> iterator = registerInserter(singletonName, singletonPtr);
		return iterator.second;
	}
	else
		return nullptr;
}

template<typename Type, std::size_t Count>
std::shared_ptr<DataSourceSingleton<Type, Count>> DataSourceSingleton<Type, Count>::registerInserter(std::string& singletonName, std::shared_ptr<DataSourceSingleton<Type, Count>> singletonPtr)
{
	std::pair<std::string, std::shared_ptr<DataSourceSingleton<Type, Count>>> iterator;

	if (!_registry.size())
	{
		iterator = _registry.insert(singletonName, singletonPtr);	
	}
	else
	{
		if (_registry.find(singletonName) == _registry.end())
		{
			iterator = _registry.insert(singletonName, singletonPtr);
		}
		else
		{
			iterator = _registry.find(singletonName);
		}
	}
	return iterator.second;
}
template<typename Type, std::size_t Count>
std::shared_ptr<DataSourceSingleton<Type, Count>> DataSourceSingleton<Type, Count>::lookUp(std::string& singletonName)
{
	//std::pair<std::string, std::shared_ptr<DataSourceSingleton<Type, Count>>> iterator;
	//std::pair<std::string, std::shared_ptr<DataSourceSingleton<Type, Count>> iterator = 
	//auto iterator = _registry.find(singletonName);

	//if (iterator != _registry.end())
	{
		//return iterator.second;
	}
	//else
	{
		return nullptr;
	}
}