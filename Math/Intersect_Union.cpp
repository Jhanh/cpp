#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::max;

/*
Cách 1: Dùng mảng đếm tần suất. Cho 2 mảng đếm tần suất 2 mảng để cho, duyệt từ 0 đến giá trị lớn nhất của 2 mảng nếu xuất hiện ở một trong hai thì cho vào mảng hợp còn xuất hiện ở cả hai thì cho vào mảng giao.
Ưu: Nhanh
Nhược: Không dùng được nếu mảng có số âm hoặc quá lớn
*/
// Time complexity: O(N + M + maxVal)
// Space complexity: O(N + M + maxVal)
void todo1 (const vector<int> &a, const vector<int> &b){
    // Tìm maxVal để xác định kích thước mảng đếm
    int maxVal = 0;
    for (int x : a)  maxVal = max(maxVal, x);
    for (int x : b)  maxVal = max(maxVal, x);

    vector<int> cntA(maxVal + 1, 0);
    vector<int> cntB(maxVal + 1, 0);

    for (int x : a)  cntA[x]++;
    for (int x : b)  cntB[x]++;

    vector<int> giao, hop;
    for (int i = 0; i <= maxVal; i++){
        if (cntA[i] > 0 && cntB[i] > 0){
            giao.push_back(i);
        }
        if (cntA[i] > 0 || cntB[i] > 0){
            hop.push_back(i);
        }
    }

    for (int x : giao)  cout << x << ' ';
    cout << '\n';
    for (int x : hop)  cout << x << ' ';
}

/*
Cách 2: Sắp xếp và dùng 2 con trỏ tương ứng cho 2 mảng. Nếu 2 phần tử bằng nhau thì cho vào mảng giao, ngược lại thì ta cho phần tử nhỏ hơn vào mảng hợp. Lưu ý: trước khi cho vào mảng thì kiểm tra tính trùng lập
*/
// Time complexity: O(N log(N) + M log(M))
// Space complexity: O(N + M)
void todo2 (vector<int> a, vector<int> b){
    // Điều kiện bắt buộc để dùng Two pointer
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0; // i trỏ vào mảng a còn j trỏ vào mảng b
    vector<int> giao, hop;
    while (i < a.size() && j < b.size()){
        if (a[i] < b[j]){
            if (hop.empty() || (hop.back() != a[i])){
                hop.push_back(a[i]);
            }
            ++i;
        }
        else if (a[i] > b[j]){
            if (hop.empty() || (hop.back() != b[j])){
                hop.push_back(b[j]);
            }
            ++j;
        }
        else{ // nếu bằng nhau thì chỉ cần lấy 1 trong 2
            if (hop.empty() || (hop.back() != a[i])){
                hop.push_back(a[i]);
            }
            if (giao.empty() || (giao.back() != a[i])){
                giao.push_back(a[i]);
            }
            ++i;
            ++j;
        }
    }
    while (i < a.size()){
        if (hop.empty() || (hop.back() != a[i])){
            hop.push_back(a[i]);
        }
        ++i;
    }
    while (j < b.size()){
        if (hop.empty() || (hop.back() != b[j])){
            hop.push_back(b[j]);
        }
        ++j;
    }

    for (int x : giao)  cout << x << ' ';
    cout << '\n';
    for (int x : hop) cout << x << ' ';
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // Chọn todo1 hoặc todo2 để giải quyết bài toán

    return 0;
}
