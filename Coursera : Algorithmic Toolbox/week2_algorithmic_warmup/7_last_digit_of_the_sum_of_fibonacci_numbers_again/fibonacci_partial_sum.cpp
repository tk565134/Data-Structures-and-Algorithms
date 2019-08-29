#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long fast_fibonacci_sum(long long n){

    if(n==0) return 0;
    //pattern length is 60
    long long sumd[60];
    sumd[0]=0;
    sumd[1]=1;
    long long a = 0;
    long long b = 1;
    long long temp;
    for(int i=2;i<60;i++){
      temp = b;
      b = (temp+a)%10;
      a = temp;

      sumd[i] = (b+sumd[i-1])%10;
      //std::cout<< i <<" "<< sumd[i]<<"\n";
    }

    return sumd[n%60];
}
long long get_fibonacci_partial_sum_fast(long long from, long long to){
    
    return  (fast_fibonacci_sum(to) + 10 - fast_fibonacci_sum(from-1) ) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
