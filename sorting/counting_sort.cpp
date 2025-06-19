#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void counting_sort(vector<T> &arr)
{
    int n = arr.size();
    std::vector<T> tmp(n);
    std::copy(arr.begin(), arr.end(), tmp.begin());
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    vector<T> count(max - min + 1, 0);
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    for (int i = 1; i < (max - min + 1); i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        arr[count[tmp[i] - min] - 1] = tmp[i];
        count[arr[i] - min]--;
    }
}

int main()
{
    vector<int> arr = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    counting_sort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}