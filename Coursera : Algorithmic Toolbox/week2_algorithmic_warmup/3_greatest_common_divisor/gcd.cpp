#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int fast_gcd(int a, int b){
    if(a==0) return b;
    return fast_gcd(b%a, a);
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << fast_gcd(a, b) << std::endl;
  return 0;
}
