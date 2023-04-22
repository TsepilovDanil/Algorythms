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
	

private:

	template<typename Type, std::size_t Count>
	void launch(void)
	{
		std::shared_ptr<ArrayStorage<Type, Count>> storage = std::make_shared<ArrayStorage<Type, Count>>();
		
		//auto strategyThread = std::thread(&Strategy::algorythm<T, storage->getSize()>, this, (ArrayStorage<T, storage->getSize()> *)&storage2);

		//algorythm<T, S>(storage);
		
		/*if (typeid(storage) == typeid(Storage<int> *))
		{
			algorythm<int, S>(&storage);
		}*/

		//if (std::is_same<T, int>::value)
		{
			//algorythm<T, S>(&storage);
		}
	};

	template<typename Type , std::size_t Count>
	void algorythm(ArrayStorage<Type, Count> * storage) {
		
		

	};
	
};

template<typename Type, std::size_t Count>
void Strategy<Type, Count>::StartWork()
{
	std::shared_ptr<ArrayStorage<Type, Count>> storage = std::make_shared<ArrayStorage<Type, Count>>();

	auto strategyThread = std::thread(&Strategy::algorythm<Type, Count>, this, (ArrayStorage<Type, Count> *) &storage);

	//launch<Type, Count>();

	//try
	{
		//auto strategyThread = std::thread(&Strategy::launch<int, 10>, this, (Storage<int, 10> *)storageType);

		//if (std::is_same<T, int>::value)
		{
			//algorythm<T, S>(&storage);
		}

		//if (typeid(storageType) == typeid(Storage<int, size> *))
		{
			//Storage<int> * ptr = (Storage<int> *)storageType;
			//auto strategyThread = std::thread(&Strategy::launch<int, getSize(1)>, this, (Storage<int, getSize(1)> *)storageType);
		}



		//thread my_thread([](auto x) { my_function(x); }, 10)
		int a = 9;

		//auto strategyThread = std::thread(&Strategy::algorythm<ArrayStorage<int, 10>>, this, &storage);

		//auto strategyThread = std::thread(&Strategy::algorythm<int, 10>, this, &storage);


		//auto strategyThread = std::thread(&Strategy::algorythm, this, (ArrayStorage<int, 10> *)&_Composition);
		//strategyThread.join();
	}
	//catch (const std::exception& exception)
	{
		//std::cout << "Cant start Strategy thread" << std::endl;
	}
}




