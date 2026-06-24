# Số nhỏ nhất, số lớn nhất có n chữ số và tổng bằng s
&emsp;Cho 2 số nguyên không âm N và S. Hãy tìm số nhỏ nhất và số lớn nhất có N chữ số và tổng các chữ số bằng S. (Bắt buộc dùng string vì N có thể lên đến 100) <br>

**Input Format** <br>
N và S cách nhau 1 khoảng trắng

**Output Format** <br>
Dòng 1: Số nhỏ nhất <br>
Dòng 2: Số lớn nhất

**Constraints** <br>
1 <= N <= 100 <br>
1 <= S <= 900 <br>

**Example Input**
> 5 25 <br>

**Example Output**
> 10699 <br>
> 99700

## Code
``` cpp
#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::to_string;
using std::min;

// Time complexity: O(N)
// Space complexity: O(N)

string minVal(int n, int sum);
string maxVal(int n, int sum);

int main(){
    int n, s;
    cin >> n >> s;

    // Nếu cả n số đều là 9 mà vẫn không thể bằng s coi như vô lý
    // Nếu yêu cầu có từ 2 số trở lên mà tổng bằng 0 cũng coi như vô lý (nếu chỉ có 1 số 0 thì hợp lý)
    if (9*n < s || (s == 0 && n > 1)){
        cout << "ERROR!";
    }
    else if (s == 0 && n == 1){ // Trường hợp 1 số 0
        cout << "0\n0";
    }
    else{
        string minStr = minVal(n, s);
        string maxStr = maxVal(n, s);
        cout << minStr << '\n' << maxStr;
    }

    return 0;
}

string minVal(int n, int sum){
    string res(n, '0');
    sum = sum - 1; // Chừa lại 1 đơn vị cho chữ số đầu tiên
    for (int i = n-1; i > 0; i--){ // Duyệt từ cuối về kế số đầu
        int digit = min(9, sum);
        res[i] = digit + '0'; // Chuyển kiểu số nguyên về kiểu char
        sum -= digit;

        if (sum == 0)  break; // Câu lệnh không ảnh hưởng đến kết quả
        // Nhưng vì đã tạo sẵn chuỗi có n số 0 nên trừ hết sum thì dừng luôn để nhanh hơn
    }
    res[0] = (sum + 1) + '0'; // Số đầu tiên sẽ là phần còn lại của sum cộng thêm 1 đơn vị đã chừa lại ở trên
    return res;
}

string maxVal(int n, int sum){
    string res(n, '0');
    for (int i = 0; i < n; i++){ // Duyệt từ đầu về cuối
        int digit = min(9, sum);
        res += (digit + '0');
        sum -= digit;

        if (sum == 0)  break; // Câu lệnh không ảnh hưởng đến kết quả
        // Nhưng vì đã tạo sẵn chuỗi có n số 0 nên trừ hết sum thì dừng luôn để nhanh hơn
    }
    return res;
}
```
