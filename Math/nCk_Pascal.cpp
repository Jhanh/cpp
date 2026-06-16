#include <iostream>
using std::cin;
using std::cout;
#define MOD 1000000007

/*
Nếu chỉ dùng công thức nguyên thủy
C(n, k) = n! / (k! * (n-k)!)
thì cứ mỗi truy vấn hoặc số quá lớn sẽ khiến code không thể chạy nổi

Nên ta dùng công thức dựa vào tam giác Pascal (n <= 1000)
C(n, k) = C(n-1, k-1) + C(n-1, k)

Lưu ý chỉ dùng DP khi phải truy vấn nhiều lần, nếu n>1000 thì code không hoạt động được
*/
// Time complexity: O(N*N + q)
// Space complexity: O(N*N)

long long C[1007][1007]; // vùng nhớ Segment

void nCk(){
    for (int n = 0; n <= 1000; n++){
        for (int k = 0; k <= n; k++){
            if (k == 0 || k == n){ // Chọn 0 phần tử luôn có 1 cách
                C[n][k] = 1;
            }
            else{
                C[n][k] = C[n-1][k-1] + C[n-1][k];
                C[n][k] %= MOD;
            }
        }
    }
}

int main(){
    // Đẩy nhanh tốc độ nhập xuất
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    nCk();

    int q; cin >> q;
    while(q--){
        int n, k;  cin >> n >> k;
        cout << C[n][k] << '\n';
    }

    return 0;
}
