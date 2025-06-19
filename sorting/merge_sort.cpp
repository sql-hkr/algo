#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void merge(vector<T> &arr, int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;

    vector<T> L(nL), R(nR);

    for (int i = 0; i < nL; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < nR; j++)
        R[j] = arr[m + j + 1];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(vector<T> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    merge_sort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}