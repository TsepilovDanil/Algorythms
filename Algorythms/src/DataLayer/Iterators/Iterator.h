#pragma once
#include <cstddef>
#include "../DataSources/DataSource.h"

template<typename Type, std::size_t Count> class DataSource;

template<typename Type, std::size_t Count>
class Iterator
{
public:

	Iterator() = default;
	Iterator(std::shared_ptr<DataSource<Type, Count>> dataSource) : _DataSource(dataSource) {};
	virtual ~Iterator() = default;

	virtual void First() {};
	virtual void Next() {};
	virtual bool IsDone() { return false; };
	virtual Type& CurrentItem() { return nullptr; };

	std::shared_ptr<DataSource<Type, Count>> _DataSource = nullptr;

protected:

	std::size_t _currentItemIndex = 0;
};

