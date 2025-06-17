#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        T tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && tmp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    insertion_sort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}