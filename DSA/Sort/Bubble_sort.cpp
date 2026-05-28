#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::swap;

// Bubble sort: Duyệt mảng n-1 lần với mỗi lần ta đưa phần tử lớn nhất (nhỏ nhất theo yêu cầu) xuống cuối mảng
// Time complexity: O(N * N)
// Space complexity: O(1)

void bubbleSort (vector<int> &v){
    // Vòng for i: số lần duyệt mảng
    for (int i = 0; i < (int)v.size()-1; i++){
        bool check = true; // nếu mảng đã được sắp xếp thì dừng luôn

        // Vòng for j: số phần tử cần thao tác
        for (int j = 1; j < (int)v.size()-i; j++){
            if (v[j-1] > v[j]){
                swap(v[j-1], v[j]);
                check = false;
            }
        }

        // In thao tác
        cout << "Step " << i+1 << ": ";
        for (int k = 0; k < (int)v.size(); k++){
            cout << v[k] << ' ';
        }
        cout << '\n';

        if (check)  return;
    }
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    bubbleSort(v);

    return 0;
}
