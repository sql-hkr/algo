#include <iostream>
#include <string>

using namespace std;

const string digits = "0123456789ABCDEF";

string convert_base(int n, int base) {
  if (n == 0)
    return "0";
  string res = "";
  while (n) {
    res = digits[n % base] + res;
    n /= base;
  }
  return res;
}

int main() {
  int n, base;
  cin >> n >> base;
  cout << convert_base(n, base) << endl;
  return 0;
}
