#include <iostream>
using std::cin;
using std::cout;
const int mod = 1000000007;

/*
Lũy thừa nhị phân
Nếu dùng a^n thì time complexity = O(N)
Nên dùng công thức Lũy thừa nhị phân với time complexity = O(logN)

    =           1            Nếu n = 0
a^n = a^(n/2) * a^(n/2)      Nếu n > 0 và n chẵn
    = a^(n/2) * a^(n/2) * a  Nếu n > 0 và n lẻ
*/

long long binpow (long long a, long long b){
    // a là cơ số, b là số mũ
    if (b == 0)  return 1;

    long long x = binpow(a, b/2);
    if (b % 2 == 0){ // Nếu mũ chẵn
        // CT: (A * B) % C = [(A % C) * (B % C)] % C
        return ((x % mod) * (x % mod)) % mod; // có thể return (x * x) % mod vì sau hàm binpow thì số luôn được % mod rồi
    }
    else{
        return ((((x % mod) * (x % mod)) % mod) * ((a % mod) % mod)) % mod;  // có thể return (x * x * a) % mod vì sau hàm binpow thì số luôn được % mod rồi
    }
}

int main(){
    long long a, b;
    cin >> a >> b;
    cout << binpow(a, b);
    
    return 0;
}
