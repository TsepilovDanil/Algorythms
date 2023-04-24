#pragma once

#include <iostream>
#include <thread>
#include "../compositions/Composition.h"

template<typename Type, std::size_t Count> class Composition;

template<typename Type, std::size_t Count>
class AlgorythmStrategy
{
public:

	AlgorythmStrategy() = default;
	virtual ~AlgorythmStrategy() = default;

	virtual void StartWork();

private:

	void algorythm() { std::cout << "Strategy algorythm" << std::endl; };

protected:

	std::shared_ptr<Composition<Type, Count>> _aComposition;
	
};

template<typename Type, std::size_t Count>
void AlgorythmStrategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&AlgorythmStrategy::algorythm, this);
	strategyThread.join();
}




