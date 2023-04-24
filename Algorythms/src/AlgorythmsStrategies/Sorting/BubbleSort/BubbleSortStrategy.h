#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"

template<typename Type, std::size_t Count> class Composition;
template<typename Type, std::size_t Count> class AlgorythmStrategy;

template<typename Type, std::size_t Count>
class BubbleSortStrategy : public AlgorythmStrategy<Type, Count>
{
public:

	BubbleSortStrategy() = default;
	~BubbleSortStrategy() = default;

	void StartWork() override;

private:
	
	void algorythm(std::shared_ptr<Composition<Type, Count>> aComposition);

};

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_aComposition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> aComposition)
{
	std::cout << "BubbleSortStrategy algorythm" << std::endl;
}





