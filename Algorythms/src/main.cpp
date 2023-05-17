#include <iostream>
#include <memory>
#include <array>

#include "BusinessLayer/CompositionsFabrics/CompositionsFabric.h"
#include "BusinessLayer/CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"
#include "BusinessLayer/Compositions/Composition.h"
#include "BusinessLayer/Compositions/Sorting/BubbleSort/BubbleSortComposition.h"

typedef int DataSourceType;
#define DataSourceSize 10

int main(int argc, const std::size_t* argv[])
{
    std::array<int, 3> ar({1,1,1});
    //std::size_t var = 0;
    //std::cout << "var = " << var << std::endl;
    //std::cin >> var;

    std::shared_ptr < CompositionsFabric < DataSourceType, DataSourceSize >> bubbleSortFabric = std::make_shared<BubbleSortFabric<DataSourceType, DataSourceSize>>();
    auto composition = bubbleSortFabric->GetComposition();
    composition->StartAlgorythm();

}

