#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
long long fast_fibonacci_sum(long long n){

    if(n==0) return 0;
    //pattern length is 60
    long long sumd[60];
    sumd[0]=0;
    sumd[1]=1;
    long long ans ;
    long long a = 0;
    long long b = 1;
    long long temp;
    for(int i=2;i<60;i++){
      temp = b;
      b = (temp+a)%10;
      a = temp;

      sumd[i] = (b+sumd[i-1])%10;

    }
    ans = sumd[59]*(n/60) + sumd[n%60];
    return ans;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fast_fibonacci_sum(n);
}
