#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int modpow(int a, int b, int m)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
            r = 1LL * r * a % m;
        a = 1LL * a * a % m;
        b >>= 1;
    }
    return r;
}

int main()
{
    int p = 7919, q = 1009, n = p * q, e = 5, phi = (p - 1) * (q - 1);
    int d = 1;
    while ((e * d) % phi != 1)
        d++;
    int m = 123;              // Message
    int c = modpow(m, e, n);  // Encrypt the message
    int m2 = modpow(c, d, n); // Decrypt the message
    cout << "enc:" << c << " dec:" << m2 << endl;
}