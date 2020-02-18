// Prim Wandeevong // CS 302 - Homework 2: hw2.cpp // 2-17-20 //
#include <iostream>
#include "Stack.h"
#include"Node.h"
#include "Menu.h"
using namespace std;

int main()
{
    char expression[50];

    cout << "Please enter your mathematical expression (seperate each character with a space): ";
    cin.getline(expression,50);
    removeSpaces(expression);
    postFix(expression);
    
    return 0;
}
