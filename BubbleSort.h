#include <cmath>
#include <iostream>
#include "Weather.h"
#include <vector>

#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

template<typename Comparable>
class BubbleSort {

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

    void bubbleSort(std::vector <Comparable> vec) {
        bool haveSwapped = true;
        bool readIterator = true;
        int numPasses = 0, i;
        Comparable temp;
        while (haveSwapped) {

            haveSwapped = false;

            for (i = 0; i + 1 < vec.size() - numPasses; ++i) {
                // 1 read for vec

                if (vec[i] > vec[i + 1]) {
                    // 2 reads for vec

                    // The two elements are out of order. Swap them.
                    temp = vec[i];
                    // 1 write for temp
                    // 1 read for vec

                    vec[i] = vec[i + 1];
                    // 1 write for vec
                    // 1 read for vec

                    vec[i + 1] = temp;
                    // 1 write for vec
                    // 1 read for temp

                    // Update haveSwapped
                    haveSwapped = true;


                }

                calcReadsAndWrites(6,3);

            }
            ++numPasses;
            //printVec(vec);

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

#endif //SORTING_BUBBLESORT_H
