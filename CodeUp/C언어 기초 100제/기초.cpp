#include <iomanip>
#include <iostream>
int main()
{
    float a;
    std::cin >> a;
    std::cout.setf(std::ios::showpoint);
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << a;
}