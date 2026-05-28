# Tính nCk bằng mảng 2 chiều
&emsp;Cho Q truy vấn với mỗi truy vấn yêu cầu tính tổ hợp chập K của N sau đó chia dư 10^9 + 7. <br>

**Input Format** <br>
Dòng 1: Q (Số lượng truy vấn) <br>
Q dòng còn lại: N, K <br>

**Output Format** <br>
Q dòng kết quả của phép toán nCk <br>

**Constraints** <br>
1 <= Q <= 10^6 <br>
1 <= N,K < 1000 <br>

**Example Input**
> 6 <br>
  5 2 <br>
  999 0 <br>
  999 999 <br>
  10 15 <br>
  6 3 <br>
  100 2 <br>

**Example Output**
> 10 <br>
  1 <br>
  1 <br>
  0 <br>
  20 <br>
  4950 <br>

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
#define limit 1001
#define MOD 1000000007

// Time complexity: O(N² + Q)
// Space complexity: O(N * N)

vector<vector<long long>> C(limit, vector<long long>(limit, 0));
void init(){
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i){ // bài toán con nhỏ nhất
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j]; // CT Pascal
                C[i][j] %= MOD;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int q; cin >> q;
    while (q--){
        int n, k; cin >> n >> k;
        if (k > n)  cout << 0 << '\n';
        else  cout << C[n][k] << '\n';
    }

    return 0;
}
```
