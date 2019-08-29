#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}
long long FastMaxPairwiseProduct(const std::vector<int>& numbers){
    int n = numbers.size();
    long long first_max = 0;
    int first_max_i ;
    for(int i=0;i<n;i++){
        if(first_max < numbers[i]){
            first_max = numbers[i];
            first_max_i = i;
        }
    }
    long long second_max = 0;
    for(int i=0;i<n;i++){
        if(i!=first_max_i and second_max < numbers[i]){
            second_max = numbers[i];
        }
    }
    long long ans = first_max*second_max;
    return ans;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << FastMaxPairwiseProduct(numbers) << "\n";
    return 0;
}
