#include <cmath>
#include <iostream>
#include "Weather.h"
#include <vector>

#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

template<typename Comparable>
class HeapSort {

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

    // Helper function for heapSort
    inline int leftChild(int i) {
        return 2 * i + 1;
    }

    // Helper function for heapSort
    // i is the index of the value being percolated down
    // n is the number of items in the heap
    void percolateDown(std::vector <Comparable> &items, int i, int n, int child, Comparable tmp) {
        //int child;
        //Comparable tmp;

        for (tmp = items[i]; leftChild(i) < n; i = child) {
            // 1 read for items
            // 1 write for tmp
            child = leftChild(i);
            // choose the child with the larger value
            if (child != n - 1 && items[child] < items[child + 1]) {
                // 2 reads for items
                calcReadsAndWrites(2, 0);
                ++child;
            }
            // if the parent is less than the child, swap them
            if (tmp < items[child]) {
                // 1 read for tmp
                // 1 read for items
                items[i] = items[child];
                // 1 write for items
                // 1 read for items
                calcReadsAndWrites(3,1);
            } else {
                // parent is >= both children. nothing more to do.
                break;
            }
            calcReadsAndWrites(1,1);
        }
        items[i] = tmp;
        calcReadsAndWrites(1,1);
        // 1 write for items
        // 1 read for tmp
    }

    std::vector <Comparable> heapSort(std::vector <Comparable> items) {
        int i, j, child;
        Comparable temp, tmp;
        // build the heap (with max value at root)
        for (i = items.size() / 2 - 1; i >= 0; --i) {
            percolateDown(items, i, items.size(), child, tmp);

        }
        //printVec(items);
        // keep deleting the max
        for (j = items.size() - 1; j > 0; --j) {
            // 1 read for items
            // swap the maximum out
            temp = items[0];
            // 1 write for temp
            // 1 read for items
            items[0] = items[j];
            // 1 write for items
            // 1 read for items
            items[j] = temp;
            // 1 write for items
            // 1 read for items
            calcReadsAndWrites(4, 3);

            // make it into a heap again
            percolateDown(items, 0, j, child, tmp);

            //printVec(items);
        }
        return items;
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

#endif //SORTING_HEAPSORT_H
