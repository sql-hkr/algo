#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using Mat = vector<vector<double>>;

static double pythag(double a, double b)
{
    double at = fabs(a), bt = fabs(b);
    if (at > bt)
    {
        double r = bt / at;
        return at * sqrt(1 + r * r);
    }
    return bt == 0 ? 0 : bt * sqrt(1 + (at / bt) * (at / bt));
}

// Golub-Reinsch SVD (m >= n): A = U * diag(w) * V^T
// thin U(m x n), w(n), V(n x n)
void svd(Mat A, Mat &U, vector<double> &w, Mat &V)
{
    int m = A.size(), n = A[0].size();
    U = A;
    w.assign(n, 0);
    V.assign(n, vector<double>(n, 0));
    vector<double> rv1(n, 0);
    double g = 0, scale = 0, anorm = 0;

    for (int i = 0; i < n; i++)
    {
        rv1[i] = scale * g;
        g = scale = 0;
        for (int k = i; k < m; k++)
            scale += fabs(U[k][i]);
        if (scale)
        {
            double s = 0;
            for (int k = i; k < m; k++)
            {
                U[k][i] /= scale;
                s += U[k][i] * U[k][i];
            }
            double f = U[i][i], h;
            g = -copysign(sqrt(s), f);
            h = f * g - s;
            U[i][i] = f - g;
            for (int j = i + 1; j < n; j++)
            {
                double t = 0;
                for (int k = i; k < m; k++)
                    t += U[k][i] * U[k][j];
                t /= h;
                for (int k = i; k < m; k++)
                    U[k][j] += t * U[k][i];
            }
            for (int k = i; k < m; k++)
                U[k][i] *= scale;
        }
        w[i] = scale * g;
        g = scale = 0;
        if (i < n - 1)
        {
            for (int k = i + 1; k < n; k++)
                scale += fabs(U[i][k]);
            if (scale)
            {
                double s = 0;
                for (int k = i + 1; k < n; k++)
                {
                    U[i][k] /= scale;
                    s += U[i][k] * U[i][k];
                }
                double f = U[i][i + 1], h;
                g = -copysign(sqrt(s), f);
                h = f * g - s;
                U[i][i + 1] = f - g;
                for (int k = i + 1; k < n; k++)
                    rv1[k] = U[i][k] / h;
                for (int j = i + 1; j < m; j++)
                {
                    double t = 0;
                    for (int k = i + 1; k < n; k++)
                        t += U[j][k] * U[i][k];
                    for (int k = i + 1; k < n; k++)
                        U[j][k] += t * rv1[k];
                }
                for (int k = i + 1; k < n; k++)
                    U[i][k] *= scale;
            }
        }
        anorm = max(anorm, fabs(w[i]) + fabs(rv1[i]));
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && g)
        {
            for (int j = i + 1; j < n; j++)
                V[j][i] = (U[i][j] / U[i][i + 1]) / g;
            for (int j = i + 1; j < n; j++)
            {
                double t = 0;
                for (int k = i + 1; k < n; k++)
                    t += U[i][k] * V[k][j];
                for (int k = i + 1; k < n; k++)
                    V[k][j] += t * V[k][i];
            }
            for (int j = i + 1; j < n; j++)
                V[i][j] = V[j][i] = 0;
        }
        V[i][i] = 1;
        g = rv1[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        g = w[i];
        for (int j = i + 1; j < n; j++)
            U[i][j] = 0;
        if (g)
        {
            g = 1.0 / g;
            for (int j = i + 1; j < n; j++)
            {
                double t = 0;
                for (int k = i + 1; k < m; k++)
                    t += U[k][i] * U[k][j];
                t = (t / U[i][i]) * g;
                for (int k = i; k < m; k++)
                    U[k][j] += t * U[k][i];
            }
            for (int k = i; k < m; k++)
                U[k][i] *= g;
        }
        else
            for (int k = i; k < m; k++)
                U[k][i] = 0;
        U[i][i]++;
    }

    for (int k = n - 1; k >= 0; k--)
    {
        for (int its = 0; its < 30; its++)
        {
            bool flag = true;
            int nm = 0, l = k;
            for (; l >= 0; l--)
            {
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm)
                {
                    flag = false;
                    break;
                }
                if (l == 0 || fabs(w[nm]) + anorm == anorm)
                    break;
            }
            if (flag)
            {
                double c = 0, s = 1;
                for (int i = l; i <= k; i++)
                {
                    double f = s * rv1[i];
                    rv1[i] *= c;
                    if (fabs(f) + anorm == anorm)
                        break;
                    g = w[i];
                    double h = pythag(f, g);
                    w[i] = h;
                    h = 1.0 / h;
                    c = g * h;
                    s = -f * h;
                    for (int j = 0; j < m; j++)
                    {
                        double y = U[j][nm], z = U[j][i];
                        U[j][nm] = y * c + z * s;
                        U[j][i] = z * c - y * s;
                    }
                }
            }
            double z = w[k];
            if (l == k)
            {
                if (z < 0)
                {
                    w[k] = -z;
                    for (int j = 0; j < n; j++)
                        V[j][k] = -V[j][k];
                }
                break;
            }
            double x = w[l], y = w[k - 1];
            g = rv1[k - 1];
            double h = rv1[k];
            double f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2 * h * y);
            g = pythag(f, 1.0);
            f = ((x - z) * (x + z) + h * (y / (f + copysign(g, f)) - h)) / x;
            double c = 1, s = 1;
            for (int j = l; j < k; j++)
            {
                int i = j + 1;
                g = rv1[i];
                y = w[i];
                h = s * g;
                g *= c;
                z = pythag(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y *= c;
                for (int jj = 0; jj < n; jj++)
                {
                    double xv = V[jj][j], zv = V[jj][i];
                    V[jj][j] = xv * c + zv * s;
                    V[jj][i] = zv * c - xv * s;
                }
                z = pythag(f, h);
                w[j] = z;
                if (z)
                {
                    c = f / z;
                    s = h / z;
                }
                f = c * g + s * y;
                x = c * y - s * g;
                for (int jj = 0; jj < m; jj++)
                {
                    double yu = U[jj][j], zu = U[jj][i];
                    U[jj][j] = yu * c + zu * s;
                    U[jj][i] = zu * c - yu * s;
                }
            }
            rv1[l] = 0;
            rv1[k] = f;
            w[k] = x;
        }
    }
}

int main()
{
    Mat A = {{1, 2}, {3, 4}, {5, 6}};
    Mat U, V;
    vector<double> w;
    svd(A, U, w, V);
    cout << "Singular values:";
    for (double sv : w)
        cout << " " << sv;
    cout << "\n";
}
