#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubble_sort(vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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