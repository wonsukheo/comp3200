#include <iostream>

#include "Add.h"

int main()
{
    int a = 10;
    int b = 15;

    int result = lab1::Add(a, b);

    std::cout << result << std::endl;

    return 0;
}