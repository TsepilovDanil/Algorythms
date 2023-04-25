#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"

template<typename Type, std::size_t Count>
class MergeSortStrategy : public AlgorythmStrategy<Type, Count>
{
public:

	MergeSortStrategy() = default;
	~MergeSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm(std::shared_ptr<Composition<Type, Count>> composition);

	
};

template<typename Type, std::size_t Count>
void MergeSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&MergeSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_composition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void MergeSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> composition)
{
	std::cout << "MergeSortStrategy algorythm" << std::endl;
}



