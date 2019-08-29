#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fast_get_fibonacci_last_digit_naive(int n){
    if(n==0) return 0;
    int a = 0;
    int b = 1;
    int temp;
    for(int i = 2; i <= n; i++){
        temp = b;
        b = (a+b)%10;
        a = temp;
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;
    int c = fast_get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
