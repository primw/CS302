// Prim Wandeevong // CS 302 - Homework 3: MergeSort.h // 3-4-20 //
#ifndef MERGE_H
#define MERGE_H

//Templated Class Forward Declaration
template <class T>
class MergeSort;

//Templated Class Declaration
template <class T>
class MergeSort
{
    public:
        MergeSort(const int maxSize);
        void merge(int first, int mid, int last);
        void sort(int first, int last);
        void copy(T array[], int size);
        void printToFile(string filename) const;
        long int getSwaps();
        unsigned long int getComparisons();
    private:
        T *m_arr;
        int m_size;
        int m_maxSize;
        unsigned long int m_comparisons;
        long int m_swaps;
};

#include "MergeSort.cpp"
#endif