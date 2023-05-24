#pragma once
#include <array>
#include <memory>
#include "../Iterator.h"

template<typename Type, std::size_t Count>
class ForwardIterator : public Iterator<Type, Count>
{
	ForwardIterator() = default;
	ForwardIterator(std::shared_ptr<DataSource<Type, Count>> dataSource) : Iterator<Type, Count>(dataSource) {};
	~ForwardIterator() = default;

	void First() override;
	void Next() override;
	bool IsDone() override;
	Type& CurrentItem() override;

};

template<typename Type, std::size_t Count>
void ForwardIterator<Type, Count>::First()
{

}

template<typename Type, std::size_t Count>
void ForwardIterator<Type, Count>::Next()
{

}

template<typename Type, std::size_t Count>
bool ForwardIterator<Type, Count>::IsDone()
{

}

template<typename Type, std::size_t Count>
Type& ForwardIterator<Type, Count>::CurrentItem()
{

}

