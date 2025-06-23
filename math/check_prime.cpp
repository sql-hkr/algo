#include <iostream>

using namespace std;

bool is_prime(unsigned int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (unsigned int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << (is_prime(n) ? "prime" : "composite") << "\n";
    return 0;
}