#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<complex<double>> x(N), X(N);
    for (int i = 0; i < N; i++)
    {
        double a;
        cin >> a;
        x[i] = a;
    }
    for (int k = 0; k < N; k++)
        for (int n = 0; n < N; n++)
            X[k] += x[n] * exp(complex<double>(0, -2 * M_PI * k * n / N));
    for (auto y : X)
        cout << abs(y) << "\n";
}
