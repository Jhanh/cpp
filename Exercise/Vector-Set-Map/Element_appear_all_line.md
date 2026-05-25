# Phần tử xuất hiện ở mọi dòng
&emsp;Cho một số nguyên int N và một ma trận N*N, hãy tìm ra tất cả giá trị xuất hiện ở mọi dòng. <br>

**Input Format** <br>
Dòng 1: N (số dòng của ma trận) <br>
N dòng tiếp theo: N giá trị <br>

**Output Format** <br>
Tất cả giá trị xuất hiện ở mọi dòng, nếu không có thì in "NOT FOUND" <br>

**Constraints** <br>
1 <= N <= 100 <br>
Các phần tử trong ma trận: 0 <= x <= 10^6

**Example Input**
> 5 <br>
  1 4 2 6 2 <br>
  2 5 3 6 1 <br>
  7 1 8 2 0 <br>
  9 3 1 2 4 <br>
  2 4 5 5 1 <br>

**Example Output**
> 1 2

### Note / Hint
- Không cần phải dùng đến mảng 2 chiều để lưu vì ta chỉ thao tác với các phần tử trên từng dòng.
- Dùng 1 mảng để đánh dấu, tại hàng i thì kiểm tra xem phần tử có nằm ở hàng i-1 không.

## Code
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::max;
#define limit 1000001

int main(){
    int n; cin >> n;
    vector<int> tmp(limit, 0);
    int maxVal = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;
            if (tmp[x] == i)  ++tmp[x];
            maxVal = max(maxVal, x);
        }
    }

    bool check = true;
    for (int i = 0; i <= maxVal; i++){
        if (tmp[i] == n){
            cout << i << ' ';
            check = false;
        }
    }
    if (check)  cout << "NOT FOUND";

    return 0;
}

```
