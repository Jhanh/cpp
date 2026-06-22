# Xâu con liên tiếp ngắn nhất chứa đầy đủ kí tự
&emsp;Cho 1 xâu S gồm các chữ cái in thường. Hãy tìm chiều dài xâu con liên tiếp ngắn nhất chứa đầy đủ kí tự khác trong xâu S và in ra xâu con đó. <br>

**Input Format** <br>
1 dòng duy nhất chứa xâu S <br>

**Output Format** <br>
Dòng 1: Chiều dài xâu con liên tiếp ngắn nhất chứa đầy đủ kí tự khác nhau trong xâu S <br>
Dòng 2: Chỉ số (index) của kí tự đầu tiên của xâu con (bắt đầu từ chỉ số 0), và xâu con

**Constraints** <br>
1 <= s.length() <= 10^6 <br>
Xâu chỉ chứa các chữ cái in thường, không có khoảng trắng <br>

**Example Input**
> xxyyzzxzyx <br>

**Example Output**
> 3 <br>
> 6 - xzy <br>

## Code
``` cpp
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

// Time complexity: O(N)
// Space complexity: O(1)

int main(){
    string text;
    cin >> text;
    vector<int> charFreq(26, 0); // Mảng lưu tần suất các chữ cái

    // Tìm số lượng kí tự khác nhau
    int unique = 0;
    for (char x : text){
        int tmp = x - 'a'; // chuyển kiểu chữ về kiểu số theo bảng mã ASCII
        if (charFreq[tmp] == 0)  ++unique;
        ++charFreq[tmp];
    }

    // Reset mảng tần suất chữ cái về ban đầu (= 0)
    for (int &x : charFreq) x = 0;

    int left = 0, idx = 0;
    int diffChar = 0; // Ghi nhận số lượng kí tự khác nhau trong xâu con
    int minLen = text.length() + 1;
    int idxMin = -1;
    while (idx < text.length()){
        int tmp = text[idx] - 'a';

        if (charFreq[tmp] == 0){ // Nếu chữ cái chưa từng xuất hiện
            ++diffChar;
        }
        ++charFreq[tmp];

        while (diffChar == unique){ // Nếu đã đủ số lượng chữ cái khác nhau thì bắt đầu thu hẹp xâu con
            int currLen = idx - left + 1;
            if (currLen < minLen){ // Nếu độ dài xâu con hiện tại ngắn hơn xâu con đã từng ghi nhận thì cập nhật lại
                minLen = currLen;
                idxMin = left;
            }

            // Ta bắt đầu thu hẹp từ bên trái qua
            int leftASCII = text[left] - 'a';
            --charFreq[leftASCII];
            // Nếu sau khi thu hẹp mà làm mất chữ cái độc nhất thì cho dừng để bổ sung lại nếu có
            if (charFreq[leftASCII] == 0){
                --diffChar;
            }
            ++left;
        }

        ++idx;
    }

    if (idxMin != -1){
        cout << minLen << '\n';
        cout << idxMin << " - " << text.substr(idxMin, minLen);
    }

    return 0;
}
```
