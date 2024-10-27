#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"

int main()
{
	// collection sizes
	std::vector<size_t> s = { 2000, 5000, 10000, 15000, 20000, 30000, 40000, 50000, 100000,150000, 200000, 300000, 400000, 500000, 600000, 800000, 1000000 };

	for (auto n : s)
	{
		std::vector<unsigned int> v;

		// generating random collection contents
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
			v.push_back(generator());

		Benchmark<std::chrono::nanoseconds> b;
		//bubbleSort(v.begin(), v.end());
		//insertionSort(v.begin(), v.end());
		//selectionSort(v.begin(), v.end());
		//mergeSort(v.begin(), v.end());
		//quickSort(v.begin(), v.end());
		std::sort(v.begin(), v.end());
		auto t = b.elapsed();

		std::cout << t << std::endl;
	}
}
