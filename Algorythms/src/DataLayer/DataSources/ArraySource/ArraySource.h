#pragma once

#include "../DataSource.h"

template<typename Type>
class ArraySource : public DataSource<Type>
{

public:

	ArraySource() = default;

	ArraySource(Type* item, std::size_t size);
	ArraySource(std::initializer_list<Type> && initializer);
	
	Type* operator[] (const std::size_t index) override;

	std::shared_ptr <Type> _source = nullptr;

};

template<typename Type>
Type* ArraySource<Type>::operator[] (std::size_t index)
{
	try
	{		
		auto item = &(&*_source)[index];

		return &(&*_source)[index];
	}
	catch (const std::exception& exception)
	{
		std::cout << "ArraySource<Type>::operator[] exception: " << exception.what() << std::endl;
	}
	return nullptr;
}

template<typename Type>
ArraySource<Type>::ArraySource(Type *initializationMemory, std::size_t size)
{
	if (!size)
		return;

	_source = std::shared_ptr<Type>(new Type[size], [](Type* p) {delete[] p; });

	for (std::size_t indexInArray = 0; indexInArray < size; ++indexInArray)
	{
		(&*_source)[indexInArray] = initializationMemory[indexInArray];
	}

	DataSource<Type>::_sizeOfSource = size;

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

	DataSource<Type>::_sizeOfSource = initializer.size();
}

