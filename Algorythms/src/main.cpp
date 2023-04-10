
#include <iostream>
#include <memory>
#include "CompositionsFabrics/CompositionsFabric.h"
#include "CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"

#include "Compositions/Composition.h"


int main()
{
    std::cout << "Hello World!\n";

    std::shared_ptr<CompositionsFabric> bubbleSortFabric = std::make_shared<BubbleSortFabric>();

    auto composition = bubbleSortFabric->GetComposition();

}

