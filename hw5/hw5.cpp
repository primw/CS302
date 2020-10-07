// Prim Wandeevong // CS 302 - Homework 5: hw5.cpp // 4-21-20 //
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

const int NUM_VALS = 100;
const int MIN_VAL = 1;
const int MAX_VAL = 200;
const string FILENAME = "numbers.txt";

int generateNumber(int min, int max);

int main() 
{
    BinarySearchTree<int> myBinaryTree;
    ofstream outFile;

    outFile.open(FILENAME);

    srand(time(NULL));
    for (int i = 0; i < NUM_VALS; i++) 
    {
        int random = generateNumber(MIN_VAL, MAX_VAL);
        outFile << random << endl;
        myBinaryTree.add(random);
    }


    cout << "HEIGHT: " << myBinaryTree.getHeight() << endl << endl;
    myBinaryTree.preorderTraverse();
    myBinaryTree.inorderTraverse();
    myBinaryTree.postorderTraverse();

    return 0;
}


int generateNumber(int min, int max) 
{
    int diff = max - min;
    return (rand() % diff) + min;
}
