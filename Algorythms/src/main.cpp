#include <iostream>
#include <memory>
#include "CompositionsFabrics/CompositionsFabric.h"
#include "CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"
#include "Compositions/Composition.h"
#include "Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "DataSources/ArraySource/ArraySourceSingleton.h"

typedef int DataSourceType;
#define DataSourceSize 10

int main()
{
    //unsigned long var = 0;
    //std::cout << "uvar = " << var << std::endl;
    //std::cout << "var = " << var << std::endl;

    

    std::shared_ptr<CompositionsFabric<DataSourceType, DataSourceSize>> bubbleSortFabric = std::make_shared<BubbleSortFabric<DataSourceType, DataSourceSize>>();
    auto composition = bubbleSortFabric->GetComposition();
    composition->StartAlgorythm();

}

