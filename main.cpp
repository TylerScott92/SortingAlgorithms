#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "SortingAlgorithms.h"
#include "TwoSort.h"
#include "Weather.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    SortingAlgorithms sorting_algorithms;
    sorting_algorithms.heapSort();
    sorting_algorithms.bubbleSort();
    sorting_algorithms.selectionSort();
    sorting_algorithms.mergeSort();
    sorting_algorithms.twoSort();
    return 0;
}



