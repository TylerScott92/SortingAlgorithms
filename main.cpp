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

template<typename Comparable>
void printVec(const vector<Comparable> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

// Note: Not a template function
void radixSort(vector<int> vec, int numDigits) {
    int iteration, i, digit, bucket, item;
    vector<vector<int>> buckets(10);
    for (iteration = 0; iteration < numDigits; ++iteration) {
        // Copy everything from vec into buckets
        for (i = 0; i < vec.size(); ++i) {
            digit = (vec[i] / int(pow(10, iteration)) % 10);
            buckets[digit].push_back(vec[i]);
        }
        // Copy everything from buckets back into vec
        i = 0;
        for (bucket = 0; bucket < buckets.size(); ++bucket) {
            for (item = 0; item < buckets[bucket].size(); ++item) {
                vec[i] = buckets[bucket][item];
                ++i;
            }
            buckets[bucket].clear();
        }
        printVec(vec);
    }
}

//void mergeSort();
void selectionSort();
void twoSort();

int main() {

    SortingAlgorithms sorting_algorithms;
    sorting_algorithms.heapSort();
    sorting_algorithms.bubbleSort();
    sorting_algorithms.selectionSort();
    sorting_algorithms.mergeSort();
    //twoSort();
    //radixSort(numbers, 2);
    return 0;
}

void bubbleSort() {

    // Create vector object
    vector<MarsWeather> weather;
    vector<MarsWeather> weather_one_hundred;
    vector<MarsWeather> weather_two_hundred;
    //vector<MarsWeather> weather_three_hundred;
    //vector<MarsWeather> weather_four_hundred;
    //vector<MarsWeather> weather_five_hundred;
    //vector<MarsWeather> weather_six_hundred;
    //vector<MarsWeather> weather_seven_hundred;
    //vector<MarsWeather> weather_eight_hundred;
    //vector<MarsWeather> weather_nine_hundred;
    //vector<MarsWeather> weather_one_thousand;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);

    BubbleSort<MarsWeather> bs_one_hundred;
    BubbleSort<MarsWeather> bs_two_hundred;
    BubbleSort<MarsWeather> bs_three_hundred;
    BubbleSort<MarsWeather> bs_four_hundred;

    for (int i = 0; i < 101; ++i) {
        weather_one_hundred.push_back(weather[i]);
    }

    bs_one_hundred.bubbleSort(weather_one_hundred);
    cout << bs_one_hundred.getReads() << "\n" << endl;
    cout << bs_one_hundred.getWrites() << "\n" << endl;

    for (int i = 0; i < 201; ++i) {
        weather_two_hundred.push_back(weather[i]);
    }

    bs_two_hundred.bubbleSort(weather_two_hundred);
    cout << bs_two_hundred.getReads() << "\n" << endl;
    cout << bs_two_hundred.getWrites() << "\n" << endl;

    //for (int i = 0; i < 300; ++i) {
    //    weather_three_hundred.push_back(weather[i]);
    //}

    //bs_three_hundred.bubbleSort(weather_three_hundred, read_number);
    //cout << bs_three_hundred.getReads() << endl;

    //for (int i = 0; i < 400; ++i) {
    //   weather_four_hundred.push_back(weather[i]);
    //}

    //bs_four_hundred.bubbleSort(weather_four_hundred, read_number);
    //cout << bs_four_hundred.getReads() << endl;

    //bs.bubbleSort(weather, read_number);
    //cout << bs.getReads() << endl;
}

void mergeSort() {

    // Create vector object
    vector<MarsWeather> weather;
    vector<MarsWeather> weather_one_hundred;
    vector<MarsWeather> weather_two_hundred;
    //vector<MarsWeather> weather_three_hundred;
    //vector<MarsWeather> weather_four_hundred;
    //vector<MarsWeather> weather_five_hundred;
    //vector<MarsWeather> weather_six_hundred;
    //vector<MarsWeather> weather_seven_hundred;
    //vector<MarsWeather> weather_eight_hundred;
    //vector<MarsWeather> weather_nine_hundred;
    //vector<MarsWeather> weather_one_thousand;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);

    MergeSort<MarsWeather> ms_one_hundred;
    MergeSort<MarsWeather> ms_two_hundred;
    MergeSort<MarsWeather> ms_three_hundred;
    MergeSort<MarsWeather> ms_four_hundred;

    for (int i = 0; i < 101; ++i) {
        weather_one_hundred.push_back(weather[i]);
    }

    ms_one_hundred.mergeSort(weather_one_hundred);
    cout << ms_one_hundred.getReads() << "\n" << endl;
    cout << ms_one_hundred.getWrites() << "\n" << endl;

    for (int i = 0; i < 201; ++i) {
        weather_two_hundred.push_back(weather[i]);
    }

    ms_two_hundred.mergeSort(weather_two_hundred);
    cout << ms_two_hundred.getReads() << "\n" << endl;
    cout << ms_two_hundred.getWrites() << "\n" << endl;

}

void selectionSort() {

    // Create vector object
    vector<MarsWeather> weather;
    vector<MarsWeather> weather_one_hundred;
    vector<MarsWeather> weather_two_hundred;
    //vector<MarsWeather> weather_three_hundred;
    //vector<MarsWeather> weather_four_hundred;
    //vector<MarsWeather> weather_five_hundred;
    //vector<MarsWeather> weather_six_hundred;
    //vector<MarsWeather> weather_seven_hundred;
    //vector<MarsWeather> weather_eight_hundred;
    //vector<MarsWeather> weather_nine_hundred;
    //vector<MarsWeather> weather_one_thousand;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);

    SelectionSort<MarsWeather> ss_one_hundred;
    SelectionSort<MarsWeather> ss_two_hundred;
    SelectionSort<MarsWeather> ss_three_hundred;
    SelectionSort<MarsWeather> ss_four_hundred;

    for (int i = 0; i < 101; ++i) {
        weather_one_hundred.push_back(weather[i]);
    }

    ss_one_hundred.selectionSort(weather_one_hundred);
    cout << ss_one_hundred.getReads() << "\n" << endl;
    cout << ss_one_hundred.getWrites() << "\n" << endl;

    for (int i = 0; i < 201; ++i) {
        weather_two_hundred.push_back(weather[i]);
    }

    ss_two_hundred.selectionSort(weather_two_hundred);
    cout << ss_two_hundred.getReads() << "\n" << endl;
    cout << ss_two_hundred.getWrites() << "\n" << endl;
}

void twoSort() {

    // Create vector object
    vector<MarsWeather> weather;
    vector<MarsWeather> weather_one_hundred;
    vector<MarsWeather> weather_two_hundred;
    //vector<MarsWeather> weather_three_hundred;
    //vector<MarsWeather> weather_four_hundred;
    //vector<MarsWeather> weather_five_hundred;
    //vector<MarsWeather> weather_six_hundred;
    //vector<MarsWeather> weather_seven_hundred;
    //vector<MarsWeather> weather_eight_hundred;
    //vector<MarsWeather> weather_nine_hundred;
    //vector<MarsWeather> weather_one_thousand;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);

    TwoSort<MarsWeather> ts_one_hundred;
    TwoSort<MarsWeather> ts_two_hundred;
    TwoSort<MarsWeather> ts_three_hundred;
    TwoSort<MarsWeather> ts_four_hundred;

    for (int i = 0; i < 101; ++i) {
        weather_one_hundred.push_back(weather[i]);
    }

    ts_one_hundred.quickSortUnstable(weather_one_hundred);
    cout << ts_one_hundred.getReads() << "\n" << endl;
    cout << ts_one_hundred.getWrites() << "\n" << endl;

    for (int i = 0; i < 201; ++i) {
        weather_two_hundred.push_back(weather[i]);
    }

    ts_two_hundred.quickSortUnstable(weather_two_hundred);
    cout << ts_two_hundred.getReads() << "\n" << endl;
    cout << ts_two_hundred.getWrites() << "\n" << endl;
}
