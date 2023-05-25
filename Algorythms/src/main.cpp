#include <iostream>
#include <memory>
#include <array>
#include <type_traits>
#include <initializer_list>

#include "BusinessLayer/CompositionsFabrics/CompositionsFabric.h"
#include "BusinessLayer/CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"
#include "BusinessLayer/Compositions/Composition.h"
#include "BusinessLayer/Compositions/Sorting/BubbleSort/BubbleSortComposition.h"

int main(int argc, const std::size_t* argv[])
{
    std::initializer_list<const int> list{ 2,1,1 };

    std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*list.begin())>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*list.begin())>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*list.begin())>::type>>(list));
    auto composition = bubbleSortFabric->GetComposition();
    composition->StartAlgorythm();

}

