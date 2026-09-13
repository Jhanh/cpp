#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

/*
Sinh tổ hợp chập K của N: Dựa trên mảng k phần tử, ta đi từ cuối nếu số chưa đạt đến trần theo công thức n-k+i (nếu index bắt đầu là 0 thì n-k+i+1) thì ta tăng giá trị và cập nhật lại toàn bộ mảng bên phải để luôn tạo thành dãy tăng dần
*/
// Time complexity: O(k * C(n, k))
// Space complexity: O(k)

int n, k;
vector<int> v;
void init(); // khởi tạo cấu hình đầu tiên
void display(); // in cấu hình
bool generatenCk(); // thuật toán sinh tổ hợp chập k của n

int main(){
    cin >> n >> k;
    init();
    do{
        display();
    } while(generatenCk());

    return 0;
}

void init(){
    v.assign(k, 0);
    for (int i = 0; i < k; i++){
        v[i] = i + 1;
    }
}

void display(){
    for (int x : v)  cout << x << ' ';
    cout << '\n';
}

bool generatenCk(){
    int i = k - 1; // đi từ cuối mảng
    // nếu vẫn nằm trong dãy số cần xét và số đang xét đã chạm trần
    while (i >= 0 && v[i] == n-k+i+1){
        --i; // dịch trái
    }

    if (i == -1){  // hết số để xét, chạm đến cấu hình cuối cùng
        return false;
    }
    else{
        ++v[i]; // tăng giá trị phần tử đang xét
        // Cập nhật lại tất cả giá trị bên phải
        for (int j = i+1; j < k; j++){
            v[j] = v[j-1] + 1;
        }
        return true;
    }
}

