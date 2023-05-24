#pragma once

#include "../../Iterators/ForwardIterator/ForwardIterator.h"
#include "../DataSource.h"

template<typename Type, std::size_t Count>
class ArraySource : public DataSource<Type, Count>
{

public:

	std::size_t s = 5;

	ArraySource() : _array((new Type[s], [](Type* p) {delete[] p; })) {};

	//ArraySource(std::initializer_list<Type> initialization) : _arraySource(std::make_shared<std::array<Type, Count>>(initialization, initialization.size())) {};

	Type* operator[] (const std::size_t index) override;

	std::shared_ptr<std::array<Type, Count>> _arraySource = nullptr;

	std::shared_ptr<Type> _array;

	std::shared_ptr<Iterator<Type, Count>> GetForwardIterator() override;

};

template<typename Type, std::size_t Count>
Type* ArraySource<Type, Count>::operator[] (std::size_t index)
{
	try
	{
		return &_arraySource->at(index);
	}
	catch (const std::exception& exception)
	{
		std::cout << "ArraySourceSingleton<Type, Count>::operator[] exception: " << exception.what() << std::endl;
	}
	return nullptr;
}

template<typename Type, std::size_t Count>
std::shared_ptr<Iterator<Type, Count>> ArraySource<Type, Count>::GetForwardIterator()
{
	return std::make_shared<ForwardIterator<Type, Count>>(this);
}

