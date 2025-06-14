#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int linear_search(vector<T> &arr, T target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int target;
    cin >> target;
    cout << linear_search(arr, target) << "\n";
    return 0;
}