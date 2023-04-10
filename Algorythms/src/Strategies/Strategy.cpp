#include "Strategy.h"
#include <thread>

void Strategy::algorythm(void* parameters)
{

}

/*template<typename T, std::size_t S>
bool Strategy<T, S>::StartWork()
{
	//try
	{
		//auto strategyThread = std::thread(&Strategy<T, S>::algorythm, this, (void*)_Composition);
	}
	//catch (const std::exception& exception)
	{
		std::cout << "Cant start Strategy thread" << std::endl;
	}
	return false;
}*/