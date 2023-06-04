#include "main.h"

int main(int argc, const std::size_t* argv[])
{
    std::initializer_list<int> list{ 9,8,7,6,5,4,3,2,1 };
    //std::initializer_list<char> list{ 'a','b','c'};

    if (!list.size())
        return 0;

    std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
    //std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
    bubbleSortFabric->GetComposition()->StartAlgorythm();

	std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> insertionSortFabric = std::make_shared<InsertionSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	//std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
    insertionSortFabric->GetComposition()->StartAlgorythm();

	std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> mergeSortFabric = std::make_shared<MergeSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	//std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
    mergeSortFabric->GetComposition()->StartAlgorythm();

	std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> quickSortFabric = std::make_shared<QuickSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	//std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
	quickSortFabric->GetComposition()->StartAlgorythm();

	std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>> selectionSortFabric = std::make_shared<SelectionSortFabric<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<int*>(list.begin()))>::type>>(list));
	//std::shared_ptr <CompositionsFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>> bubbleSortFabric = std::make_shared<BubbleSortFabric<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(std::forward<std::initializer_list<std::remove_reference<decltype(*const_cast<char*>(list.begin()))>::type>>(list));
	selectionSortFabric->GetComposition()->StartAlgorythm();

}

