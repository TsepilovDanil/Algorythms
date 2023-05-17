#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"

template<typename Type, std::size_t Count>
class SelectionSortStrategy : public AlgorythmStrategy<Type, Count>
{
public:

	SelectionSortStrategy() = default;
	~SelectionSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm(std::shared_ptr<Composition<Type, Count>> composition);
	
};

template<typename Type, std::size_t Count>
void SelectionSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&SelectionSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_composition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void SelectionSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> composition)
{
	std::cout << "SelectionSortStrategy algorythm" << std::endl;
}

