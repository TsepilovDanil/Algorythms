#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"

template<typename Type, std::size_t Count>
class QuickSortStrategy : public AlgorythmStrategy<Type, Count>
{
public:

	QuickSortStrategy() = default;
	~QuickSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm(std::shared_ptr<Composition<Type, Count>> composition);
	
};

template<typename Type, std::size_t Count>
void QuickSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&QuickSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_composition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void QuickSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> composition)
{
	std::cout << "QuickSortStrategy algorythm" << std::endl;
}



