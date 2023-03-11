// SwapperOfNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program swap value two numbers

#include <iostream>

int main()
{
    int smaller_number, greater_number;
    std::cout << "Enter number: ";
    std::cin >> smaller_number;
    std::cout << "Enter greater number: ";
    std::cin >> greater_number;

    if (smaller_number > greater_number)
    {
        int temp = smaller_number;
        smaller_number = greater_number;
        greater_number = temp;

        std::cout << "Swap values!" << std::endl;
        std::cout << "Smaller number: " << smaller_number << std::endl;
        std::cout << "Greater number: " << greater_number << std::endl;
    }
    else if (smaller_number == greater_number)
    {
        std::cout << "Numbers are equal!!" << std::endl;
    }
    else
    {
        std::cout << "Smaller number: " << smaller_number << std::endl;
        std::cout << "Greater number: " << greater_number << std::endl;
    }

    return 0;
}
