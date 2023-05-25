#pragma once
#include <array>
#include <memory>
#include "../Iterator.h"

template<typename Type>
class ForwardIterator : public Iterator<Type>
{
	ForwardIterator() = default;
	ForwardIterator(std::shared_ptr<DataSource<Type>> dataSource) : Iterator<Type>(dataSource) {};
	~ForwardIterator() = default;

	void First() override;
	void Next() override;
	bool IsDone() override;
	Type& CurrentItem() override;

};

template<typename Type>
void ForwardIterator<Type>::First()
{

}

template<typename Type>
void ForwardIterator<Type>::Next()
{

}

template<typename Type>
bool ForwardIterator<Type>::IsDone()
{

}

template<typename Type>
Type& ForwardIterator<Type>::CurrentItem()
{

}

