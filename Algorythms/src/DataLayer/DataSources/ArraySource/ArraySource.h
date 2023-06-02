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
		//return (&*_source)[index];;
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
	Type item0 = (*_source + 0);
	Type item1 = (*_source + 1);
	
	//auto intSource = std::shared_ptr<int>(new int[3]{ 1, 2, 3 }, [](int* p) {delete[] p; });
	//auto intSource = std::shared_ptr<std::string>(new std::string[3]{ "a", "b", "c"}, [](std::string* p) {delete[] p; });
	//auto intSource = std::shared_ptr<char>(new char[3]{ 'a', 'b', 'c' }, [](char* p) {delete[] p; });
	//std::string strs[3] = { "a", "b", "c" };//new std::string[3]{ "a", "b", "c" };
	//auto item2 = (*intSource + 0);
	//auto item3 = (*intSource + 1);
	
	std::size_t sourceIndex = 0;

	//auto source1 = (&*_source)[0];
	//auto source2 = (&*_source)[1];
	//auto source3 = (&*_source)[2];
	//auto source4 = (&*_source)[3];

	

	for (auto initializerIterator = initializer.begin() ; initializerIterator != initializer.end(); ++initializerIterator)
	{
		auto source = (&*_source)[sourceIndex];
		auto initList = *initializerIterator;
		(&*_source)[sourceIndex++] = *initializerIterator;
	}

	auto source1 = *(&*_source);
	auto source2 = *(&*_source + 1);
	auto source3 = *(&*_source + 2);
	auto source4 = *(&*_source + 3);

	//auto val = (_source.get())[0];
}

