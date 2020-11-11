#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "TwoSort.h"
#include "Weather.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <cmath>
#include <iostream>
#include <vector>

#ifndef SORTING_SORTINGALGORITHMS_H
#define SORTING_SORTINGALGORITHMS_H

/**
    Overloaded Operators
*/

bool operator > (const MarsWeather &a, const MarsWeather &b) {

    return a.getSol() > a.getSol();
}

bool operator < (const MarsWeather &a, const MarsWeather &b) {

    return b.getSol() < a.getSol();
}

bool operator <= (const MarsWeather &a, const MarsWeather &b) {

    return b.getSol() < a.getSol();
}

bool operator >= (const MarsWeather &a, const MarsWeather &b) {

    return b.getSol() < a.getSol();
}

bool operator == (const MarsWeather &a, const MarsWeather &b) {

    return b.getSol() == a.getSol();

}

class SortingAlgorithms {

public:

    void bubbleSort() {
        // Create vector object
        std::vector<MarsWeather> weather;
        std::vector<MarsWeather> weather_one_hundred;
        std::vector<MarsWeather> weather_two_hundred;
        std::vector<MarsWeather> weather_three_hundred;
        std::vector<MarsWeather> weather_four_hundred;
        std::vector<MarsWeather> weather_five_hundred;
        std::vector<MarsWeather> weather_six_hundred;
        std::vector<MarsWeather> weather_seven_hundred;
        std::vector<MarsWeather> weather_eight_hundred;
        std::vector<MarsWeather> weather_nine_hundred;
        std::vector<MarsWeather> weather_one_thousand;

        // Populate vector with content from file
        getWeather("mars-weather.csv", weather);
        unsigned random_num = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(weather.begin(), weather.end(), std::default_random_engine(random_num));

        BubbleSort<MarsWeather> bs_one_hundred;
        BubbleSort<MarsWeather> bs_two_hundred;
        BubbleSort<MarsWeather> bs_three_hundred;
        BubbleSort<MarsWeather> bs_four_hundred;
        BubbleSort<MarsWeather> bs_five_hundred;
        BubbleSort<MarsWeather> bs_six_hundred;
        BubbleSort<MarsWeather> bs_seven_hundred;
        BubbleSort<MarsWeather> bs_eight_hundred;
        BubbleSort<MarsWeather> bs_nine_hundred;
        BubbleSort<MarsWeather> bs_one_thousand;

        for (int i = 0; i < 101; ++i) {
            weather_one_hundred.push_back(weather[i]);
        }

        bs_one_hundred.bubbleSort(weather_one_hundred);

        for (int i = 0; i < 201; ++i) {
            weather_two_hundred.push_back(weather[i]);
        }

        bs_two_hundred.bubbleSort(weather_two_hundred);

        for (int i = 0; i < 301; ++i) {
            weather_three_hundred.push_back(weather[i]);
        }

        bs_three_hundred.bubbleSort(weather_three_hundred);

        for (int i = 0; i < 401; ++i) {
            weather_four_hundred.push_back(weather[i]);
        }

        bs_four_hundred.bubbleSort(weather_four_hundred);

        for (int i = 0; i < 501; ++i) {
            weather_five_hundred.push_back(weather[i]);
        }

        bs_five_hundred.bubbleSort(weather_five_hundred);

        for (int i = 0; i < 601; ++i) {
            weather_six_hundred.push_back(weather[i]);
        }

        bs_six_hundred.bubbleSort(weather_six_hundred);

        for (int i = 0; i < 701; ++i) {
            weather_seven_hundred.push_back(weather[i]);
        }

        bs_seven_hundred.bubbleSort(weather_seven_hundred);

        for (int i = 0; i < 801; ++i) {
            weather_eight_hundred.push_back(weather[i]);
        }

        bs_eight_hundred.bubbleSort(weather_eight_hundred);

        for (int i = 0; i < 901; ++i) {
            weather_nine_hundred.push_back(weather[i]);
        }

        bs_nine_hundred.bubbleSort(weather_nine_hundred);

        for (int i = 0; i < 1001; ++i) {
            weather_one_thousand.push_back(weather[i]);
        }

        bs_one_thousand.bubbleSort(weather_one_thousand);

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../bubble_sort.csv");
        if (file_sequence) {

            file_sequence << bs_one_hundred.getReads() << ", " << bs_one_hundred.getWrites() << std::endl;
            file_sequence << bs_two_hundred.getReads() <<  ", " << bs_two_hundred.getWrites() << std::endl;
            file_sequence << bs_three_hundred.getReads() << ", " << bs_three_hundred.getWrites() << std::endl;
            file_sequence << bs_four_hundred.getReads() << ", " << bs_four_hundred.getWrites() << std::endl;
            file_sequence << bs_five_hundred.getReads() << ", " << bs_five_hundred.getWrites() << std::endl;
            file_sequence << bs_six_hundred.getReads() << ", " << bs_six_hundred.getWrites() << std::endl;
            file_sequence << bs_seven_hundred.getReads() << ", " << bs_seven_hundred.getWrites() << std::endl;
            file_sequence << bs_eight_hundred.getReads() << ", " << bs_eight_hundred.getWrites() << std::endl;
            file_sequence << bs_nine_hundred.getReads() << ", " << bs_nine_hundred.getWrites() << std::endl;
            file_sequence << bs_one_thousand.getReads() << ", " << bs_one_thousand.getWrites() << std::endl;

        }
        file_sequence.close();

    }

