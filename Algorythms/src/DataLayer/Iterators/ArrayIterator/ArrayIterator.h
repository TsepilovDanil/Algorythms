#pragma once
#include <array>
#include <memory>
#include "../Iterator.h"

template<typename Type, std::size_t Count>
class ArrayIterator : public Iterator<Type, Count>
{
	ArrayIterator() = default;
	//ArrayIterator(std::shared_ptr<std::array<Type, Count>> arraySource) : _arraySource(arraySource) {};
	~ArrayIterator() = default;

	void First() override;
	void Next() override;
	bool IsDone() override;
	Type* CurrentItem() override;

private:

	static std::shared_ptr<std::array<Type, Count>> _arraySource;

};

template<typename Type, std::size_t Count>
void ArrayIterator<Type, Count>::First()
{

}

template<typename Type, std::size_t Count>
void ArrayIterator<Type, Count>::Next()
{

}

template<typename Type, std::size_t Count>
bool ArrayIterator<Type, Count>::IsDone()
{

}

template<typename Type, std::size_t Count>
Type* ArrayIterator<Type, Count>::CurrentItem()
{

}

