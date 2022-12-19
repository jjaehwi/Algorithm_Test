#include <iostream>
#include <iomanip>
int main()
{
    float a;
    std::cin >> a;
    std::cout.setf(std::ios::showpoint);
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << a;
}