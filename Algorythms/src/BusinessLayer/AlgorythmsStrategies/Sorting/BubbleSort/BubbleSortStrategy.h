#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;

template<typename Type>
class BubbleSortStrategy : public AlgorythmStrategy<Type>
{
public:

	BubbleSortStrategy() = default;
	BubbleSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~BubbleSortStrategy() = default;

	void StartWork() override;

private:
	
	void algorythm(std::shared_ptr<Composition<Type>> composition);

};

template<typename Type>
void BubbleSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this, AlgorythmStrategy<Type>::_composition);
	strategyThread.join();
}

template<typename Type>
void BubbleSortStrategy<Type>::algorythm(std::shared_ptr<Composition<Type>> composition)
{
	std::cout << "BubbleSortStrategy algorythm" << std::endl;
	Composition<Type> _composition = *composition;

	auto val = *(*_composition._dataSourceSingleton)[0];

	Swap(&*(*_composition._dataSourceSingleton)[0], 0, 1);

	auto val2 = *(*_composition._dataSourceSingleton)[0];

	//_composition.
	//auto ptr = composition;
	//(*((*composition)._dataSourceSingleton))[0];
	//auto item = *(*ArraySourceSingleton<Type, Count>::Instance())[0];
	//std::cout << "((Composition<Type, Count>) * composition)->_dataSourceSingleton->operator [0]: " << *(*ArraySingleton<Type, Count>::Instance())[0] << std::endl;

}





