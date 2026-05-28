#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Time complexity: O(N log(N))
// Space complexity: O(N)

void merge (vector<int> &v, int left, int right, int mid){
    int n1 = mid - left + 1; // Kích thước nửa trái
    int n2 = right - mid;    // Kích thước nửa phải

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)  L[i] = v[left + i];
    for (int j = 0; j < n2; j++)  R[j] = v[mid + j + 1];

    int i = 0, j = 0; // i trỏ mảng L, j trỏ mảng R
    int k = left; // k trỏ mảng gốc (mảng v)

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i];
            ++i;
        }
        else{
            v[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1){
        v[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        v[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort (vector<int> &v, int left, int right){
    if (left >= right){ // dừng vì mảng chỉ còn 1 phần tử
        return;
    }

    int mid = left + (right - left) / 2;

    // đệ qui để chia đôi mảng
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);

    // trộn 2 mảng đã chia
    merge(v, right, left, mid);
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    mergeSort(v, 0, n-1);

    for (int x : v)  cout << x << ' ';

    return 0;
}
