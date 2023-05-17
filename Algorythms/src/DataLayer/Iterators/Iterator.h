#pragma once
#include <cstddef>

template<typename Type, std::size_t Count>
class Iterator
{
public:

	Iterator() = default;
	virtual ~Iterator() = default;

	virtual void First() {};
	virtual void Next() {};
	virtual bool IsDone() { return false; };
	virtual Type* CurrentItem() { return nullptr; };

protected:

	std::size_t _currentItemIndex = 0;
};

