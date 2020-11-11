#include <cmath>
#include <iostream>
#include "Weather.h"
#include <vector>

#ifndef SORTING_MERGESORT_H
#define SORTING_MERGESORT_H

template<typename Comparable>

class MergeSort {

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

    void mergeSortRec(std::vector<Comparable> &vec, int startIndex, int endIndex, std::vector<Comparable> &temp) {

        // Recursive base case
        if (startIndex == endIndex) {
            // We are down to one element. Nothing to split or sort.
            return;
        }

        // Recursive calls
        int centerIndex = (startIndex + endIndex) / 2;
        // Recursive call for the left half
        mergeSortRec(vec, startIndex, centerIndex, temp);
        // 1 read for vec
        // 1 read temp
        // Recursive call for the right half
        mergeSortRec(vec, centerIndex + 1, endIndex, temp);
        // 1 read for vec
        // 1 read for temp
        calcReadsAndWrites(2,2);

        // Merge
        //vector<Comparable> temp;
        int leftIndex = startIndex;
        int rightIndex = centerIndex + 1;
        int tempIndex = 0;
        while (leftIndex <= centerIndex && rightIndex <= endIndex) {
            if (vec[leftIndex] <= vec[rightIndex]) {
                // 2 reads for vec
                // Take the element from the left half
                temp[tempIndex] = vec[leftIndex];
                // 1 write for temp
                // 1 read for vec
                calcReadsAndWrites(3,1);

                ++tempIndex;
                ++leftIndex;
            } else {
                // Take the element from the right half
                temp[tempIndex] = vec[rightIndex];
                // 1 write for temp
                // 1 read for vec
                calcReadsAndWrites(1,1);
                ++tempIndex;
                ++rightIndex;
            }
        }
        // At this point, one of the halves has been copied into temp
        // and there is at least one element left in the other half
        while (leftIndex <= centerIndex) {
            // This is the case when there are still elements in the left half
            // Copy them over
            temp[tempIndex] = vec[leftIndex];

            // 1 write for temp
            // 1 read for vec
            calcReadsAndWrites(1, 1);

            ++tempIndex;
            ++leftIndex;
        }
        while (rightIndex <= endIndex) {
            // This is the case when there are still elements in the right half
            // Copy them over
            temp[tempIndex] = vec[rightIndex];
            // 1 write for temp
            // 1 read for vec
            calcReadsAndWrites(1, 1);

            ++tempIndex;
            ++rightIndex;
        }

        // Now all of the elements are sorted in temp
        // Copy them all back to vec
        for (int i = 0; i <= (endIndex - startIndex); ++i) {
            vec[startIndex + i] = temp[i];
            // 1 write for vec
            // 1 read for temp
            calcReadsAndWrites(1, 1);
        }

        //printVec(vec);
    }

    void mergeSort(std::vector<Comparable> vec) {
        // Create a temporary vector that is the same size as vec
        std::vector<Comparable> temp(vec.size());
        mergeSortRec(vec, 0, vec.size() - 1, temp);
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


#endif //SORTING_MERGESORT_H
