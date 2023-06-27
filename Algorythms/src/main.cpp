#include "main.h"


int main()
{
    std::initializer_list<int> list{ 9,8,7,6,5,4,3,2,1 };
    
    if (!list.size())
        return 0;

    

    auto bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
    bubbleSortFabric->GetComposition()->StartAlgorythm();

	auto insertionSortFabric = std::make_shared<InsertionSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
    insertionSortFabric->GetComposition()->StartAlgorythm();

    auto mergeSortFabric = std::make_shared<MergeSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
    mergeSortFabric->GetComposition()->StartAlgorythm();

    auto quickSortFabric = std::make_shared<QuickSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	quickSortFabric->GetComposition()->StartAlgorythm();

    auto selectionSortFabric = std::make_shared<SelectionSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	selectionSortFabric->GetComposition()->StartAlgorythm();

}

