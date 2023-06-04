#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;
template<typename Type> class ArraySingleton;

template<typename Type>
class InsertionSortStrategy : public AlgorythmStrategy<Type>
{
public:

	InsertionSortStrategy() = default;
	InsertionSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~InsertionSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm();

};

template<typename Type>
void InsertionSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&InsertionSortStrategy::algorythm, this);
	strategyThread.join();
}

template<typename Type>
void InsertionSortStrategy<Type>::algorythm()
{
	std::cout << "InsertionSortStrategy algorythm" << std::endl;
}

