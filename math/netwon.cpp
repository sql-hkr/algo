#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return x * x - 2;
}

double df(double x)
{
    return 2 * x; // f'(x)
}

int main()
{
    double x0 = 1.0;
    double tolerance = 1e-6;
    int max_iter = 1000;
    int iter = 0;

    while (iter < max_iter)
    {
        double x1 = x0 - f(x0) / df(x0);

        if (abs(x1 - x0) < tolerance)
            break;

        x0 = x1;
        iter++;
    }
    cout << "∃x≃" << x0 << ", f(x)≃0\n";
    return 0;
}
