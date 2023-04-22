#pragma once

#include <iostream>
#include <thread>
#include "../compositions/Composition.h"
#include "../Storage/ArrayStorage/ArrayStorage.h"

template<typename Type, std::size_t Count> class Composition;

template<typename Type, std::size_t Count>
class Strategy
{
public:

	Strategy() = default;
	virtual ~Strategy() = default;

	std::shared_ptr<Composition<Type, Count>> _Composition;

	void SetComposition(std::shared_ptr<Composition<Type, Count>> composition) { _Composition = composition; };
	
	virtual void StartWork();

protected:

	void algorythm() { std::cout << "Strategy algorythm" << std::endl; };
	
};

template<typename Type, std::size_t Count>
void Strategy<Type, Count>::StartWork()
{
	auto strategyThread = std::thread(&Strategy::algorythm, this);

	strategyThread.join();
}




