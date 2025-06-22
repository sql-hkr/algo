#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> gauss(vector<vector<double>> A, vector<double> b)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[p][i]))
                p = j;
        swap(A[i], A[p]), swap(b[i], b[p]);
        for (int j = i + 1; j < n; j++)
        {
            double f = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
                A[j][k] -= f * A[i][k];
            b[j] -= f * b[i];
        }
    }
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    return x;
}

int main()
{
    vector<vector<double>> A = {{2, -1, 1}, {3, 3, 9}, {3, 3, 5}};
    vector<double> b = {8, 0, -6};
    vector<double> x = gauss(A, b);
    for (int i = 0; i < x.size(); i++)
        cout << "x" << i + 1 << ": " << x[i] << "\n";
}