    void heapSort() {
        // Create vector object
        std::vector<MarsWeather> weather;
        std::vector<MarsWeather> weather_one_hundred;
        std::vector<MarsWeather> weather_two_hundred;
        std::vector<MarsWeather> weather_three_hundred;
        std::vector<MarsWeather> weather_four_hundred;
        std::vector<MarsWeather> weather_five_hundred;
        std::vector<MarsWeather> weather_six_hundred;
        std::vector<MarsWeather> weather_seven_hundred;
        std::vector<MarsWeather> weather_eight_hundred;
        std::vector<MarsWeather> weather_nine_hundred;
        std::vector<MarsWeather> weather_one_thousand;

        // Populate vector with content from file
        getWeather("mars-weather.csv", weather);
        unsigned random_num = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(weather.begin(), weather.end(), std::default_random_engine(random_num));

        HeapSort<MarsWeather> hs_one_hundred;
        HeapSort<MarsWeather> hs_two_hundred;
        HeapSort<MarsWeather> hs_three_hundred;
        HeapSort<MarsWeather> hs_four_hundred;
        HeapSort<MarsWeather> hs_five_hundred;
        HeapSort<MarsWeather> hs_six_hundred;
        HeapSort<MarsWeather> hs_seven_hundred;
        HeapSort<MarsWeather> hs_eight_hundred;
        HeapSort<MarsWeather> hs_nine_hundred;
        HeapSort<MarsWeather> hs_one_thousand;

        for (int i = 0; i < 101; ++i) {
            weather_one_hundred.push_back(weather[i]);
        }

        hs_one_hundred.heapSort(weather_one_hundred);

        for (int i = 0; i < 201; ++i) {
            weather_two_hundred.push_back(weather[i]);
        }

        hs_two_hundred.heapSort(weather_two_hundred);

        for (int i = 0; i < 301; ++i) {
            weather_three_hundred.push_back(weather[i]);
        }

        hs_three_hundred.heapSort(weather_three_hundred);

        for (int i = 0; i < 401; ++i) {
            weather_four_hundred.push_back(weather[i]);
        }

        hs_four_hundred.heapSort(weather_four_hundred);

        for (int i = 0; i < 501; ++i) {
            weather_five_hundred.push_back(weather[i]);
        }

        hs_five_hundred.heapSort(weather_five_hundred);

        for (int i = 0; i < 601; ++i) {
            weather_six_hundred.push_back(weather[i]);
        }

        hs_six_hundred.heapSort(weather_six_hundred);

        for (int i = 0; i < 701; ++i) {
            weather_seven_hundred.push_back(weather[i]);
        }

        hs_seven_hundred.heapSort(weather_seven_hundred);

        for (int i = 0; i < 801; ++i) {
            weather_eight_hundred.push_back(weather[i]);
        }

        hs_eight_hundred.heapSort(weather_eight_hundred);

        for (int i = 0; i < 901; ++i) {
            weather_nine_hundred.push_back(weather[i]);
        }

        hs_nine_hundred.heapSort(weather_nine_hundred);

        for (int i = 0; i < 1001; ++i) {
            weather_one_thousand.push_back(weather[i]);
        }

        hs_one_thousand.heapSort(weather_one_thousand);

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../heap_sort.csv");
        if (file_sequence) {

            file_sequence << hs_one_hundred.getReads() << ", " << hs_one_hundred.getWrites() << std::endl;
            file_sequence << hs_two_hundred.getReads() << ", " << hs_two_hundred.getWrites() << std::endl;
            file_sequence << hs_three_hundred.getReads() << ", " << hs_three_hundred.getWrites() << std::endl;
            file_sequence << hs_four_hundred.getReads() << ", " << hs_four_hundred.getWrites() << std::endl;
            file_sequence << hs_five_hundred.getReads() << ", " << hs_five_hundred.getWrites() << std::endl;
            file_sequence << hs_six_hundred.getReads() << ", " << hs_six_hundred.getWrites() << std::endl;
            file_sequence << hs_seven_hundred.getReads() << ", " << hs_seven_hundred.getWrites() << std::endl;
            file_sequence << hs_eight_hundred.getReads() << ", " << hs_eight_hundred.getWrites() << std::endl;
            file_sequence << hs_nine_hundred.getReads() << ", " << hs_nine_hundred.getWrites() << std::endl;
            file_sequence << hs_one_thousand.getReads() << ", " << hs_one_thousand.getWrites() << std::endl;

        }
        file_sequence.close();

    }

