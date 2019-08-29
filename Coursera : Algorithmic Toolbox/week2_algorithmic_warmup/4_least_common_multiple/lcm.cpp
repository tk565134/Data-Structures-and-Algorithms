#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int fast_gcd(int a, int b){
    if(a==0) return b;
    return fast_gcd(b%a, a);
}

long long fast_lcm(long long a, long long b){
    long long ans = (a*b)/fast_gcd(a, b);
    return ans;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << fast_lcm(a, b) << std::endl;
  return 0;
}
