#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubble_sort(vector<T> &arr)
{
    int n = arr.size() - 1;
    bool swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    bubble_sort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}