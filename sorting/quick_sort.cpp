#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void quick_sort(vector<T> &arr, const int &low, const int &high)
{
    if (low < high)
    {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
    }
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int n = arr.size();
    quick_sort(arr, 0, n - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}