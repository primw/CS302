// Prim Wandeevong // CS 302 - Homework 3: Insertion.h // 3-3-20 //
#ifndef INSERTION_H
#define INSERTION_H

//Templated Class Forward Declaration
template <class T>
class InsertionSort;


//Templated Class Declaration
template <class T>
class InsertionSort
{
    public:
        InsertionSort(const int maxSize);
        void sort();
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

#include "InsertionSort.cpp"
#endif