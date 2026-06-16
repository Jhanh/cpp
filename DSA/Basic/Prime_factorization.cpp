#include <iostream>
using std::cin;
using std::cout;

// Time complexity: O(sqrt(N))
// Space complexity: O(1)

void primeFactorization (long long n){
    for (long long i = 2; i*i <= n; i++){
        if (n%i == 0){
            while (n%i == 0){
                cout << i << ' ';
                n /= i;
            }
        }
    }
    if (n > 1)  cout << n;
}

int main(){
    long long n;
    cin >> n;
    primeFactorization(n);

    return 0;
}
