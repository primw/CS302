#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include "Menu.h"
#include "Stack.h"
using namespace std;

//isOperand Function
bool isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    else {return false;}
}

//isOperator Function
bool isOperator(char ch)
{
    switch(ch)
    {
        case '+': 
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}

//Remove Spaces Function
void removeSpaces(char str[])
{
    int i = 0, j = 0;

    while(str[i])
    {
        if(str[i] != ' ')
        {
            str[j++]= str[i];
        }
        i++;
    }
    str[j] = '\0';
}

//Post Fix Function
void postFix(char expression[])
{
    Stack<char> operator_stack;

    stringstream output;

    for (unsigned i = 0; i < strlen(expression); i++) 
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') 
        {
            while (!operator_stack.isEmpty() && priority(operator_stack.peek()) <= priority(expression[i])) 
            {
                output << operator_stack.peek();
                operator_stack.pop();
            }
            operator_stack.push(expression[i]);
        }
        else if (expression[i] == '(') 
        {
            operator_stack.push(expression[i]);
        } 
        else if (expression[i] == ')') 
        {
            while (operator_stack.peek() != '(') 
            {
                output << operator_stack.peek();
                operator_stack.pop();
            }

            operator_stack.pop();
        } 
        else 
        {
            output << expression[i];
        }
    }

    while (!operator_stack.isEmpty()) {
        output << operator_stack.peek();
        operator_stack.pop();
    }

    cout << "The postfix expression is: " << output.str() << endl;

    evaluatePostfix(output.str());
}

//Operator Precedence Function
int priority(char ch) 
{
    int temp;

    if (ch == '^')  {temp = 1;}
    else  if (ch == '*' || ch == '/')   {temp = 2;}
    else  if (ch == '+' || ch == '-') {temp = 3;}

    return temp;
}

//Evaluate Postfix Function
void evaluatePostfix(string expression)
{   
    Stack<double> operandStack;
    double result = 0;

    for(int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperand(expression[i]))
        {
            operandStack.push(expression[i] - '0');
        }
        else if (isOperator(expression[i]))
        {
            double operand1 = operandStack.peek();
            operandStack.pop();

            double operand2 = operandStack.peek();
            operandStack.pop();

            switch(expression[i])
            {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-': 
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2/operand1;
                    break;
                case '^':
                    result = pow(operand2, operand1);
            }

            operandStack.push(result);
        }
    }
    cout << "The result is: " << operandStack.peek() << endl;

}
