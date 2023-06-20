#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"
#include "../../../../DataLayer/DataSources/ArraySource/ArraySource.h"


template<typename Type> class Composition;
template<typename Type> class AlgorythmStrategy;
template<typename Type> class DataSingleton;
template<typename Type> class ArraySingleton;
template<typename Type> class ArraySource;

template<typename Type>
class BubbleSortStrategy : public AlgorythmStrategy<Type>
{
public:

	BubbleSortStrategy() = default;
	BubbleSortStrategy(std::shared_ptr<Composition<Type>> composition) : AlgorythmStrategy(composition) {};
	~BubbleSortStrategy() = default;

	void StartWork() override;

private:
	
	void algorythm();

};

template<typename Type>
void BubbleSortStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this);
	strategyThread.join();
}

template<typename Type>
void BubbleSortStrategy<Type>::algorythm()
{
	std::cout << "BubbleSortStrategy algorythm" << std::endl;

	if (!AlgorythmStrategy<Type>::_composition || !AlgorythmStrategy<Type>::_composition->_dataSingleton)
	{
		std::cout << "BubbleSortStrategy algorythm: wrong parameters - emergency exit" << std::endl;
		return;
	}

	std::shared_ptr<DataSingleton<Type>> singletone = AlgorythmStrategy<Type>::_composition->_dataSingleton->Instance();

	std::size_t singletoneSize;
	if (!singletone || !singletone->GetSingletoneSize(ArraySingleton<Type>::_singletonName, singletoneSize))
		return;

	ArraySource<Type> workArray((*singletone)[0], singletoneSize);
	ArraySource<Type> copyArray(workArray);

	std::cout << "Original array     : ";
	for (int i = 0; i < workArray.GetSize(); ++i) {
		std::cout << *(workArray)[i];
	}
	std::cout << std::endl;
	
	bool swapped;

	do
	{
		swapped = false;
		for (std::size_t i = 1; i < workArray.GetSize(); ++i) {
			if (*(workArray)[i - 1] > *(workArray)[i])
			{
				AlgorythmStrategy<Type>::swap((workArray)[0], i - 1, i);
				swapped = true;

				std::cout << "Valued iteration   : ";
				
				for (int i = 0; i < workArray.GetSize(); ++i) {
					std::cout << *(workArray)[i];
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Empty iteration    : " << std::endl;;
			}
		}

		if (swapped)
		{
			std::cout << "Outer iteration    :*";
			for (int i = 0; i < workArray.GetSize(); ++i) {
				std::cout << *(workArray)[i];
			}
			std::cout << "*" << std::endl;
		}
		

	} while (swapped != false);

}





