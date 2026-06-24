#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

// Số abundant là số mà tổng các ước không bao gồm nó lớn hơn nó

bool abundant(int n){
    if (n <= 1)  return false; // Số abundant nhỏ nhất là 12

    long long sum = 1;  // Luôn có ước là 1
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            sum += i;
            if (n/i != i)  sum += n/i;  // Cộng thêm ước đối xứng nếu nó khác i
        }
    }

    return sum > n;
}

int main(){
    int n; cin >> n;
    if (abundant(n))  cout << "Yes";
    else  cout << "No";

    return 0;
}
