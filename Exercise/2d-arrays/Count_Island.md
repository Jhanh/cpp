# Đếm đảo
&emsp;Cho 1 mảng 2 chiều có kích thước N*M chỉ có hai giá trị là 0 và 1. Hãy đếm số lượng đảo, biết mỗi đảo gồm các số 1 chung cạnh với nhau. <br>

**Input Format** <br>
Dòng 1: N, M (Kích thước ma trận) <br>
N*M dòng còn lại: Các phần tử 0 hoặc 1 <br>

**Output Format** <br>
Số lượng đảo <br>

**Constraints** <br>
1 <= N, M <= 100 <br>
Đảm bảo các giá trị của ma trận chỉ có 1 hoặc 0 <br>

**Example Input**
> 8 9 <br>
  0 0 1 1 0 1 0 0 1 <br>
  1 0 0 1 0 0 0 0 1 <br>
  1 1 0 1 1 0 1 0 0 <br>
  1 1 1 0 0 0 1 1 0 <br>
  0 0 0 0 1 0 0 0 0 <br>
  0 1 1 1 0 1 0 0 0 <br>
  0 0 1 1 1 1 1 0 1 <br>
  0 0 0 1 0 1 1 1 1 <br>

**Example Output**
> 7 <br>

### Note / Hint
- Ta nên dùng 2 mảng 1 chiều để đại diện cho 4 ô xung quanh ô đang xét
- Đi đến ô nào bằng 1 thì cho bằng 0 để khi quay lui không bị lặp lại

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Tọa độ 4 ô chung cạnh
int dx[4] = {0,  0, 1, -1};
int dy[4] = {1, -1, 0,  0};
int n, m;
vector<vector<int>> v;

void dfs(int i, int j){
    v[i][j] = 0;  // đánh dấu đã đi qua rồi

    for (int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];

        // đảm bảo không đi ra ngoài mảng
        if (x>=0 && x<n && y>=0 && y<m && v[x][y]==1){
            dfs(x, y);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 1){
                ++cnt;
                dfs(i, j);
            }
        }
    }
    cout << cnt;

    return 0;
}
```