    void selectionSort() {
        // Create vector object
        std::vector<MarsWeather> weather;
        std::vector<MarsWeather> weather_one_hundred;
        std::vector<MarsWeather> weather_two_hundred;
        std::vector<MarsWeather> weather_three_hundred;
        std::vector<MarsWeather> weather_four_hundred;
        std::vector<MarsWeather> weather_five_hundred;
        std::vector<MarsWeather> weather_six_hundred;
        std::vector<MarsWeather> weather_seven_hundred;
        std::vector<MarsWeather> weather_eight_hundred;
        std::vector<MarsWeather> weather_nine_hundred;
        std::vector<MarsWeather> weather_one_thousand;

        // Populate vector with content from file
        getWeather("mars-weather.csv", weather);
        unsigned random_num = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(weather.begin(), weather.end(), std::default_random_engine(random_num));

        SelectionSort<MarsWeather> ss_one_hundred;
        SelectionSort<MarsWeather> ss_two_hundred;
        SelectionSort<MarsWeather> ss_three_hundred;
        SelectionSort<MarsWeather> ss_four_hundred;
        SelectionSort<MarsWeather> ss_five_hundred;
        SelectionSort<MarsWeather> ss_six_hundred;
        SelectionSort<MarsWeather> ss_seven_hundred;
        SelectionSort<MarsWeather> ss_eight_hundred;
        SelectionSort<MarsWeather> ss_nine_hundred;
        SelectionSort<MarsWeather> ss_one_thousand;

        for (int i = 0; i < 101; ++i) {
            weather_one_hundred.push_back(weather[i]);
        }

        ss_one_hundred.selectionSort(weather_one_hundred);

        for (int i = 0; i < 201; ++i) {
            weather_two_hundred.push_back(weather[i]);
        }

        ss_two_hundred.selectionSort(weather_two_hundred);

        for (int i = 0; i < 301; ++i) {
            weather_three_hundred.push_back(weather[i]);
        }

        ss_three_hundred.selectionSort(weather_three_hundred);

        for (int i = 0; i < 401; ++i) {
            weather_four_hundred.push_back(weather[i]);
        }

        ss_four_hundred.selectionSort(weather_four_hundred);

        for (int i = 0; i < 501; ++i) {
            weather_five_hundred.push_back(weather[i]);
        }

        ss_five_hundred.selectionSort(weather_five_hundred);

        for (int i = 0; i < 601; ++i) {
            weather_six_hundred.push_back(weather[i]);
        }

        ss_six_hundred.selectionSort(weather_six_hundred);

        for (int i = 0; i < 701; ++i) {
            weather_seven_hundred.push_back(weather[i]);
        }

        ss_seven_hundred.selectionSort(weather_seven_hundred);

        for (int i = 0; i < 801; ++i) {
            weather_eight_hundred.push_back(weather[i]);
        }

        ss_eight_hundred.selectionSort(weather_eight_hundred);

        for (int i = 0; i < 901; ++i) {
            weather_nine_hundred.push_back(weather[i]);
        }

        ss_nine_hundred.selectionSort(weather_nine_hundred);

        for (int i = 0; i < 1001; ++i) {
            weather_one_thousand.push_back(weather[i]);
        }

        ss_one_thousand.selectionSort(weather_one_thousand);

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../selection_sort.csv");
        if (file_sequence) {

            file_sequence << ss_one_hundred.getReads() << ", " << ss_one_hundred.getWrites() << std::endl;
            file_sequence << ss_two_hundred.getReads() <<  ", " << ss_two_hundred.getWrites() << std::endl;
            file_sequence << ss_three_hundred.getReads() << ", " << ss_three_hundred.getWrites() << std::endl;
            file_sequence << ss_four_hundred.getReads() << ", " << ss_four_hundred.getWrites() << std::endl;
            file_sequence << ss_five_hundred.getReads() << ", " << ss_five_hundred.getWrites() << std::endl;
            file_sequence << ss_six_hundred.getReads() << ", " << ss_six_hundred.getWrites() << std::endl;
            file_sequence << ss_seven_hundred.getReads() << ", " << ss_seven_hundred.getWrites() << std::endl;
            file_sequence << ss_eight_hundred.getReads() << ", " << ss_eight_hundred.getWrites() << std::endl;
            file_sequence << ss_nine_hundred.getReads() << ", " << ss_nine_hundred.getWrites() << std::endl;
            file_sequence << ss_one_thousand.getReads() << ", " << ss_one_thousand.getWrites() << std::endl;

        }
        file_sequence.close();

    }

