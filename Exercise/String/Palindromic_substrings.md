# Chuỗi con đối xứng
&emsp;Cho 1 xâu S gồm các chữ cái in thường. Hãy đếm số lượng xâu con đối xứng trong xâu S. <br>

**Input Format** <br>
1 dòng duy nhất chứa xâu S <br>

**Output Format** <br>
Số lượng xâu con đối xứng

**Constraints** <br>
1 <= s.length() <= 10^5 <br>
Xâu chỉ chứa các chữ cái in thường, không có khoảng trắng <br>

**Example Input**
> ababaa <br>

**Example Output**
> 11 <br>
> Bao gồm: a, b, a, b, a, a, aba, bab, aba, ababa, aa

## Code
``` cpp
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

// Time complexity: O(N^2)
// Space complexity: O(1)

// Ta quen đặt 2 con trỏ ở 2 rìa rồi thu hẹp để kiểm tra đối xứng
// Nhưng để giải quyết bài này ta cần phải xét từ tâm rồi đi ra 2 bên.
// Có 2 trường hợp lấy tâm là:
// 1. Số lượng phần tử là lẻ như "aba" thì tâm là b.
// 2. Số lượng phần tử là chẵn như "abba" thì tâm gồm cả 2 kí tự b.

long long aroundCenter (const string &text, int left, int right){
    long long cnt = 0;
    // Nếu 2 rìa không vượt qua giới hạn của xâu, và giá trị ở 2 rìa bằng nhau
    while (left >= 0 && right < (int)text.length() && text[left] == text[right]){
        ++cnt;
        --left;
        ++right;
    }
    return cnt;
}

int main(){
    string text;
    cin >> text;

    long long total = 0;
    for (int i = 0; i < (int)text.length(); i++){
        total += aroundCenter(text, i, i);   // Đếm trường hợp số lượng phần tử là lẻ
        total += aroundCenter(text, i, i+1); // Đếm trường hợp số lượng phần tủ là chẵn
    }
    cout << total;

    return 0;
}
```
