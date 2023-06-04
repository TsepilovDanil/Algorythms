#pragma once
#include <iostream>
#include <memory>
#include <array>
#include <type_traits>
#include <initializer_list>

#include "BusinessLayer/CompositionsFabrics/CompositionsFabric.h"
#include "BusinessLayer/Compositions/Composition.h"

#include "BusinessLayer/CompositionsFabrics/Sorting/BubbleSort/BubbleSortFabric.h"
#include "BusinessLayer/Compositions/Sorting/BubbleSort/BubbleSortComposition.h"

#include "BusinessLayer/CompositionsFabrics/Sorting/InsertionSort/InsertionSortFabric.h"
#include "BusinessLayer/Compositions/Sorting/InsertionSort/InsertionSortComposition.h"

#include "BusinessLayer/CompositionsFabrics/Sorting/MergeSort/MergeSortFabric.h"
#include "BusinessLayer/Compositions/Sorting/MergeSort/MergeSortComposition.h"

#include "BusinessLayer/CompositionsFabrics/Sorting/QuickSort/QuickSortFabric.h"
#include "BusinessLayer/Compositions/Sorting/QuickSort/QuickSortComposition.h"

#include "BusinessLayer/CompositionsFabrics/Sorting/SelectionSort/SelectionSortFabric.h"
#include "BusinessLayer/Compositions/Sorting/SelectionSort/SelectionSortComposition.h"
