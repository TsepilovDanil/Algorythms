
#include <iostream>
#include <memory>
#include "CompositionsFabrics/CompositionsFabric.h"
#include "CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"

#include "Compositions/Composition.h"
#include "Compositions/Sorting/BubbleSort/BubbleSortComposition.h"
#include "DataSources/DataSource.h"
#include "DataSources/ArraySource/ArraySource.h"

template<typename ProcessinElementType, std::size_t ElementCount> class CompositionsFabric;
template<typename ProcessinElementType, std::size_t ElementCount> class BubbleSortFabric;

int main()
{
    //unsigned long var = 0;
    //std::cout << "var = " << var << std::endl;
    //std::cout << "var = " << var << std::endl;

    std::shared_ptr<CompositionsFabric<int, 10>> bubbleSortFabric = std::make_shared<BubbleSortFabric<int, 10>>();

    auto composition = bubbleSortFabric->GetComposition();

    composition->_Strategy->StartWork();

    DataSource<int, 1> ds;
    ArraySource<int, 1> as;

    std::cout << "ds = " << ds[0] << " as = " << as[0] << std::endl;
}

