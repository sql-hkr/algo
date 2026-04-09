#include <iostream>
#include <vector>
using namespace std;

vector<int> lu(vector<vector<double>> &A)
{
    int n = A.size();
    vector<int> P(n);
    for (int i = 0; i < n; i++)
        P[i] = i;
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[p][i]))
                p = j;
        swap(A[i], A[p]), swap(P[i], P[p]);
        for (int j = i + 1; j < n; j++)
        {
            A[j][i] /= A[i][i];
            for (int k = i + 1; k < n; k++)
                A[j][k] -= A[j][i] * A[i][k];
        }
    }
    return P;
}

vector<double> solve(const vector<vector<double>> &LU, const vector<int> &P, const vector<double> &b)
{
    int n = LU.size();
    vector<double> x(n);
    for (int i = 0; i < n; i++)
    {
        x[i] = b[P[i]];
        for (int j = 0; j < i; j++)
            x[i] -= LU[i][j] * x[j];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
            x[i] -= LU[i][j] * x[j];
        x[i] /= LU[i][i];
    }
    return x;
}

int main()
{
    vector<vector<double>> A = {{2, -1, 1}, {3, 3, 9}, {3, 3, 5}};
    vector<double> b = {8, 0, -6};
    vector<int> P = lu(A);
    vector<double> x = solve(A, P, b);
    for (int i = 0; i < (int)x.size(); i++)
        cout << "x" << i + 1 << ": " << x[i] << "\n";
}
