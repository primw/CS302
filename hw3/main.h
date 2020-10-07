#ifndef MAIN_H
#define MAIN_H
using namespace std;
using namespace std::chrono;


void printToTable(string filename, double time, int comparisons, int swaps)
{
    ofstream output;
    output.open(filename, ios_base::app);
    output << time << "," << comparisons << "," << swaps << endl;
}

//Read Small File Fuction
void readSmallFile(int data [])
{
    ifstream inputStream;
    inputStream.open("small.txt");

    int i = 0;
    while (inputStream && i < 1000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}

//Read Medium File Function
void readMediumFile(int data [])
{
    ifstream inputStream;
    inputStream.open("medium.txt");

    int i = 0;
    while (inputStream && i < 10000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}

//Read Large File
void readLargeFile(int data [])
{
    ifstream inputStream;
    inputStream.open("large.txt");

    int i = 0;
    while (inputStream && i < 100000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}


//Read Small Best File
void readSmallBest(int data[])
{
    ifstream inputStream;
    inputStream.open("smallBest.txt");

    int i = 0;
    while (inputStream && i < 1000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}

//Read Small Best File
void readMediumBest(int data[])
{
    ifstream inputStream;
    inputStream.open("mediumBest.txt");

    int i = 0;
    while (inputStream && i < 1000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}

//Read Large Best File
void readLargeBest(int data[])
{
    ifstream inputStream;
    inputStream.open("largeBest.txt");

    int i = 0;
    while (inputStream && i < 1000) 
    {
        inputStream >> data[i];
        i++;
    }
    inputStream.close();
}
//Selection Sort Small Sample Function
void selectionSortSmall(int s_data[], bool best)
{
    //Test Selection Sort 10x on the Small Sample
    for (int i = 0; i < 10; i++)
    {
        SelectionSort<int> small(1000);
        small.copy(s_data, 1000);

        auto start = high_resolution_clock::now();
        small.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Selection Sort]" << endl;
        cout << "SMALL SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "SMALL SAMPLE - COMPARISONS: " << small.getComparisons() << endl;
        cout << "SMALL SAMPLE - SWAPS: " << small.getSwaps() << endl << endl;

        small.printToFile("smallSelectionSort.txt");

        if (best)
        {
            printToTable("SelectionSort_ALL_BEST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
        else
        {
            printToTable("SelectionSort_ALL_WORST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
        
    }

}

//Selection Sort Medium Sample Function
void selectionSortMedium(int m_data[], bool best)
{
    //Test Selection Sort 10x on the Medium Sample
    for (int i = 0; i < 10; i++)
    {
        SelectionSort<int> medium(10000);
        medium.copy(m_data, 10000);

        auto start = high_resolution_clock::now();
        medium.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Selection Sort]" << endl;
        cout << "MEDIUM SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "MEDIUM SAMPLE - COMPARISONS: " << medium.getComparisons() << endl;
        cout << "MEDIUM SAMPLE - SWAPS: " << medium.getSwaps() << endl << endl;

        medium.printToFile("mediumSelectionSort.txt");
        if (best)
        {
            printToTable("SelectionSort_ALL_BEST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
        else
        {
            printToTable("SelectionSort_ALL_WORST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
    }
}

//Selection Sort Large Sample Function
void selectionSortLarge(int l_data[], bool best)
{
    //Test Selection Sort 10x on the Large Sample
    for (int i = 0; i < 10; i++)
    {
        SelectionSort<int> large(100000);
        large.copy(l_data, 100000);

        auto start = high_resolution_clock::now();
        large.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Selection Sort]" << endl;
        cout << "LARGE SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "LARGE SAMPLE - COMPARISONS: " << large.getComparisons() << endl;
        cout << "LARGE SAMPLE - SWAPS: " << large.getSwaps() << endl << endl;

        large.printToFile("largeSelectionSort.txt");

        if (best)
        {
            printToTable("SelectionSort_ALL_BEST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
        else
        {
            printToTable("SelectionSort_ALL_WORST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
    }
}

//Insertion Sort Small Sample Function
void insertionSortSmall(int s_data[], bool best)
{
    //Test Insertion Sort 10x on the Small Sample
    for (int i = 0; i < 10; i++)
    {
        InsertionSort<int> small(1000);
        small.copy(s_data, 1000);
        auto start = high_resolution_clock::now();
        small.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Insertion Sort]" << endl;
        cout << "SMALL SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "SMALL SAMPLE - COMPARISONS: " << small.getComparisons() << endl;
        cout << "SMALL SAMPLE - SWAPS: " << small.getSwaps() << endl << endl;

        small.printToFile("smallInsertionSort.txt");

        if (best)
        {
            printToTable("InsertionSort_ALL_BEST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
        else
        {
            printToTable("InsertionSort_ALL_WORST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
    }
}

//Insertion Sort Medium Sample Function
void insertionSortMedium(int m_data[], bool best)
{
    //Test Insertion Sort 10x on the Medium Sample
    for (int i = 0; i < 10; i++)
    {
        InsertionSort<int> medium(10000);
        medium.copy(m_data, 1000);
        auto start = high_resolution_clock::now();
        medium.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Insertion Sort]" << endl;
        cout << "MEDIUM SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "MEDIUM SAMPLE - COMPARISONS: " << medium.getComparisons() << endl;
        cout << "MEDIUM SAMPLE - SWAPS: " << medium.getSwaps() << endl << endl;

        medium.printToFile("mediumInsertionSort.txt");

        if (best)
        {
            printToTable("InsertionSort_ALL_BEST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
        else
        {
            printToTable("InsertionSort_ALL_WORST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
    }
}

//Insertion Sort Large Sample Function
void insertionSortLarge(int l_data[], bool best)
{
    //Test Selection Sort 10x on the Large Sample
    for (int i = 0; i < 10; i++)
    {
        InsertionSort<int> large(100000);
        large.copy(l_data, 100000);

        auto start = high_resolution_clock::now();
        large.sort();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Insertion Sort]" << endl;
        cout << "LARGE SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "LARGE SAMPLE - COMPARISONS: " << large.getComparisons() << endl;
        cout << "LARGE SAMPLE - SWAPS: " << large.getSwaps() << endl << endl;

        large.printToFile("largeInsertionSort.txt");

        if (best)
        {
            printToTable("InsertionSort_ALL_BEST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
        else
        {
            printToTable("InsertionSort_ALL_WORST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
    }
}


//Merge Sort Small Sample Function
void mergeSortSmall(int s_data[], bool best)
{
    //Test Merge Sort 10x on the Small Sample
    for (int i = 0; i < 10; i++)
    {
        MergeSort<int> small(1000);
        small.copy(s_data, 1000);
        auto start = high_resolution_clock::now();
        small.sort(0,999);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Merge Sort]" << endl;
        cout << "SMALL SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "SMALL SAMPLE - COMPARISONS: " << small.getComparisons() << endl;
        cout << "SMALL SAMPLE - SWAPS: " << small.getSwaps() << endl << endl;

        small.printToFile("smallMergeSort.txt");

        if (best)
        {
            printToTable("MergeSort_ALL_BEST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
        else
        {
            printToTable("MergeSort_ALL_WORST.csv", elapsed.count(), small.getComparisons(), small.getSwaps());
        }
    }
}

//Merge Sort Medium Sample Function
void mergeSortMedium(int m_data[], bool best)
{
    //Test Merge Sort 10x on the Medium Sample
    for (int i = 0; i < 10; i++)
    {
        MergeSort<int> medium(10000);
        medium.copy(m_data, 10000);
        auto start = high_resolution_clock::now();
        medium.sort(0,9999);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Merge Sort]" << endl;
        cout << "MEDIUM SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "MEDIUM SAMPLE - COMPARISONS: " << medium.getComparisons() << endl;
        cout << "MEDIUM SAMPLE - SWAPS: " << medium.getSwaps() << endl << endl;

        medium.printToFile("mediumMergeSort.txt");

        if (best)
        {
            printToTable("MergeSort_ALL_BEST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
        else
        {
            printToTable("MergeSort_ALL_WORST.csv", elapsed.count(), medium.getComparisons(), medium.getSwaps());
        }
    }
}

//Merge Sort Large Sample Function
void mergeSortLarge(int l_data[], bool best)
{
    //Test Merge Sort 10x on the Large Sample
    for (int i = 0; i < 10; i++)
    {
        MergeSort<int> large(100000);
        large.copy(l_data, 100000);
        auto start = high_resolution_clock::now();
        large.sort(0,99999);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;

        cout << "[" << i+1 << " - Merge Sort]" << endl;
        cout << "LARGE SAMPLE - SECONDS: " << elapsed.count() << endl;
        cout << "LARGE SAMPLE - COMPARISONS: " << large.getComparisons() << endl;
        cout << "LARGE SAMPLE - SWAPS: " << large.getSwaps() << endl << endl;
        large.printToFile("largeMergeSort.txt");

        if (best)
        {
            printToTable("MergeSort_ALL_BEST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
        else
        {
            printToTable("MergeSort_ALL_WORST.csv", elapsed.count(), large.getComparisons(), large.getSwaps());
        }
    }
}
#endif