#include <iostream>
using std::cin;
using std::cout;

// Phi hàm Euler: là số lượng cặp số trong khoảng (1-n) với n, có gcd bằng 1
/*
Nếu đếm cặp số và tính gcd thì sẽ tốn O(N log(N)) nên ta sẽ dùng công thức:
φ(N) = N * (1 - 1/p₁)  * (1 - 1/p₂) * ...

Trong code ta sẽ chuyển như sau:
res = res * (1 - 1/p)
res = res - res/p
*/
// Time complexity: O(sqrt(N))
// Space complexity: O(1)

long long euler (long long n){
    long long res = n;
    for (long long i = 2; i*i <= n; i++){ // duyệt tìm thừa số nguyên tố
        if (n % i == 0){
            res = res - res/i;
            while (n % i == 0){ // bỏ qua bội số bị trùng
                n /= i;
            }
        }
    }
    if (n > 1)  res = res - res/n;
    return res;
}

int main(){
    long long n; cin >> n;
    cout << euler(n);

    return 0;
}
