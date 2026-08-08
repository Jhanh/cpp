# Đổi xu
&emsp;Một ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Biết rằng mỗi mệnh giá tiền ở ngân hàng có số lượng không giới hạn. Bạn có một số tiền là N và muốn đổi hết với ngân hàng với số lượng tờ tiền là ít nhất. Hãy tính xem số lượng tờ tiền sau khi đổi ra được là bao nhiêu? <br>

**Input Format** <br>
1 dòng duy nhất là số tiền N muốn đổi <br>

**Output Format** <br>
Số lượng tờ tiền ít nhất sau khi đổi được <br>

**Constraints** <br>
1 <= N <= 10^14 <br>

**Example Input**
> 1318 <br>

**Example Output**
> 7 <br>


### Note / Hint
- Dùng phép chia lấy nguyên (/) để biết số tờ tiền tối đa của mệnh giá đó có thể dùng
- Dùng phép chia lấy dư (%) để tìm số tiền còn lại cần đổi tiếp.

## Code
``` cpp
#include <iostream>
using std::cin;
using std::cout;

int main(){
    long long n;
    cin >> n;
    int money[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    long long res = 0;

    for (int i = 0; i < 10; i++){
        if (n == 0){  // nếu đã đổi hết tiền
            break;
        }

        res += n / money[i]; // xem đổi được bao nhiêu tờ có mệnh giá tại index i
        n %= money[i]; // tính xem còn lại bao nhiêu tiền cần đổi
    }
    cout << res;

    return 0;
}
```
