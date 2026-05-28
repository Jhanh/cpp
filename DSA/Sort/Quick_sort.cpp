#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::swap;

// Time complexity: O(N log(N)) tệ nhất lên đến O(N * N)
// Space complexity: O(log(N))

void quickSort (vector<int> &v, int left, int right){
    // dừng vì mảng không còn hoặc chỉ còn 1 phần tử
    if (left >= right){
        return;
    }

    // chọn pivot nằm giữa
    int mid = left + (right - left) / 2;
    int pivot = v[mid];

    // Phân lô (Partition) bằng two pointer
    int i = left, j = right;

    while (i <= j){
        // tìm phần tử lớn hơn hoặc bằng pivot để quăng qua phần bên phải
        while (v[i] < pivot){
            ++i;
        }

        // tìm phần tử nhỏ hơn hoặc bằng pivot để quăng qua phần bên trái
        while (v[j] > pivot){
            --j;
        }

        // nếu tìm được i,j thích hợp và đảm bảo i,j chưa vượt qua nhau
        if (i <= j){
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }

    // dùng đệ qui để chia nhỏ bài toán
    if (left < j){
        quickSort(v, left, j);
    }
    if (i < right){
        quickSort(v, i, right);
    }
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    quickSort(v, 0, n-1);

    return 0;
}
