#include <iostream>

using namespace std;

unsigned long long fibonacci(unsigned int n)
{

    return n <= 1 ? n : fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << fibonacci(n) << "\n";
    return 0;
}
