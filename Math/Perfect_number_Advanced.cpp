#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

// Dùng định lý Euclid-Euler
// 2^(p-1) * (2^p - 1)
// Số hoàn hảo theo cách này giải quyết được số rất lớn
// Time complexity: O(1)
// Space complexity: O(1)

bool isPrime(long long n){
    if (n < 2)  return false;

    for (long long i = 2; i*i <= n; i++){
        if (n % i == 0)  return false;
    }
    return false;
}

bool perfectNum(long long n){
    for (int p = 2; p <= 32; p++){ // Chỉ duyệt với 32 vì 2^32 là giới hạn của long long
        if (isPrime(p)){
            long long tmp = (1ll << p) - 1;  // (1ll << p) = pow(2, p)
            if (isPrime(tmp)){
                long long perfectVal = tmp * (1ll << (p-1));
                if (n == perfectVal)  return true;
            }
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    long long n; cin >> n;
    if (perfectNum(n))  cout << "YES";
    else  cout << "NO";

    return 0;
}
