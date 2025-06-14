#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binary_search(vector<T> &arr, T target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int m = (low + high) / 2;
        if (arr[m] == target)
        {
            return m;
        }
        else if (arr[m] > target)
        {
            high = m - 1;
        }
        else
        {
            low = m + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    cin >> target;
    cout << binary_search(arr, target) << "\n";
    return 0;
}