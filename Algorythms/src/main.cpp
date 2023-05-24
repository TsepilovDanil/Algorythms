#include <iostream>
#include <memory>
#include <array>
#include <type_traits>
#include <initializer_list>

#include "BusinessLayer/CompositionsFabrics/CompositionsFabric.h"
#include "BusinessLayer/CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"
#include "BusinessLayer/Compositions/Composition.h"
#include "BusinessLayer/Compositions/Sorting/BubbleSort/BubbleSortComposition.h"

typedef int DataSourceType;
#define DataSourceSize 4

int main(int argc, const std::size_t* argv[])
{
    std::initializer_list<int> list{ 1,1,1 };


    std::shared_ptr < CompositionsFabric < std::remove_reference<decltype(*list.begin())>::type, DataSourceSize >> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*list.begin())>::type, DataSourceSize>>();
    auto composition = bubbleSortFabric->GetComposition();
    composition->StartAlgorythm();

}

