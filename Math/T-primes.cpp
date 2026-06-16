#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::vector;
using std::sqrt;
#define limit 10000001

// T-primes hay còn gọi là số có đúng 3 ước số dương duy nhất; là 1, chính nó, căn bậc 2 của nó
// Cách chứng minh: Nó phải là số chính phương (căn bậc hai là số nguyên) và căn bậc hai phải là một số nguyên tố
// Time complexity: O(limit log(log limit) + q)
// Space complexity: O(limit)

vector<bool> prime(limit, true);
void sieve(){
    prime[0] = prime[1] = false;

    for (int i = 2; i*i < limit; i++){
        if (prime[i]){
            for (int j = i*i; j < limit; j += i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    sieve();

    int q; cin >> q;
    while (q--){
        long long n; cin >> n;
        long long tmp = sqrt(n);

        if (tmp * tmp == n && prime[tmp])  cout << "YES\n";
        else  cout << "NO\n";
    }

    return 0;
}
