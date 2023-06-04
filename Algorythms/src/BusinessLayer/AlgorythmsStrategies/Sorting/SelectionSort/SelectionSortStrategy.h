#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;
template<typename Type> class ArraySingleton;

template<typename Type>
class SelectionSortStrategy : public AlgorythmStrategy<Type>
{
public:

	SelectionSortStrategy() = default;
	SelectionSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~SelectionSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm();

};

template<typename Type>
void SelectionSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&SelectionSortStrategy::algorythm, this);
	strategyThread.join();
}

template<typename Type>
void SelectionSortStrategy<Type>::algorythm()
{
	std::cout << "SelectionSortStrategy algorythm" << std::endl;
}

