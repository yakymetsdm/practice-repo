// PrintInputNumber: This program type into console entered number

#include <iostream>
#include "io.h"

int main()
{
    std::cout << "Enter first number: ";
    int number_1 = readNumber();

    std::cout << "Enter second number: ";
    int number_2 = readNumber();

    writeAnswer(number_1 + number_2);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu