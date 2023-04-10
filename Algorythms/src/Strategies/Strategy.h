#pragma once

#include <iostream>
#include <thread>
#include "../compositions/Composition.h"

class Composition;

class Strategy
{
public:

	Strategy() = default;
	Strategy(Composition* composition) : _Composition(composition) {};
	virtual ~Strategy() = default;

	Composition * _Composition;

	/*virtual void StartWork() {
		try
		{
			auto strategyThread = std::thread(&Strategy<T, S>::algorythm, this, (void*)_Composition);
			strategyThread.join();
		}
		catch (const std::exception& exception)
		{
			std::cout << "Cant start Strategy thread" << std::endl;
		}
	};*/

private:
	
	void algorythm(void*);
};






