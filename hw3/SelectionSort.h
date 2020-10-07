#ifndef SELECTION_H
#define SELECTION_H
using namespace std;

//Templated Class Forward Declaration
template <class T>
class SelectionSort;

//Templated Class Declaration
template <class T>
class SelectionSort
{

    public:
        SelectionSort(const int maxSize);
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
        int findIndexOfLargest(const int maxIndex);
};
#include "SelectionSort.cpp"
#endif 