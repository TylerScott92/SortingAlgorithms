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

    void quickSortUnstableRec(std::vector<Comparable> &vec, int startIndex, int endIndex) {
        if (endIndex <= startIndex) {
            // There is only one element left. Nothing to do.
            return;
        }
        Comparable partition = vec[startIndex];
        Comparable temp;
        int i;
        int largerElementIndex = startIndex + 1;
        for (i = startIndex; i <= endIndex; ++i) {
            if (vec[i] < partition) {
                // 1 read for vec
                // 1 read for partition

                // Swap the element with the one at largerElementIndex to keep smaller elements grouped
                temp = vec[i];
                // 1 write for temp
                // 1 read for vec

                vec[i] = vec[largerElementIndex];
                // 1 write vec
                // 1 read for vec

                vec[largerElementIndex] = temp;
                // 1 write for vec
                // 1 read for temp

                // Update largerElementIndex
                ++largerElementIndex;
                calcReadsAndWrites(5,3);
            }

        }
        vec[startIndex] = vec[largerElementIndex - 1];
        vec[largerElementIndex - 1] = partition;
        // 2 writes for vec
        // 1 read for vec
        // 1 read for partition
        calcReadsAndWrites(2,2);

        //printVec(vec);

        // Recursive call for less-than-partition side
        quickSortUnstableRec(vec, startIndex, largerElementIndex - 2);
        // Recursive call for greater-than-or-equal-to-partition side
        quickSortUnstableRec(vec, largerElementIndex, endIndex);
    }

    void quickSortUnstable(std::vector<Comparable> vec) {
        quickSortUnstableRec(vec, 0, vec.size() - 1);
    }

    void quickSortStableRec(std::vector<MarsWeather> &vec) {
        // Recursive base case
        if (vec.size() < 2) {
            // There is nothing to sort
            return;
        }
        // Choose a partition element
        Comparable partition = vec[0];
        std::vector<MarsWeather> smaller, equal, larger;
        // Loop through vec and populate smaller, equal, larger
        int i;
        for (i = 0; i < vec.size(); ++i) {
            if (vec[i] < partition) {
                smaller.push_back(vec[i]);
            } else if (vec[i] > partition) {
                larger.push_back(vec[i]);
            } else {
                equal.push_back(vec[i]);
            }
        }
        // Recursive calls
        quickSortStableRec(smaller);
        quickSortStableRec(larger);
        // Copy everything back into vec
        for (i = 0; i < smaller.size(); ++i) {
            vec[i] = smaller[i];
        }
        for (; i < smaller.size() + equal.size(); ++i) {
            vec[i] = equal[i - smaller.size()];
        }
        for (; i < vec.size(); ++i) {
            vec[i] = larger[i - smaller.size() - equal.size()];
        }
        printVec(vec);
    }

    void quickSortStable(std::vector<MarsWeather> vec) {
        quickSortStableRec(vec);
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
