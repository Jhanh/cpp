# Tổng hình chữ nhật
&emsp;Cho mảng 2 chiều số nguyên A[i][j] có kích thước N*M, và Q truy vấn. Mỗi truy vấn ta tính tổng giá trị các phần tử trong hình chữ nhật được yêu cầu nằm trong mảng 2 chiều. <br>

**Input Format** <br>
Dòng 1: N, M (Kích thước mảng 2 chiều) <br>
N*M dòng tiếp theo: Giá trị của mảng 2 chiều <br>
Dòng kế tiếp: Q (Số lượng truy vấn) <br>
Q dòng còn lại: r1, c1, r2, c2 (Hai ô góc trên đường chéo chính) <br>

**Output Format** <br>
Q dòng thỏa yêu cầu đề bài <br>

**Constraints** <br>
1 <= N,M <= 1000 <br>
1 <= Q <= 10^5 <br>
1 <= A[i][j] <= 10^6 <br>
1 <= r1,r2 <= N &emsp; 1 <= c1,c2 <= M <br>

**Example Input**
> 3 4 <br>
  10 20 30 40 <br>
  50 60 70 80 <br>
  1000000 1000000 1000000 1000000 <br>
  5 <br>
  1 1 3 4 <br>
  1 1 1 1 <br>
  3 4 3 4 <br>
  2 2 3 3 <br>
  1 4 3 4 <br>

**Example Output**
> 4000360 <br>
  10 <br>
  1000000 <br>
  2000130 <br>
  1000120 <br>

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Time complexity: O(N*M) nhưng mỗi truy vấn chỉ còn O(1)
// Space complexity: O(N*M)

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<long long>> pre(n+1, vector<long long>(m+1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            // pre[i-1][j]  : tổng phần trên
            // pre[i][j-1]  : tổng phần bên trái
            // pre[i-1][j-1]: do phần trên và phần bên trái giao nhau 1 khoảng giữa nên ta phải trừ ra
            // v[i-1][j-1]  : phần tử hiện tại (do based-index là 1 nên i,j phải trừ 1)
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i-1][j-1];
        }
    }

    int q; cin >> q;
    while (q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // pre[r2][c2]    : ô chứa tổng hcn từ [0][0] đến [r2][c2]
        // pre[r1-1][c2]  : tổng phần trên
        // pre[r2][c1-1]  : tổng phần bên trái
        // pre[r1-1][c1-1]: phần giao của phần trên và phần bên trái
        cout << pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1] << '\n';
    }

    return 0;
}

```
