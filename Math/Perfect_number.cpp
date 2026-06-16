#include <iostream>
using std::cin;
using std::cout;

// Số hoàn hảo: Là số mà tổng các ước của nó và không tính bản thân nó bằng chính số đó
// Time complexity: O(sqrt(N))
// Space complexity: O(1)

bool perfectNum (long long n){
    if (n <= 1)  return false;

    long long sum = 1;
    for (long long i = 2; i*i <= n; i++){
        if (n % i == 0){
            sum += i;
            if (n/i != i)  sum += n/i;
        }
    }
    return sum == n;
}

int main(){
    long long n; cin >> n;
    if (perfectNum(n))  cout << "YES";
    else  cout << "NO";

    return 0;
}
