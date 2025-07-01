#include <iostream>

using namespace std;

double f(double x, double y) { return x * y; } // dy/dx = xy

int main()
{
    double x = 0, y = 1, h = 0.001, xn = 1;
    while (x < xn)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        x += h;
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
    cout << y << "\n";
}
