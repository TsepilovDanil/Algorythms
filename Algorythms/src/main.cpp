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
    std::initializer_list<int> list{ 9,8,7,6,5,4,3,2,1 };
    //std::initializer_list<char> list{ 'a','b','c'};

    if (!list.size())
        return 0;

    std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
    //std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
    auto composition = bubbleSortFabric->GetComposition();
    composition->StartAlgorythm();

}

