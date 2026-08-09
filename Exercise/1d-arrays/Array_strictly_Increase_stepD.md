# Số thao tác giúp mảng tăng chặt
&emsp;Cho mảng số nguyên A[] có N phần tử, với D đơn vị. Nếu mảng chưa tăng chặt thì hãy xác định số thao tác tối thiểu để mảng tăng chặt, với mỗi thao tác ta tăng 1 phần tử thêm D đơn vị. Mảng tăng chặt là mảng có phần tử đứng sau luôn luôn lớn hơn phần tử đứng trước ví dụ như 1 3 4 7 9 là mảng tăng chặt còn 1 3 3 7 9 không phải mảng tăng chặt. <br>

**Input Format** <br>
Dòng 1: N, D (N: Số lượng phần tử của mảng, D: lượng tăng) <br>
Dòng 2: N phần tử

**Output Format** <br>
Dòng 1: Số thao tác tối thiểu để mảng tăng chặt <br>
Dòng 2: Mảng sau khi thực hiện thao tác

**Constraints** <br>
1 <= N, D <= 10^4 <br>
1 <= A[i] <= 10^6 <br>

**Example Input**
> 4 2 <br>
> 1 3 3 2

**Example Output**
> 3 <br>
> 1 3 5 6 <br>

Tăng phần tử A[2] thêm 2 với 1 lần <br>
Tăng phần tử A[3] thêm 2 với 2 lần <br>

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

/*
Để mảng tăng chặt thì A[i] > A[i-1]. Nếu A[i] <= A[i-1] thì ta phải thực hiện K thao tác cộng D:
    A[i] + (K * D) > A[i-1]
         K*D       > A[i-1] - A[i]
          K        > (A[i-1] - A[i]) / D
          K        = (⌊A[i-1] - A[i]⌋ / D) + 1
*/
// Time complexity: O(N)
// Space complexity: O(1)

int main(){
    int n;
    int d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int res = 0;
    for (int i = 1; i < n; i++){
        if (v[i] <= v[i-1]){
            int diff = v[i-1] - v[i]; // tính độ lệch
            int k = (diff / d) + 1; // số thao tác cần thiết
            res += k;
            v[i] += (d * k);
        }
    }

    cout << res << '\n';
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }

    return 0;
}
```
