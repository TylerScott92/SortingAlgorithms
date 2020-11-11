#include <cmath>
#include <iostream>
#include "Weather.h"
#include <vector>

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

template<typename Comparable>

class TwoSort {

private:

    int read_number = 0;
    int write_number = 0;

    void printVec(const std::vector<Comparable> &v) {
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0) {
                std::cout << ", ";
            }
            std::cout << v[i];
        }
        std::cout << std::endl;
    }

public:

    // Bubble Sort
    void stableAlgorithm(std::vector <Comparable> vec) {
        bool haveSwapped = true;
        bool readIterator = true;
        int numPasses = 0, i;
        Comparable temp;
        while (haveSwapped) {

            haveSwapped = false;

            for (i = 0; i + 1 < vec.size() - numPasses; ++i) {

                if (vec[i] > vec[i + 1]) {

                    // The two elements are out of order. Swap them.
                    temp = vec[i];

                    vec[i] = vec[i + 1];

                    vec[i + 1] = temp;

                    // Update haveSwapped
                    haveSwapped = true;


                }

                calcReadsAndWrites(6,3);

            }
            ++numPasses;
            //printVec(vec);

        }
    }

    // Selection Sort
    void unstableAlgorithm(std::vector<Comparable> vec) {
        int swapIndex, i, minIndex;
        Comparable temp;
        for (swapIndex = 0; swapIndex < vec.size(); ++swapIndex) {
            // 1 read for vec
            minIndex = swapIndex;
            for (i = swapIndex + 1; i < vec.size(); ++i) {
                // 1 read for vec
                if (vec[i] < vec[minIndex]) {
                    // 2 reads for vec
                    calcReadsAndWrites(2,0);
                    // We have found a new minimum
                    minIndex = i;
                }
                calcReadsAndWrites(1, 0);
            }
            temp = vec[minIndex];
            // 1 write for temp
            // 1 read for vec
            vec[minIndex] = vec[swapIndex];
            // 1 write for vec
            // 1 read for vec
            vec[swapIndex] = temp;
            // 1 write for vec
            // 1 read for temp
            //printVec(vec);
            calcReadsAndWrites(4,3);
        }
    }

    void calcReadsAndWrites (int reads, int writes) {

        read_number += reads;
        write_number += writes;
    }

    int getReads () {

        return read_number;
    }

    int getWrites () {

        return write_number;
    }
};

#endif //SORTING_QUICKSORT_H
