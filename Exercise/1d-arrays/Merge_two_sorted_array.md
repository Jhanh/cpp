# Trộn 2 dãy đã sắp xếp
&emsp;Cho 2 mảng 1 chiều A[] và B[] với kích thước lần lượt là N và M đã được sắp xếp theo thứ tự tăng dần. Nhiệm vụ của bạn là trộn 2 mảng này thành một mảng được sắp xếp theo thứ tự tăng dần. <br>

**Input Format** <br>
Dòng 1: N và M cách nhau 1 khoảng trắng <br>
Dòng 2: N phần tử của A[] <br>
Dòng 3: M phần tử của B[] <br>

**Output Format** <br>
Mảng tăng dần sau khi trộn A[] và B[] <br>

**Constraints** <br>
1 <= N,M <= 10^7 <br>
1 <= A[i],B[i] <= 10^9 <br>

**Example Input**
> 7 8 <br>
  1 2 4 6 7 10 25 <br>
  4 5 6 9 12 22 35 78 <br>

**Example Output**
> 1 2 4 4 5 6 6 7 9 10 12 22 25 35 78 <br>


### Note / Hint
- Dùng 2 con trỏ, 1 con trỏ vào A[] con còn lại trỏ vào B[]

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Time complexity: O(N + M)
// Space complexity: O(N + M)

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int i = 0, j = 0; // i trỏ vào mảng a còn j trỏ vào mảng b
    vector<int> v;
    while (i < n && j < m){
        if (a[i] <= b[j]){
            v.push_back(a[i]);
            ++i;
        }
        else{
            v.push_back(b[j]);
            ++j;
        }
    }
    while (i < n){
        v.push_back(a[i]);
        ++i;
    }
    while (j < m){
        v.push_back(b[j]);
        ++j;
    }

    for (int x : v)  cout << x << ' ';

    return 0;
}
```
