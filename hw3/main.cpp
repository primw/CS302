// Prim Wandeevong // CS 302 - Homework 3: main.cpp // 3-3-20 //
#include <iostream>
#include <chrono>
#include <cstring>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "main.h"
using namespace std;
using namespace std::chrono;


int main()
{
    int s_data[1000], m_data[10000], l_data[100000];
    int s_best[1000], m_best[10000], l_best[100000];

    //Read Input Data - Worst Case
    readSmallFile(s_data);
    readMediumFile(m_data);
    readLargeFile(l_data);

    //Read Input Data - Best Case
    readSmallBest(s_best);
    readMediumBest(m_best);
    readLargeBest(l_best);

    //Test Sorting Algorithms - Worst Case
    cout << "WORST CASE - NOT SORTED" << endl;
    selectionSortSmall(s_data, 0);
    cout << "-----------------------------------" << endl << endl;
    selectionSortMedium(m_data, 0);
    cout << "-----------------------------------" << endl << endl;
    selectionSortLarge(l_data, 0);
    cout << "-----------------------------------" << endl << endl;
    insertionSortSmall(s_data, 0);
    cout << "-----------------------------------" << endl << endl;
    insertionSortMedium(m_data, 0);
    cout << "-----------------------------------" << endl << endl;
    insertionSortLarge(l_data, 0);
    cout << "-----------------------------------" << endl << endl;
    mergeSortSmall(s_data, 0);
    cout << "-----------------------------------" << endl << endl;
    mergeSortMedium(m_data, 0);
    cout << "-----------------------------------" << endl << endl;
    mergeSortLarge(l_data, 0);
    
    //Test Sorting Algorithms - Best Case
    cout << "BEST CASE - ALREADY SORTED" << endl;
    selectionSortSmall(s_best , 1);
    cout << "-----------------------------------" << endl << endl;
    selectionSortMedium(m_best, 1);
    cout << "-----------------------------------" << endl << endl;
    selectionSortLarge(l_best, 1);
    cout << "-----------------------------------" << endl << endl;
    insertionSortSmall(s_best, 1);
    cout << "-----------------------------------" << endl << endl;
    insertionSortMedium(m_best, 1);
    cout << "-----------------------------------" << endl << endl;
    insertionSortLarge(l_best, 1);
    cout << "-----------------------------------" << endl << endl;
    mergeSortSmall(s_best, 1);
    cout << "-----------------------------------" << endl << endl;
    mergeSortMedium(m_best, 1);
    cout << "-----------------------------------" << endl << endl;
    mergeSortLarge(l_best, 1);

}
    