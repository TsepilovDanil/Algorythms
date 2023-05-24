#pragma once
#include "../../AlgorythmStrategy.h"
#include "../../../compositions/Composition.h"
#include "../../../../DataLayer/Singletones/ArraySingleton/ArraySingleton.h"

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
	
	void algorythm(std::shared_ptr<Composition<Type, Count>> composition);

};

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&BubbleSortStrategy::algorythm, this, AlgorythmStrategy<Type, Count>::_composition);
	strategyThread.join();
}

template<typename Type, std::size_t Count>
void BubbleSortStrategy<Type, Count>::algorythm(std::shared_ptr<Composition<Type, Count>> composition)
{
	std::cout << "BubbleSortStrategy algorythm" << std::endl;
	//auto ptr = composition;
	//(*((*composition)._dataSource))[0];
	//auto item = *(*ArraySourceSingleton<Type, Count>::Instance())[0];
	//std::cout << "((Composition<Type, Count>) * composition)->_dataSource->operator [0]: " << *(*ArraySingleton<Type, Count>::Instance())[0] << std::endl;

}





