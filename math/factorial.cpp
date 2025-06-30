#include <iostream>

using namespace std;

unsigned int factorial(unsigned int n)
{

    return n == 0 ? 1 : n * factorial(n - 1);
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << factorial(n) << "\n";
    return 0;
}
