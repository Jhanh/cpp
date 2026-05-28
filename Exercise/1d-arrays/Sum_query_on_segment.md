# Truy vấn tổng trên đoạn
&emsp;Cho mảng 1 chiều số nguyên có N phần tử, hãy thực hiện Q truy vấn với mỗi truy vấn ta tính tổng các phần tử từ chỉ số left đến chỉ số right theo yêu cầu. <br>

**Input Format** <br>
Dòng 1: N (Số phần tử của mảng 1 chiều) <br>
Dòng 2: N phần tử <br>
Dòng 3: Q (Số truy vấn cần thực hiện) <br>
Q dòng còn lại: left và right cách nhau 1 khoảng trắng <br>

**Output Format** <br>
Q kết quả hiển thị trên từng dòng <br>

**Constraints** <br>
1 <= N,Q <= 10^6 <br>
1 <= a[i] <= 10^9 <br>
0 <= left <= right <= N-1 <br>

**Example Input**
> 5 <br>
  1000000000 2 1000000000 5 1000000000 <br>
  5 <br>
  0 4 <br>
  0 0 <br>
  4 4 <br>
  1 3 <br>
  0 2 <br>

**Example Output**
> 3000000007 <br>
  1000000000 <br>
  1000000000 <br>
  1000000007 <br>
  2000000002 <br>


### Note / Hint
- Tính mảng cộng dồn (Prefix Sum)
- a[right] - a[left - 1]. Chú ý với trường hợp left = 0

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Time complexity: O(N + q)
// Space complexity: O(N)

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    // Mảng cộng dồn (Prefix sum)
    vector<long long> p(n);
    for (int i = 0; i < n; i++){
        if (i == 0)  p[i] = v[i];
        else  p[i] = p[i-1] + v[i];
    }

    int q; cin >> q;
    while(q--){
        int left, right;
        cin >> left >> right;
        if (left == 0){
            cout << p[right] << '\n';
        }
        else{
            cout << p[right] - p[left - 1] << '\n';
        }
    }

    return 0;
}
```
