#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"

template<typename Type, std::size_t Count>
class InsertionSortStrategy : public AlgorythmStrategy<Type, Count>
{
public:

	InsertionSortStrategy() = default;
	~InsertionSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm(std::shared_ptr<Composition<Type, Count>> composition);

};

template<typename Type, std::size_t Count>
void InsertionSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&InsertionSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_composition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void InsertionSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> composition)
{
	std::cout << "InsertionSortStrategy algorythm" << std::endl;
}

