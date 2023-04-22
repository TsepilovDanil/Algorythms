
#include <iostream>
#include <memory>
#include "CompositionsFabrics/CompositionsFabric.h"
#include "CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"

#include "Compositions/Composition.h"
#include "Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "Storage/ArrayStorage/ArrayStorage.h"

template<typename ProcessinElementType, std::size_t ElementCount> class CompositionsFabric;
template<typename ProcessinElementType, std::size_t ElementCount> class BubbleSortFabric;

int main()
{
    std::cout << "Hello World!\n";

    std::shared_ptr<CompositionsFabric<int, 10>> bubbleSortFabric = std::make_shared<BubbleSortFabric<int, 10>>();

    //auto composition = bubbleSortFabric->GetComposition();

}

