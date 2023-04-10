#include "BubbleSortFabric.h"
#include "../../../Strategies/Sorting/BubbleSort/BubbleSortStrategy.h"

std::shared_ptr<Composition> BubbleSortFabric::GetComposition()
{
	auto strategy = std::make_shared<BubbleSortStrategy>();
	return std::make_shared<BubbelSortComposition>(strategy);
}
