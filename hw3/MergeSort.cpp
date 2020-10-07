 // Prim Wandeevong // CS 302 - Homework3: MergeSort.cpp // 3-4-20 //
#include <iostream>
#include <fstream>
#include "MergeSort.h"
using namespace std;

//Parameterized Constructor
template <class T>
MergeSort<T>::MergeSort(const int maxSize) : m_size(0), m_maxSize(maxSize), m_comparisons(0), m_swaps(0)
{
    m_arr = new T[maxSize];
}

//Copy Method
template <class T>
void MergeSort<T>::copy(T array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_arr[i] = array[i];
        m_size++;
    }
}


//Merge Method
template <class T>
void MergeSort<T>::merge(int first, int mid, int last)
{
    T tempArray[m_maxSize];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        m_comparisons++;
        if(m_arr[first1] <= m_arr[first2])
        {
            tempArray[index] = m_arr[first1];
            first1++;
            m_swaps++;
        }
        else
        {
            tempArray[index] = m_arr[first2];
            first2++;
            m_swaps++;
        }
        index++;
    }

    while (first1 <= last1)
    {
        tempArray[index] = m_arr[first1];
        first1++;
        index++;
    }

    while (first2 <= last2)
    {
        tempArray[index] = m_arr[first2];
        first2++;
        index++;
    }

    for (index = first; index <= last; index++)
    {
        m_arr[index] = tempArray[index];
    }

}

//Sort Method
template <class T>
void MergeSort<T>::sort(int first, int last)
{
    if (first < last)
    {
        int mid = first + (last-first)/2;
        sort(first, mid);
        sort(mid + 1, last);
        merge(first, mid, last);
    }
}

//Print to File Method
template <class T>
void MergeSort<T>::printToFile(string filename) const
{
    ofstream output;
    output.open(filename);
    for (int i = 0; i < m_maxSize; i++)
    {
        output << m_arr[i] << " ";
    }
    output.close();
}
//Get Swap Method
template <class T>
long int MergeSort<T>::getSwaps()
{
    return m_swaps;
}

//Get Comparison Method
template <class T>
unsigned long int MergeSort<T>:: getComparisons()
{
    return m_comparisons;
}
