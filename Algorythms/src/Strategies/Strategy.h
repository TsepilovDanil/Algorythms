#pragma once

#include <iostream>
#include <thread>
#include "../compositions/Composition.h"
#include "../Storage/ArrayStorage/ArrayStorage.h"

class Composition;

constexpr std::size_t getSize(const std::size_t size) { return size; };

class Strategy
{
public:

	Strategy() = default;
	Strategy(Composition* composition) : _Composition(composition) {};
	virtual ~Strategy() = default;

	Composition * _Composition;
	

	void StartWork(void * storageType, const std::size_t size) {
		
		launch<int, StorageSize>();
		
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
	};

private:

	template<typename T, const std::size_t S>
	void launch(void)
	{
		std::shared_ptr<ArrayStorage<T, S>> storage = std::make_shared<ArrayStorage<T, S>>();
		
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

	template<typename T , std::size_t S>
	void algorythm(ArrayStorage<T, S> * storage) {
		
		if (std::is_same<T, int>::value)
			int a = 0;

		storage->_Array.size();

		ArrayStorage<T, storage->_Array.size()> * storage2;

	};
	
};






