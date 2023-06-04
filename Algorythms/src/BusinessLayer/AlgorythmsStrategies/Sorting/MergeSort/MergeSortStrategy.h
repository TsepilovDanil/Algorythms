#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;
template<typename Type> class ArraySingleton;

template<typename Type>
class MergeSortStrategy : public AlgorythmStrategy<Type>
{
public:

	MergeSortStrategy() = default;
	MergeSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~MergeSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm();

};

template<typename Type>
void MergeSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&MergeSortStrategy::algorythm, this);
	strategyThread.join();
}

template<typename Type>
void MergeSortStrategy<Type>::algorythm()
{
	std::cout << "MergeSortStrategy algorythm" << std::endl;
}



