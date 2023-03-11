#include <iostream>

int readNumber()
{
    int number;

    std::cin >> number;
    return number;
}

void writeAnswer(int sum)
{
    std::cout << "Sum of your numbers is: " << sum;
}