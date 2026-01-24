#include <iostream>
#include <iomanip>

long double bbp_pi(int terms)
{
    long double sum = 0.0L;
    long double inv16pow = 1.0L;

    for (int k = 0; k < terms; ++k)
    {
        long double k8 = 8.0L * k;

        long double term =
            4.0L / (k8 + 1.0L) -
            2.0L / (k8 + 4.0L) -
            1.0L / (k8 + 5.0L) -
            1.0L / (k8 + 6.0L);

        sum += inv16pow * term;
        inv16pow /= 16.0L;
    }
    return sum;
}

int main()
{
    int terms = 30;
    long double pi = bbp_pi(terms);

    std::cout << std::setprecision(40);
    std::cout << "BBP pi (terms=" << terms << "):\n"
              << pi << "\n";
    return 0;
}