#include <iostream>
using std::cin;
using std::cout;

// Time complexity: O(log(min(a, b)))
// Space complexity: O(1)

// Ước chung lớn nhất
// GCD(a, b) = GCD(b, a % b)
long long gcd (long long a, long long b){
    while(b){
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Bội chung nhỏ nhất
// LCM(a, b) = a*b / GCD(a, b)
long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

int main(){
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << ' ' << lcm(a, b);

    return 0;
}
