#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long loopSearch(long long m){
    long long f1 = 0;
    long long f2 = 1;
    long long f3 = 1;
    long long temp;

    for(long long i = 2; i <= m*m; i++){
        f1 = f2;
        f2 = f3;
        f3 = (f1+f2)%m;
        //std::cout<< f1 <<" "<< f2 <<" "<< f3 <<"\n";
        if(f1==0 and f2==1 and f3==1){
          return i-1;
        }
    }
    return m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    long long pi = loopSearch(m);
    long long l = n%pi;
    //std::cout<< pi <<" "<< l <<"\n";
    if(l==0) return 0;
    long long a = 0;
    long long b = 1;
    long long temp;
    for(long long i=2; i<=l; i++){
        temp = b;
        b = (temp+a)%m;
        a = temp;
    }

    return b;

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
