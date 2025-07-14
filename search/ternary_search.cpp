#include <iostream>

using namespace std;

int ternary_search(int a[], int l, int r, int k)
{
    while (l <= r)
    {
        int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (a[m1] == k)
            return m1;
        if (a[m2] == k)
            return m2;
        if (k < a[m1])
            r = m1 - 1;
        else if (k > a[m2])
            l = m2 + 1;
        else
            l = m1 + 1, r = m2 - 1;
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k = 7;
    cout << ternary_search(a, a[0], a[sizeof(a) / sizeof(*a) - 1], k) << endl;
}