    void mergeSort() {
        // Create vector object
        std::vector<MarsWeather> weather;
        std::vector<MarsWeather> weather_one_hundred;
        std::vector<MarsWeather> weather_two_hundred;
        std::vector<MarsWeather> weather_three_hundred;
        std::vector<MarsWeather> weather_four_hundred;
        std::vector<MarsWeather> weather_five_hundred;
        std::vector<MarsWeather> weather_six_hundred;
        std::vector<MarsWeather> weather_seven_hundred;
        std::vector<MarsWeather> weather_eight_hundred;
        std::vector<MarsWeather> weather_nine_hundred;
        std::vector<MarsWeather> weather_one_thousand;

        // Populate vector with content from file
        getWeather("mars-weather.csv", weather);
        unsigned random_num = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(weather.begin(), weather.end(), std::default_random_engine(random_num));

        MergeSort<MarsWeather> ss_one_hundred;
        MergeSort<MarsWeather> ss_two_hundred;
        MergeSort<MarsWeather> ss_three_hundred;
        MergeSort<MarsWeather> ss_four_hundred;
        MergeSort<MarsWeather> ss_five_hundred;
        MergeSort<MarsWeather> ss_six_hundred;
        MergeSort<MarsWeather> ss_seven_hundred;
        MergeSort<MarsWeather> ss_eight_hundred;
        MergeSort<MarsWeather> ss_nine_hundred;
        MergeSort<MarsWeather> ss_one_thousand;

        for (int i = 0; i < 101; ++i) {
            weather_one_hundred.push_back(weather[i]);
        }

        ss_one_hundred.mergeSort(weather_one_hundred);

        for (int i = 0; i < 201; ++i) {
            weather_two_hundred.push_back(weather[i]);
        }

        ss_two_hundred.selectionSort(weather_two_hundred);

        for (int i = 0; i < 301; ++i) {
            weather_three_hundred.push_back(weather[i]);
        }

        ss_three_hundred.selectionSort(weather_three_hundred);

        for (int i = 0; i < 401; ++i) {
            weather_four_hundred.push_back(weather[i]);
        }

        ss_four_hundred.selectionSort(weather_four_hundred);

        for (int i = 0; i < 501; ++i) {
            weather_five_hundred.push_back(weather[i]);
        }

        ss_five_hundred.selectionSort(weather_five_hundred);

        for (int i = 0; i < 601; ++i) {
            weather_six_hundred.push_back(weather[i]);
        }

        ss_six_hundred.selectionSort(weather_six_hundred);

        for (int i = 0; i < 701; ++i) {
            weather_seven_hundred.push_back(weather[i]);
        }

        ss_seven_hundred.selectionSort(weather_seven_hundred);

        for (int i = 0; i < 801; ++i) {
            weather_eight_hundred.push_back(weather[i]);
        }

        ss_eight_hundred.selectionSort(weather_eight_hundred);

        for (int i = 0; i < 901; ++i) {
            weather_nine_hundred.push_back(weather[i]);
        }

        ss_nine_hundred.selectionSort(weather_nine_hundred);

        for (int i = 0; i < 1001; ++i) {
            weather_one_thousand.push_back(weather[i]);
        }

        ss_one_thousand.selectionSort(weather_one_thousand);

        // Write to file
        std::ofstream file_sequence;
        file_sequence.open("../selection_sort.csv");
        if (file_sequence) {

            file_sequence << ss_one_hundred.getReads() << ", " << ss_one_hundred.getWrites() << std::endl;
            file_sequence << ss_two_hundred.getReads() <<  ", " << ss_two_hundred.getWrites() << std::endl;
            file_sequence << ss_three_hundred.getReads() << ", " << ss_three_hundred.getWrites() << std::endl;
            file_sequence << ss_four_hundred.getReads() << ", " << ss_four_hundred.getWrites() << std::endl;
            file_sequence << ss_five_hundred.getReads() << ", " << ss_five_hundred.getWrites() << std::endl;
            file_sequence << ss_six_hundred.getReads() << ", " << ss_six_hundred.getWrites() << std::endl;
            file_sequence << ss_seven_hundred.getReads() << ", " << ss_seven_hundred.getWrites() << std::endl;
            file_sequence << ss_eight_hundred.getReads() << ", " << ss_eight_hundred.getWrites() << std::endl;
            file_sequence << ss_nine_hundred.getReads() << ", " << ss_nine_hundred.getWrites() << std::endl;
            file_sequence << ss_one_thousand.getReads() << ", " << ss_one_thousand.getWrites() << std::endl;

        }
        file_sequence.close();

    }

};

#endif //SORTING_SORTINGALGORITHMS_H
