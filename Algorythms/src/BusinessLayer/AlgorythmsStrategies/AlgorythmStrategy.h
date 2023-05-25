#pragma once
#include <iostream>
#include <thread>
#include "../compositions/Composition.h"

template<typename Type> class Composition;

template<typename Type>
class AlgorythmStrategy
{
public:
	AlgorythmStrategy() = default;
	AlgorythmStrategy(std::shared_ptr<Composition<Type>> composition) : _composition(composition) {};
	virtual ~AlgorythmStrategy() = default;

	virtual void StartWork();

	void SetComposition(std::shared_ptr<Composition<Type>> composition) { _composition = composition; };

private:

	void algorythm() { std::cout << "AlgorythmStrategy algorythm" << std::endl; };

protected:

	std::shared_ptr<Composition<Type>> _composition;
	
};

template<typename Type>
void AlgorythmStrategy<Type>::StartWork()
{
	auto strategyThread = std::thread(&AlgorythmStrategy::algorythm, this);
	strategyThread.join();
}




