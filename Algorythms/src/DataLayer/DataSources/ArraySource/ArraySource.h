#pragma once

#include "../../Iterators/ForwardIterator/ForwardIterator.h"
#include "../DataSource.h"

template<typename Type>
class ArraySource : public DataSource<Type>
{

public:

	ArraySource() = default;

	ArraySource(std::size_t sizeOfSource);
	ArraySource(std::initializer_list<Type> && initializer);

	void SetIterator(std::shared_ptr<Iterator<Type>> iterator) override { DataSource<Type>::_iterator = iterator; }
	Type* operator[] (const std::size_t index) override;

	std::shared_ptr <Type> _source = nullptr;

};

template<typename Type>
Type* ArraySource<Type>::operator[] (std::size_t index)
{
	try
	{		
		return &(&*_source)[index];
	}
	catch (const std::exception& exception)
	{
		std::cout << "ArraySource<Type>::operator[] exception: " << exception.what() << std::endl;
	}
	return nullptr;
}

template<typename Type>
ArraySource<Type>::ArraySource(std::size_t sizeOfSource)
{

}

template<typename Type>
ArraySource<Type>::ArraySource(std::initializer_list<Type> &&initializer)
{
	if (!initializer.size())
		return;
	
	DataSource<Type>::_sizeOfSource = initializer.size();
	//may be it is need to replace by an allocator 
	_source = std::shared_ptr<Type>(new Type[initializer.size()], [](Type* p) {delete[] p; });
	
	std::size_t sourceIndex = 0;

	for (auto initializerIterator = initializer.begin(); initializerIterator != initializer.end(); ++initializerIterator)
	{
		(&*_source)[sourceIndex++] = *initializerIterator;
	}
}

