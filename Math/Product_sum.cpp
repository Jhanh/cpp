#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::sort;
const int MOD = 1000000007;

// Product sum là tổng lớn nhất của các tích 2 số là index và giá trị tại index đó
// Time complexity: O(N logN)
// Space complexity: O(N)

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long res = 0;
    for (int i = 0; i < n; i++){
        long long prodt = (1ll*i * v[i]) % MOD;
        res += prodt % MOD;
    }
    cout << res;

    return 0;
}
