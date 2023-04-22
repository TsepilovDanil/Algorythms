#pragma once
#include "../../Strategy.h"
#include "../../../compositions/Composition.h"
#include "../../../compositions/sorting/bubblesort/BubbleSortComposition.h"

template<typename Type, std::size_t Count>
class BubbleSortStrategy : public Strategy<Type, Count>
{
public:
	BubbleSortStrategy() = default;
	//BubbleSortStrategy(Composition* composition) : Strategy(composition) { std::cout << "BubbleSortStrategy" << std::endl; };
	~BubbleSortStrategy() = default;

	void StartWork() override;

	/*
	template<typename Type, std::size_t Count>
	void algorythm(ArrayStorage<Type, Count>* storage) {



	};
	*/

	void algorythm() { std::cout << "BubbleSortStrategy algorythm" << std::endl; };

};

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::StartWork()
{
	std::shared_ptr<ArrayStorage<Type, Count>> storage = std::make_shared<ArrayStorage<Type, Count>>();
	
	//auto strategyThread = std::thread(&BubbleSortStrategy::algorythm<Type, Count>, this, (ArrayStorage<Type, Count> *) & storage);

	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this);

	strategyThread.join();
}





