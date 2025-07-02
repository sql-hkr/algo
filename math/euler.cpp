#include <iostream>

using namespace std;

double f(double x, double y) { return x * y; } // dy/dx = xy

int main()
{
    double x = 0, y = 1, h = 0.001, xn = 1;
    while (x < xn)
        x += h, y += h * f(x, y);
    cout << y << "\n";
}
