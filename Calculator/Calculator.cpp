/* Calculator.cpp : This file - simple calculator program
 * that calculate input expression */ 
#include <iostream>
#include "functions.h"


int main()
{
    double number_1 = readNumber();
    char operation = readOperation();
    double number_2 = readNumber();
    double calcResult;

    switch (operation)
    {
    case '+':
        calcResult = add(number_1, number_2);
        std::cout << number_1 << " " << operation << " " << number_2 << " = " << calcResult;
        break;
    case '-':
        calcResult = substract(number_1, number_2);
        std::cout << number_1 << " " << operation << " " << number_2 << " = " << calcResult;
        break;
    case '*':
        calcResult = multiply(number_1, number_2);
        std::cout << number_1 << " " << operation << " " << number_2 << " = " << calcResult;
        break;
    case '/':
        calcResult = divide(number_1, number_2);
        std::cout << number_1 << " " << operation << " " << number_2 << " = " << calcResult;
        break;
    default:
        std::cout << "Invalid operation!!!";
        break;
    }

    return 0;
}
