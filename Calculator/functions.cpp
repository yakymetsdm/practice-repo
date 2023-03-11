//This contains functions for calculatings

#include <iostream>

//Function for user input
double readNumber()
{
    double number;

    std::cout << "Enter number: ";
    std::cin >> number;

    return number;
}

char readOperation()
{
    char operation;

    std::cout << "Enter operation type (+ - * /): ";
    std::cin >> operation;

    return operation;
}

//This is addition function
double add(double number_1, double number_2)
{
    return number_1 + number_2;
}

//This is substraction function
double substract(double number_1, double number_2)
{
    return number_1 - number_2;
}

//This is multiplication function
double multiply(double number_1, double number_2)
{
    return number_1 * number_2;
}

//This is division function
double divide(double number_1, double number_2)
{
    return number_1 / number_2;
}