#include <iostream>

using namespace std;

int _gcd(int a, int b)
{
    return b == 0 ? a : _gcd(b, a % b);
}

int gcd(int a, int b)
{

    if (a < b)
        swap(a, b);
    return _gcd(a, b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << "\n";
    return 0;
}