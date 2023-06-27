#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../Compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;
template<typename Type> class ArraySingleton;

template<typename Type>
class QuickSortStrategy : public AlgorythmStrategy<Type>
{
public:

	QuickSortStrategy() = default;
	//QuickSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~QuickSortStrategy() = default;

	void StartWork() override;

private:

	void algorythm();

};

template<typename Type>
void QuickSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&QuickSortStrategy::algorythm, this);
	strategyThread.join();
}

template<typename Type>
void QuickSortStrategy<Type>::algorythm()
{
	std::cout << "QuickSortStrategy algorythm" << std::endl;
}



