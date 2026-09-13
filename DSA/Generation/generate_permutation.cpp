#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::swap;
using std::reverse;

/*
Sinh hoán vị: Bản chất là ta cho 1 số bất kì có nhiều chữ số, sinh hoán vị xáo trộn các chữ số để tạo thành số lớn hơn số hiện tại nhưng là cấu hình nhỏ nhất.
*/
// Time complexity: O(N * N!)
// Space complexity: O(N)

int n;
vector<int> v;
void init(); // khởi tạo cấu hình đầu tiên
void display(); // in cấu hình
bool genarationPermutation(); // thuật toán sinh hoán vị

int main(){
    cin >> n;
    init();
    do{
        display();
    } while(genarationPermutation());

    return 0;
}

void init(){
    v.assign(n, 0);
    for (int i = 0; i < n; i++){
        v[i] = i + 1;
    }
}

void display(){
    for (int x : v)  cout << x << ' ';
    cout << '\n';
}

bool genarationPermutation(){
    int i = n - 2; // đi từ phần tử kế cuối
    // nếu còn số để xét và phần tử hiện tại lớn hơn phần tử bên phải
    while (i >= 0 && v[i] > v[i+1]){
        --i; // dịch trái
    }

    if (i == -1){  // không còn số để xét, đã đi đến cấu hình cuối
        return false;
    }
    else{
        // duyệt mảng bên phải tìm số lớn hơn số đang xét
        for (int j = n-1; j > i; j--){
            if (v[j] > v[i]){
                swap(v[i], v[j]); // đổi chỗ số lớn hơn với số đang xét
                break; // dừng vì chỉ cần số đầu tiên lớn hơn
            }
        }

        // đảo ngược mảng bên phải số đang xét, tạo thành mảng tăng dần
        reverse(v.begin() + i + 1, v.end());
        return true;
    }
}
