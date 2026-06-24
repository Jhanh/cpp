#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

// Số pronic là tích của 2 số liên tiếp: n = k * (k+1)
// k ~ sqrt(n)
// Time complexity: O(1)
// Space complexity: O(1)

bool pronic(int n){
    if (n < 0)  return false;

    int k = sqrt(n);
    if ((1ll*k * (k + 1)) == n)  return true;
    return false;
}

int main(){
    int n; cin >> n;
    if (pronic(n))  cout << "Yes";
    else  cout << "No";

    return 0;
}
