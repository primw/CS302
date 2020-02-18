#ifndef MENU_H
#define MENU_H
#include <string>
#include <cstring>

void removeSpaces(char str[]);
int precedence(char ch);
bool isOperand(char ch);
bool isOperator(char ch);
void postFix(char str[]);
double evaluatePostfix(std::string str);
int priority(char ch);

#endif