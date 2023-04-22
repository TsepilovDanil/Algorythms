#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../../../compositions/sorting/bubblesort/BubbleSortComposition.h"

template<typename Type, std::size_t Count> class Composition;
template<typename Type, std::size_t Count> class Strategy;

template<typename Type, std::size_t Count>
class BubbleSortStrategy : public Strategy<Type, Count>
{
public:

	BubbleSortStrategy() = default;
	~BubbleSortStrategy() = default;

	void StartWork() override;

private:

	std::shared_ptr<ArrayStorage<Type, Count>> _storage;
	void algorythm(std::shared_ptr<ArrayStorage<Type, Count>> storage);

};

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::StartWork()
{
	_storage = std::make_shared<ArrayStorage<Type, Count>>();
	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this, _storage);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::algorythm(std::shared_ptr<ArrayStorage<Type, Count>> storage)
{
	std::cout << "BubbleSortStrategy algorythm" << std::endl;
}





