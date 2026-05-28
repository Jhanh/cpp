# Mảng hiệu
&emsp;Cho mảng số nguyên A[] có N phần tử, với Q thao tác. Với mỗi thao tác ta tăng tất cả giá trị trong đoạn từ chỉ số left đến chỉ số right lên K đơn vị. Sau đó in mảng sau khi thực hiện Q thao tác. <br>

**Input Format** <br>
Dòng 1: N (Số phần tử của mảng 1 chiều) <br>
Dòng 2: N phần tử <br>
Dòng 3: Q (Số truy vấn cần thực hiện) <br>
Q dòng còn lại: left, right và K cách nhau 1 khoảng trắng <br>

**Output Format** <br>
Mảng sau khi đã thực hiện Q thao tác <br>

**Constraints** <br>
1 <= N <= 10^6 <br>
1 <= Q <= 10^5 <br>
1 <= A[i] <= 10^9 <br>
0 <= left <= right <= N-1 <br>
1 <= K <= 10^9 <br>

**Example Input**
> 6 <br>
  1000000000 500000000 1 1000000000 2 999999999 <br>
  5 <br>
  0 5 1000000000 <br>
  0 0 500000000 <br>
  5 5 1000000000 <br>
  2 4 10 <br>
  1 3 1000000000 <br>


**Example Output**
> 2500000000 2500000000 2000000011 3000000010 1000000012 2999999999

### Note / Hint
- Dùng mảng hiệu (Difference array) cho toàn mảng
- Xác định điểm bắt đầu và điểm kết thúc khoảng cần tăng
- Tăng k lần ở chỉ số bắt đầu, giảm k lần ở phía sau kết thúc
- Dùng mảng tăng dần (Prefix sum) để trả lại kết quả mong muốn

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

    // Mảng hiệu (Difference array)
    vector<long long> D(n + 1);
    for (int i = 0; i < n; i++){
        if (i == 0)  D[i] = v[i];
        else  D[i] = v[i] - v[i-1];
    }

    int q; cin >> q;
    while(q--){
        int left, right, k;
        cin >> left >> right >> k;

        D[left]    += k; // tăng ở vị trí đầu khoảng cần tăng
        D[right+1] -= k; // giảm về giá trị cũ cho phần sau khoảng cần tăng
    }

    // Mảng cộng dồn (Prefix sum)
    long long resVal = 0;
    for (int i = 0; i < n; i++){
        resVal += D[i];
        cout << resVal << ' ';
    }

    return 0;
}
```
