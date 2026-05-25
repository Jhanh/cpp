# Chia hết cho 17
&emsp;Cho mảng 1 chiều có N phần tử, hãy đếm số lượng cặp số a[i], a[j] với i, j khác nhau mà khi cộng lại sẽ chia hết cho 17. (Lưu ý: không dùng 2 vòng for vì sẽ bị TLE). <br>

**Input Format** <br>
Dòng 1: N (Số lượng phần tử trong mảng) <br>
Dòng 2: N phần tử cách nhau một khoảng trắng <br>

**Output Format** <br>
Số lượng cặp số thỏa mãn đề bài <br>

**Constraints** <br>
1 <= N <= 10^6 <br>
-10^6 <= a[i] <= 10^6 <br>

**Example Input**
> 8 <br>
  12 -5 22 -12 17 0 -34 8 <br>

**Example Output**
> 7 <br>

(12, 22) &ensp; (12, -12) &ensp; (-5, 22) &ensp; (-5, -12) <br>
(17, 0) &ensp; (17, -34) &ensp; (0, -34) <br>

### Note / Hint
- Ta dùng 1 mảng có 17 phần tử để đếm số lượng số dư sau khi chia dư cho 17 <br>

## Code
``` cpp
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> cntMod(17, 0);
    long long res = 0;

    for (int i = 0; i < n; i++){
        int x; cin >> x;

        // cụm trong () để loại bỏ trường hợp số âm
        int mod = (x % 17 + 17) % 17;
        // nửa kia của số dư
        int target = (17 - mod) % 17;

        // ghép cặp (đảm bảo nhiều số chia dư 0 đã được tính tổ hợp)
        res += cntMod[target];

        ++cntMod[mod];
    }
    cout << res;

    return 0;
}
```
